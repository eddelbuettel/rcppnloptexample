% tinyrox says don't edit this manually, but it can't stop you!
\name{testConstrainedProblem}
\alias{testConstrainedProblem}
\title{NLopt Call Example from Rcpp}
\usage{
testConstrainedProblem(method = "MMA", verbose = FALSE)
}
\arguments{
\item{method}{A string defaulting to \sQuote{MMA} (also allowing \sQuote{COBYLA})
which selects the algorithm use.}

\item{verbose}{A boolean toggle defaulting to \sQuote{false}}
}
\value{
A numeric vector with two elements
}
\description{
A simple example for for NLopt integration for Rcpp, using an example from the
NLopt tutorial.
}
\details{
This function illustrates use of \pkg{NLopt} from R without requiring linking.
It relies on the set of exported functions the \pkg{nloptr} R package provides directly
(and also instantiates) using a method described in \emph{Writing R Extensions}. There
is also a C++ interface to \pkg{NLopt} but it requires linking making use from another
R package a little more involved as presence and location of the \pkg{NLopt} library
may need to be checked (though using \pkg{pkgconf} can help).
}
\examples{
testConstrainedProblem("MMA", TRUE)
}
\seealso{
\url{https://nlopt.readthedocs.io/en/latest/NLopt_Tutorial/}
}
