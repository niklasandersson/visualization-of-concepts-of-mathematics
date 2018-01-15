add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

set(TEST_SOURCES
    main.cpp
   )

add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests Catch)
