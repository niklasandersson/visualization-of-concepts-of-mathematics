#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "some_function.hpp"

SCENARIO("some_function can increase a value by one", "[some_function]"){
  REQUIRE(some_function(10) == 12);
}
