PHP_ARG_ENABLE(
    poppler,
    whether to enable poppler support,
    [ --enable-poppler Enable poppler support]
)

if test "$PHP_POPPLER" != "no"
then
    AC_DEFINE(HAVE_POPPLER, 1, [Whether you have poppler])

    dnl check if libpoppler is installed
    AC_MSG_CHECKING([for poppler library])
    POPPLER_INCLUDES=`pkg-config --cflags-only-I poppler-glib`
    if test -z "$POPPLER_INCLUDES"
    then
        AC_MSG_RESULT([not found])
        AC_MSG_ERROR([Please install libpoppler-glib-dev])
    fi
    AC_MSG_RESULT([found])
    for inc in $POPPLER_INCLUDES
    do
        incpath=`echo $inc | sed 's/^-I//'`
        PHP_ADD_INCLUDE($incpath)
    done

    dnl add libpoppler
    PHP_SUBST(POPPLER_SHARED_LIBADD)
    PHP_ADD_LIBRARY(poppler-glib, 1, POPPLER_SHARED_LIBADD)
    PHP_ADD_LIBRARY(gobject-2.0, 1, POPPLER_SHARED_LIBADD)
    PHP_ADD_LIBRARY(cairo, 1, POPPLER_SHARED_LIBADD)
    PHP_ADD_LIBRARY(glib-2.0, 1, POPPLER_SHARED_LIBADD)

    PHP_NEW_EXTENSION(poppler, poppler.c, $ext_shared)
fi
