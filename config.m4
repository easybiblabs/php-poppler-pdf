PHP_ARG_ENABLE(
    poppler,
    whether to enable poppler support,
    [ --enable-poppler Enable poppler support]
)

if test "$PHP_POPPLER" != "no"
then
    AC_DEFINE(HAVE_POPPLER, 1, [Whether you have poppler])

    dnl XXX
    dnl check if libpoppler is installed
    AC_MSG_CHECKING([for poppler library])
    POPPLER_INCLUDES=`pkg-config --cflags-only-I poppler-cpp poppler-glib`
    if test -z "$POPPLER_INCLUDES"
    then
        AC_MSG_RESULT([not found])
        dnl XXX
        AC_MSG_ERROR([Please install libpoppler-glib-dev])
    fi
    AC_MSG_RESULT([found])
    for inc in $POPPLER_INCLUDES
    do
        incpath=`echo $inc | sed 's/^-I//'`
        PHP_ADD_INCLUDE($incpath)
    done

    dnl add libpoppler-cpp
    PHP_REQUIRE_CXX()
    PHP_SUBST(POPPLER_SHARED_LIBADD)
    PHP_ADD_LIBRARY(poppler-cpp, 1, POPPLER_SHARED_LIBADD)
    PHP_ADD_LIBRARY(stdc++, 1, POPPLER_SHARED_LIBADD)

    PHP_NEW_EXTENSION(poppler, poppler.cc, $ext_shared)
fi
