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
    dvector g(1,nvar);
    fmm fmc(nvar);      // Create structure to manage minimization
    double f = 0;
    BEGIN_MINIMIZATION(nvar,f,x_indep,g,fmc) // Macro to set up beginning of min loop
    f=test_func(x_indep);
    END_MINIMIZATION(nvar,g)    // Macro to set up end of minimization loop
    // Dump minimising values into output vector
    // This is pretty convoluted
    dvar_vector xvar_vec = x_indep;
    dvector xvec = value(xvar_vec);
    Rcpp::NumericVector xout(nvar);
    for (int i = 1; i <= nvar; ++i){
        xout(i-1) = xvec(i); // NumericVector indexing starts at 0
    }
  return xout;
}

// This function causes R to crash
// The only difference between this and the above function is that the indexing of x_indep and g start at 0, not 1
// This shouldn't affect things (unless there is something in the solver documentation that specifies that it has to start at 1)
// The test_func() function does not imply indexing starting at 1 as it uses the .indexmin and .indexmax methods
// [[Rcpp::export]]
Rcpp::NumericVector min_test_fail(int nvar)
{
    independent_variables x_indep(0,nvar-1); 
    dvector g(0,nvar-1);
    fmm fmc(nvar);      // Create structure to manage minimization
    double f = 0;
    BEGIN_MINIMIZATION(nvar,f,x_indep,g,fmc) // Macro to set up beginning of min loop
    f=test_func(x_indep);
    END_MINIMIZATION(nvar,g)    // Macro to set up end of minimization loop
    // Function crashes before this point - due to indexing at 0?
    // Dump minimising values into output vector
    // This is pretty convoluted
    dvar_vector xvar_vec = x_indep;
    dvector xvec = value(xvar_vec);

    Rcpp::NumericVector xout(nvar);
    for (int i = 0; i < nvar; ++i){
        xout(i) = xvec(i);
    }
  return xout;
}

