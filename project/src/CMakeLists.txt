include_directories("include/")
add_library(SomeFunctions some_function.cpp)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} SomeFunctions Utils)

add_subdirectory(utils)
