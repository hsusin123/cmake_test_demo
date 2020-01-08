cmake_minimum_required(VERSION 3.5)
project(sub_mod1)
message("var sub can use in subdir :" ${sub})
message("sub_mod1----" ${CMAKE_CURRENT_BINARY_DIR})
add_library(sub_mod1 SHARED src/source1.cpp)
target_include_directories(sub_mod1 
PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
$<INSTALL_INTERFACE:sub_mod1/include>
)
set_target_properties(sub_mod1 PROPERTIES VERSION 1.0.0 SOVERSION 1) #设置版本号

install(TARGETS sub_mod1 EXPORT sub_mod1_import

RUNTIME 
  DESTINATION bin
  COMPONENT runtime
LIBRARY
  DESTINATION lib/sub_mod1
  COMPONENT runtime
)

#目录后加反斜杠的规则和rsync一样。
install(DIRECTORY include/sub_mod1 DESTINATION include FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")

install(EXPORT sub_mod1_import FILE sub_mod1.cmake DESTINATION cmake/sub_mod1)