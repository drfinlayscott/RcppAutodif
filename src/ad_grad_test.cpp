/* Example of mixing Rcpp and Autodif headers
 * Users passes in a numeric vector x
 * Function calculates sum((x-1)^2)
 * Returns back to R the value and the gradient
 * Adapted from Autodif example
 */

// Rcpp headers
#include <RcppCommon.h>
#include <Rcpp.h>
// Autodif headers
#include <fvar.hpp>

double test_func(dvar_vector); 

// [[Rcpp::export]]
Rcpp::List get_value_and_grad(Rcpp::NumericVector x)
{
    double f = 0.0;
    int nvar=x.size();
    independent_variables x_indep(0,nvar-1);  // Identify the independent variables
    for (int i = 0; i < nvar; ++i){
        x_indep(i) = x(i);
    }
    gradient_structure gs;    // must declare this structure to manage derivative calculations
    f=test_func(x_indep);
    dvector g(0,nvar-1);  // Holds the vector of partial derivatives (the gradient) 
    gradcalc(nvar,g);        // The derivatives are calculated
    // Dump derivatives into a NumericVector for easy passing back to R
    Rcpp::NumericVector grads(nvar);
    for (int i = 0; i < nvar; ++i){
        grads(i) = g(i);
    }
    return Rcpp::List::create(Rcpp::Named("value", f),
        Rcpp::Named("grads", grads));
}

double test_func(dvar_vector x)
{
  dvariable z = 0;
  dvariable tmp = 0;
  for (int i=x.indexmin();i<=x.indexmax();i++)
  {
    tmp=x[i]-1;
    z=z+tmp*tmp;
  }
  return(value(z));
}

