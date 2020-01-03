cmake_minimum_required(VERSION 3.5)

add_library(sub_mod1 SHARED src/source1.cpp)
target_include_directories(sub_mod1 
PUBLIC
  include
)