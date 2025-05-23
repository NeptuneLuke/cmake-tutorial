// A simple program that computes the square root of a number

#include <cmath>
// #include <cstdlib> // TODO 5: Remove this line
#include <iostream>
#include <string>

// TODO 11: Include TutorialConfig.h (configured header file)
#include "TutorialConfig.h"

int main(int argc, char* argv[]) {

  if (argc < 2) {

	  // TODO 12: Create a print statement using Tutorial_VERSION_MAJOR
    //          and Tutorial_VERSION_MINOR

	  std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << std::endl;

    std::cout << "Usage: " << argv[0] << " number" << std::endl;

    return 1;
  }

  // TODO 4: Replace atof(argv[1]) with std::stod(argv[1])
  //double const inputValue = atof(argv[1]);
  double const inputValue = std::stod(argv[1]);

  double const outputValue = sqrt(inputValue);
  std::cout << "The square root of " << inputValue << " is " << outputValue << std::endl;

  return 0;
}
