#include "Rcpp.h"
#include <nloptrAPI.h>
#include <tl.h>

static int fcount = 0, ccount = 0;

double myfunc(unsigned n, const double *x, double *grad, void *my_func_data) {
    fcount++;
    tl::debug("[myfunc] func eval {}", fcount);
    if (grad) {
        grad[0] = 0.0;
        grad[1] = 0.5 / sqrt(x[1]);
    }
    return sqrt(x[1]);
}

typedef struct {
    double a, b;
} my_constraint_data;

double myconstraint(unsigned n, const double *x, double *grad, void *data) {
    ccount++;
    tl::trace("[myconstraint] constraint eval {}", ccount);
    my_constraint_data *d = (my_constraint_data *) data;
    double a = d->a, b = d->b;
    if (grad) {
        grad[0] = 3 * a * (a*x[0] + b) * (a*x[0] + b);
        grad[1] = -1.0;
    }
    return ((a*x[0] + b) * (a*x[0] + b) * (a*x[0] + b) - x[1]);
}

//' @title NLopt Call Example from Rcpp
//'
//' @description A simple example for for NLopt integration for Rcpp, using an example from the
//' NLopt tutorial.
//'
//' @param method A string defaulting to \sQuote{MMA} (also allowing \sQuote{COBYLA})
//' which selects the algorithm use.
//' @param verbose A boolean toggle defaulting to \sQuote{false}
//'
//' @return A numeric vector with two elements
//'
//' @seealso \url{https://nlopt.readthedocs.io/en/latest/NLopt_Tutorial/}
//'
//' @examples
//' testConstrainedProblem("MMA", TRUE)
// [[Rcpp::export]]
std::vector<double> testConstrainedProblem(std::string method = "MMA",
                                           bool verbose = false) {
    double lb[2] = { -HUGE_VAL, 0 }; 		// lower bounds
    nlopt_opt opt;

    if (method == "MMA") {                      // Method of Moving Asymptotes (local, derivatives)
        opt = nlopt_create(NLOPT_LD_MMA, 2);    // local, derivatives; dim 2
    } else if (method == "COBYLA") {			// Constrained Optimization BY Linear Approximations
        opt = nlopt_create(NLOPT_LN_COBYLA, 2); // local, no derivatives; dim 2
    } else {
        Rcpp::stop("Unsupported or wrong method\n");
    }
    nlopt_set_lower_bounds(opt, lb);
    nlopt_set_min_objective(opt, myfunc, NULL);
    my_constraint_data data[2] = { {2,0}, {-1,1} };

    nlopt_add_inequality_constraint(opt, myconstraint, &data[0], 1e-8);
    nlopt_add_inequality_constraint(opt, myconstraint, &data[1], 1e-8);
    nlopt_set_xtol_rel(opt, 1e-4);
    std::vector<double> x = {1.234, 5.678}; // some initial guess
    double minf; 							// minimum objective value, upon return
    fcount = ccount = 0;            	    // reset counters

    if (nlopt_optimize(opt, &(x[0]), &minf) < 0) {
        if (verbose) Rcpp::Rcout << "nlopt failed!" << std::endl;
        tl::warn("nlopt failed");
    } else {
        tl::info("[testConstrainedProblem] Minimum reached at ({:0.4f}, {:0.4f}) "
                 "after {} function evaluations", x[0], x[1], fcount);
        if (verbose) {
            Rcpp::Rcout << std::setprecision(5)
                        << "Found minimum at f(" << x[0] << "," << x[1] << ") "
                        << "= " << std::setprecision(8) << minf
                        << " after " << fcount << " function"
                        << " and " << ccount << " constraint evaluations."
                        << std::endl;
        }
    }
    nlopt_destroy(opt);
    return x;
}

//' Helper function to access the NLopt version as an integer vector.
//'
//' @title NLopt Version as Vector
//' @return A list with an integer vector with three elements for major, minor
//' and patch release, classed as \code{package_version} and \code{numeric_version}.
//' @examples
//' nloptVersion()
// [[Rcpp::export]]
Rcpp::List nloptVersion() {
    int ma, mi, pa;
    nlopt_version(&ma, &mi, &pa);
    // create a vector of major, minor, patch
    auto ver = Rcpp::IntegerVector{ma, mi, pa};
    // and place it in a list (as e.g. packageVersion() in R returns)
    auto lst = Rcpp::List::create(ver);
    // and class it as 'package_version' accessing print() etc methods
    lst.attr("class") = Rcpp::CharacterVector::create("package_version", "numeric_version");
    return lst;
}
