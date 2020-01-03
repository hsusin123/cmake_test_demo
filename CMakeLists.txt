cmake_minimum_required(VERSION 3.5)
project(cmake_test_demo)

set(VERSION 1.1)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/version.h.in 
${CMAKE_CURRENT_SOURCE_DIR}/include/version.h @ONLY)

#configure_file(./include/version.h.in  ./include/version.h @ONLY)
#<input> A relative path is treated with respect to the value of CMAKE_CURRENT_SOURCE_DIR.
#<output> A relative path is treated with respect to the value of CMAKE_CURRENT_BINARY_DIR.

add_subdirectory(src/sub_mod1)
add_executable(test_cmake src/main.cpp)

target_link_libraries(test_cmake PRIVATE sub_mod1)
target_include_directories(test_cmake 
PRIVATE
  include
)