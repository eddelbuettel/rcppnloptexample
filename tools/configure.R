
cppver <- tl:::cppstandard()
if (cppver < 202002) {
    cxxstd <- "CXX_STD = CXX17"
} else {
    cxxstd <- "CXX_STD = CXX20"
}
win <- if (Sys.info()[["sysname"]] == "Windows") ".win" else ""
infile <- file.path("src", paste0("Makevars", win, ".in"))
outfile <- file.path("src", paste0("Makevars", win))
lines <- readLines(infile)
lines <- gsub("@CXXSTD@", cxxstd, lines)
writeLines(lines, outfile)
