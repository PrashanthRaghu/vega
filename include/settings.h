

#if defined(__BEOS__)
# define VEGA_OS_BEOS
#elif (defined(__APPLE__) && defined(__GNUC__)) || defined(__MACOSX__)
# define VEGA_OS_MACOSX
#elif defined(__NetBSD__)
# define VEGA_OS_NETBSD
#elif defined(__FreeBSD__)
# define VEGA_OS_FREEBSD
#elif defined(__OpenBSD__)
# define VEGA_OS_OPENBSD
#elif defined(__sgi)
# define VEGA_OS_IRIX
#elif defined(__AIX)
# define VEGA_OS_AIX
#elif defined(__LINUX__) || defined(__linux__) || defined(__linux)
# define VEGA_OS_LINUX
#elif defined(__SUN__) || defined(__sun) || defined(sun)
# define VEGA_OS_SOLARIS
#elif defined(__hpux__) || defined(__hpux)
# define VEGA_OS_HPUX
#elif defined(WIN64) || defined(_WIN64) || defined(__WIN64__)
# define VEGA_OS_WINDOWS
# define VEGA_OS_WIN64
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
# define VEGA_OS_WINDOWS
# define VEGA_OS_WIN32
#else
# warning "unknown OS, please report this"
#endif
