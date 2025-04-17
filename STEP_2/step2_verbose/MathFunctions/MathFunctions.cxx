#include "MathFunctions.h"

// TODO 11: include cmath
#include <cmath>

// TODO 10: Wrap the mysqrt include in a precompiled ifdef based on USE_MYMATH
#ifdef USE_MYMATH
  #include "mysqrt.h"
#endif

namespace mathfunctions {
double sqrt(double x) {

  // TODO 9: If USE_MYMATH is defined, use detail::mysqrt.
  // Otherwise, use std::sqrt.
  // We use #ifdef because USE_MYMATH is a pre-compiler variable
  #ifdef USE_MYMATH
    return detail::mysqrt(x);
  #else
    return std::sqrt(x);
  #endif
}
}

// At this point, if USE_MYMATH is OFF, mysqrt.cxx would not be used but
// it will still be compiled because the MathFunctions target has mysqrt.cxx
// listed under sources.

// There are a few ways to fix this. The first option is to use target_sources() to add mysqrt.cxx
// from within the USE_MYMATH block. Another option is to create an additional library within the
// USE_MYMATH block which is responsible for compiling mysqrt.cxx