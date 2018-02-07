#include <string>

#include "catch.hpp"
#include "utils/sdl_utils.hpp"
#include <SDL2/SDL.h>

SCENARIO("GetResourcePath can return the correct path", "[sdl_utils]") {
  GIVEN("correct input") {

    WHEN("a subdirectory is given") {
      std::string input = "test";
      std::string out = GetResourcePath(input);
      THEN("the path should end with the given subdirectory") {
        std::size_t pos = out.rfind("test");
        REQUIRE(out.size() - pos == input.size() + 1);
      }
    }
  }
}
