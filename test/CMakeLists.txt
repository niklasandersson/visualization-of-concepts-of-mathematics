add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

set(TEST_SOURCES
    main.cpp
    test_utils.cpp
   )

find_package(SDL2 REQUIRED)
include_directories("../project/src/include/"
                    ${SDL2_INCLUDE_DIR})

add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests Catch SomeFunctions Utils SDL2)
