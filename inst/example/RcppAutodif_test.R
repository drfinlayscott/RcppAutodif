library(RcppAutodif)
library(numDeriv)

# Check the Rcpp bit work
rcpp_hello_world()

# Reproduces test_func from C++ code
func1 <- function(x){
    return(sum((x-1)^2))
}

# Test 1. Getting the gradients
# get_value_and_grad() function is declared in the C++ code in src/ad_grad_test.cpp
# It is callable from R through Rcpp
x <- rnorm(10)
out <- get_value_and_grad(x)
# Check the value
out[["value"]]
func1(x)
# And the grads. Compare to numerical derivatives using the numDeriv package
grad(func1,x)
out[["grads"]]

# Test 2. Calling the minimiser
# The min_test() function is declared in the C++ code in src/ad_min_test.cpp
# It is callable from R through Rcpp
out <- min_test(15L)
out
# Have we hit 0?
func1(out) # of course we have


# If called, R crashes
# See notes in src/ad_min_test.cpp
# out <- min_test_fail(15L)



