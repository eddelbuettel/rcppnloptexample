##' @title Minimal wrapper function
##'
##' @description Minimal wrapper for C++ function to illustrate
##' logging from R
##'
##' @param method A string defaulting to \sQuote{MMA} (also allowing \sQuote{COBYLA})
##' which selects the algorithm use.
##'
##' @return Nothing is returned as the function is invoked for
##' its side effects.
##'
##' @author Dirk Eddelbuettel
wrapper <- function(method = "MMA") {
    tl::debug("[wrapper] calling C++ function")
    testConstrainedProblem()
    tl::debug("[wrapper] returned from C++ function")
    invisible()
}
