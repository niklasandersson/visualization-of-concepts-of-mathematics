#include <iostream>
#include "some_function.hpp"
#include "utils/sdl_utils.hpp"

int main(int argc, char *argv[])
{
  std::cout << "Hello World" << std::endl;
  std::cout << "What does some_function say? " << some_function(20) << std::endl;
  std::cout <<GetResourcePath("HEJ") << std::endl;
  return 0;
}
