#include "mysqrt.h"

#include <cmath>
#include <iostream>

namespace mathfunctions {
namespace detail {

// a hack square root calculation using simple operations
double mysqrt(double x) {

  if (x <= 0) {
    return 0;
  }

  #if defined(HAVE_LOG) && defined(HAVE_EXP)
    double result = std::exp(std::log(x) * 0.5);
    std::cout << "Computing sqrt of " << x << " to be " << result << " using log and exp" << std::endl;
  #else
    double result = x;

  // do ten iterations
  for (int i = 0; i < 10; ++i) {

    if (result <= 0) {
      result = 0.1;
    }

    double delta = x - (result * result);
    result = result + 0.5 * delta / result;
    std::cout << "Computing sqrt of " << x << " to be " << result << std::endl;
  }
  #endif

  return result;
}
}
}
