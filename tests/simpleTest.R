
library(RcppNLoptExample)

expected <- c(0.3333333, 0.2962963)

verbose <- TRUE

## newer nlopt versions require lower tolerance too
val <- testConstrainedProblem("MMA", verbose)
stopifnot(all.equal(val, expected, tolerance=1e-3))

## expected slight difference in parameters hence tolerance set lower
val <- testConstrainedProblem("COBYLA", verbose)
stopifnot(all.equal(val, expected, tolerance=1e-3))
