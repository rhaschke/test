#include <stdio.h>

#if defined(_MSC_VER) || defined(__CYGWIN__)
# define TESTPKG_EXPORT __declspec(dllexport)
#else
# define TESTPKG_EXPORT __attribute__ ((visibility("default")))
#endif

TESTPKG_EXPORT void hello_world(void) {
  printf("Hello, World!\n");
}
