PHP_ARG_ENABLE(poppler, whether to enable poppler support,
[ --enable-poppler Enable poppler support])

if test "$PHP_POPPLER" = "yes"; then
  AC_DEFINE(HAVE_POPPLER, 1, [Whether you have poppler])
  PHP_NEW_EXTENSION(poppler, poppler.c, $ext_shared)
fi
