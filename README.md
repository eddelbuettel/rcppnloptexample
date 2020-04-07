## RcppNLoptExample: Rcpp example of using [NLopt](https://nlopt.readthedocs.io/en/latest/) via [nloptr](https://github.com/jyypma/nloptr)

[![Build Status](https://travis-ci.org/eddelbuettel/rcppnloptexample.svg)](https://travis-ci.org/eddelbuettel/rcppnloptexample)
[![License](http://img.shields.io/badge/license-GPL%20%28%3E=%202%29-brightgreen.svg?style=flat)](https://www.gnu.org/licenses/gpl-2.0.html)
[![CRAN](http://www.r-pkg.org/badges/version/RcppNLoptExample)](https://cran.r-project.org/package=RcppNLoptExample)
[![Downloads](http://cranlogs.r-pkg.org/badges/RcppNLoptExample?color=brightgreen)](http://www.r-pkg.org/pkg/RcppNLoptExample)
[![Last Commit](https://img.shields.io/github/last-commit/eddelbuettel/rcppnloptexample)](https://github.com/eddelbuettel/rcppnloptexample)

### About

Starting with its 1.2.0 release, the [nloptr](https://github.com/jyypma/nloptr) package by [Jelmer
Ypma](https://github.com/jyypma) now exports its C symbols in a way that makes it accessible to
other R packages _without linking_ easing the installation across operating systems.

This package illustrates this with an example drawn from the [NLopt
tutorial](https://nlopt.readthedocs.io/en/latest/NLopt_Tutorial/).

### Example

See the (currently single) file
[src/nlopt.cpp](https://github.com/eddelbuettel/rcppnloptexample/blob/master/src/nlopt.cpp).

### How / Why ?

R uses C interfaces. These C interfaces can be exported _between packages_.  So when the
usual `library(nloptr)` happens, we now _also_ get a number of C functions registered.

And those are enough to run optimization from C++ as we simply _rely on the C interface
provided_. Look careful at the example code: the objective function and the constraint
functions are C functions, and the body of our example invokes C functions from
[NLopt](https://nlopt.readthedocs.io/en/latest/). _This just works_.

On the other hand, if we tried to use the [NLopt](https://nlopt.readthedocs.io/en/latest/)
C++ interface _which brings with it someinterface code_ we would require linking to that
code (which R cannot easily export across packages using its C interface). So C it is.

### See Also

This repo builds on, extends, and simplifies an earlier [repo by Julien
Chiquet](https://github.com/jchiquet/RcppArmadilloNLoptExample) to which I contributed a core part
of this setup.

### Author

Dirk Eddelbuettel

### License

GPL (>= 2)
