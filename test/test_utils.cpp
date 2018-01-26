#include <string>

#include "catch.hpp"
#include "utils/sdl_utils.hpp"

SCENARIO("GetResourcePath can return the correct path", "[sdl_utils]") {
  GIVEN("correct input") {
    WHEN("no argument is given") {
      std::string out = GetResourcePath();
      THEN("the resourcepath is returned") {
        REQUIRE(out == "");
      }
    }
  }

}
