// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>
#include "../inst/include/RcppAutodif.h"

using namespace Rcpp;

// get_value_and_grad
Rcpp::List get_value_and_grad(Rcpp::NumericVector x);
RcppExport SEXP RcppAutodif_get_value_and_grad(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::NumericVector x = Rcpp::as<Rcpp::NumericVector >(xSEXP);
    Rcpp::List __result = get_value_and_grad(x);
    return Rcpp::wrap(__result);
END_RCPP
}
// min_test
Rcpp::NumericVector min_test(int nvar);
RcppExport SEXP RcppAutodif_min_test(SEXP nvarSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    int nvar = Rcpp::as<int >(nvarSEXP);
    Rcpp::NumericVector __result = min_test(nvar);
    return Rcpp::wrap(__result);
END_RCPP
}
// min_test_fail
Rcpp::NumericVector min_test_fail(int nvar);
RcppExport SEXP RcppAutodif_min_test_fail(SEXP nvarSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    int nvar = Rcpp::as<int >(nvarSEXP);
    Rcpp::NumericVector __result = min_test_fail(nvar);
    return Rcpp::wrap(__result);
END_RCPP
}
// rcpp_hello_world
List rcpp_hello_world();
RcppExport SEXP RcppAutodif_rcpp_hello_world() {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    List __result = rcpp_hello_world();
    return Rcpp::wrap(__result);
END_RCPP
}
