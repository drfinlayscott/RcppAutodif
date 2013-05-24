/* Example of mixing Rcpp and Autodif headers
 * Using the minimiser
 */

// Rcpp headers
#include <RcppCommon.h>
#include <Rcpp.h>
// Autodif headers
#include <fvar.hpp>


// defined in ad_grad_test.cpp
double test_func(dvar_vector); 

// [[Rcpp::export]]
Rcpp::NumericVector min_test(int nvar)
{
    independent_variables x_indep(1,nvar); 
    //independent_variables x_indep(0,nvar-1); // Solver crashes if declared to start at 0
    double f = 0;
    dvector g(1,nvar);
    //dvector g(0,nvar-1);
    fmm fmc(nvar);      // Create structure to manage minimization
    BEGIN_MINIMIZATION(nvar,f,x_indep,g,fmc) // Macro to set up beginning of min loop
    f=test_func(x_indep);
    END_MINIMIZATION(nvar,g)    // Macro to set up end of minimization loop
    // Dump minimising values into output vector
    // This is painful
    dvar_vector xvar_vec = x_indep;
    dvector xvec = value(xvar_vec);
    Rcpp::NumericVector xout(nvar);
    for (int i = 1; i <= nvar; ++i){
        xout(i-1) = xvec(i);
    //for (int i = 0; i < nvar; ++i){
    //    x(i) = x_out2(i);
    }
  return xout;
}

