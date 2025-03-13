// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// testConstrainedProblem
std::vector<double> testConstrainedProblem(std::string method, bool verbose);
RcppExport SEXP _RcppNLoptExample_testConstrainedProblem(SEXP methodSEXP, SEXP verboseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type method(methodSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    rcpp_result_gen = Rcpp::wrap(testConstrainedProblem(method, verbose));
    return rcpp_result_gen;
END_RCPP
}
// nloptVersion
Rcpp::IntegerVector nloptVersion();
RcppExport SEXP _RcppNLoptExample_nloptVersion() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(nloptVersion());
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_RcppNLoptExample_testConstrainedProblem", (DL_FUNC) &_RcppNLoptExample_testConstrainedProblem, 2},
    {"_RcppNLoptExample_nloptVersion", (DL_FUNC) &_RcppNLoptExample_nloptVersion, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_RcppNLoptExample(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
