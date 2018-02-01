include_directories("include/")
add_library(SomeFunctions some_function.cpp)

add_subdirectory(utils)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} SomeFunctions Utils SDL2)

