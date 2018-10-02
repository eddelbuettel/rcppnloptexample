
library(RcppNLoptExample)

expected <- c(0.3333333, 0.2962963)

val <- testConstrainedProblem("MMA")
stopifnot(all.equal(val, expected, tolerance=1e-5))

## expected slight difference in parameters hence tolerance set lower
val <- testConstrainedProblem("COBYLA")
stopifnot(all.equal(val, expected, tolerance=1e-3))
