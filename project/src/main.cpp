#include <iostream>
#include "some_function.hpp"

int main(int argc, char *argv[])
{
  std::cout << "Hello World" << std::endl;
  std::cout << "What does some_function say? " << some_function(20) << std::endl;
  return 0;
}
