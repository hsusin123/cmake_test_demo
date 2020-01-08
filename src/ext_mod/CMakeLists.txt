cmake_minimum_required(VERSION 3.5)
project(ext_mod)

add_library(ext_mod SHARED src/source_ext.cpp)

target_include_directories(ext_mod 
PUBLIC 
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
$<INSTALL_INTERFACE:include>
)

set_target_properties(ext_mod PROPERTIES VERSION 2.1.10 SOVERSION 2)

#如果没有设置CMAKE_INSTALL_PREFIX，更改默认设置
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "~/data/cmake_test_demo/xx" CACHE PATH "..." FORCE)
endif()

include(CMakePackageConfigHelpers)
configure_package_config_file(
  ${CMAKE_CURRENT_LIST_DIR}/cmake/Ext_modConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/Ext_modConfig.cmake
  INSTALL_DESTINATION
    cmake    #这里实际并没有安装文件，但整个path要与它将要安装的路径保持一致
)


install(TARGETS ext_mod EXPORT ext_mod_import

RUNTIME 
  DESTINATION bin
  COMPONENT runtime
LIBRARY
  DESTINATION lib
  COMPONENT runtime
INCLUDES 
  DESTINATION include
)

#目录后加反斜杠的规则和rsync一样。
install(DIRECTORY include/ext_mod DESTINATION include FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")

install(EXPORT ext_mod_import FILE ext_mod.cmake DESTINATION cmake)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/cmake/Ext_modConfig.cmake DESTINATION cmake)

