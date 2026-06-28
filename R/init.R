
.onLoad <- function(libname, pkgname) {
    if (packageVersion("tl") > "0.0.1") {
        tl::init() # set log level from envirornment variable, if given, or default
    } else {
        ## retrieve optional logging level, default to 'info'
        lvl <- Sys.getenv("TL_LEVEL", "info")
        ## set level (or default of 'info')
        tl::set_level(lvl)
        ## state level set (if level is at least 'debug')
        tl::debug("[.onLoad] Set tl level to {}", lvl)
    }
}
