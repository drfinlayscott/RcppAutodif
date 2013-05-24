RcppAutodif
===========

R package that combines R, Rcpp and Autodif

At the moment the package only contains the precompiled Autodif libraries for Linux 64-bit. The plan is to include the Autodif source code, so that compiling the package builds the libraries.

It should be noted that for the compilation to work, the libraries had to be compiled with the -fPIC flags.
i.e. when running config on ADMB use this option:

./configure CFLAGS=-fPIC CXXFLAGS=-fPIC


The package has two very simple examples in the src/ folder:
ad\_grad\_test.cpp
ad\_min\_test.cpp

These contain the functions get\_value\_and\_grad(Rcpp::NumericVector) and min\_test(int) that are callable from R. These functions are simple demonstrations of how the Autodif classes and routines can be used.

The source code is not very clean at the moment (e.g. to return the values in Autodif classes to R there is a lot of messing about with converting into Rcpp-friendly classes). This can be improved using customised as and wrap functions.

For example:

Making the package
<pre><code>
library(devtools)
library(Rcpp)
load_all("RcppAutodif")
</code></pre>

Check the Rcpp bit work

<pre><code>
rcpp_hello_world()
</code></pre>

The function we are playing with (replicated in the C++ code)

<pre><code>
func1 <- function(x){
    return(sum((x-1)^2))
}
</code></pre>

Test the gradients
<pre><code>
x <- rnorm(10)
out <- get_value_and_grad(x)
out[["value"]]
func1(x)
library(numDeriv)
grad(func1,x)
out[["grads"]]
</code></pre>

Test the minimiser

<pre><code>
out <- min_test(15L)
func1(out)
</code></pre>


