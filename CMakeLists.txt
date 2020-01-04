cmake_minimum_required(VERSION 3.5)
project(cmake_test_demo)

set(VERSION 1.1)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/version.h.in 
${CMAKE_CURRENT_SOURCE_DIR}/include/version.h @ONLY)

#configure_file(./include/version.h.in  ./include/version.h @ONLY)
#<input> A relative path is treated with respect to the value of CMAKE_CURRENT_SOURCE_DIR.
#<output> A relative path is treated with respect to the value of CMAKE_CURRENT_BINARY_DIR.



#如果没有设置CMAKE_INSTALL_PREFIX，更改默认设置
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "/home/xuxin/data/cmake_test_demo/xx" CACHE PATH "..." FORCE)
endif()


#下面RPATH选项，必须子啊构建target之前设置

#如果启用此选项，那么除了构建树中的目录之外的所有其他目录都将自动添加到安装RPATH中.
#例如，整个模块又引入了其他的第三方库，也会自动加入到install_path中
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

#多个路径时，用分号隔开
#SET(CMAKE_INSTALL_RPATH "$ORIGIN/../lib;${CMAKE_INSTALL_PREFIX}/cmake_test_bin/bin") 

# 将程序运行的当前路径写入RPATH
SET(CMAKE_INSTALL_RPATH "$ORIGIN/../lib/sub_mod1")

set(sub "test var scope") #这个变量可以在sub_mod1中使用
add_subdirectory(src/sub_mod1)
add_executable(test_cmake src/main.cpp)

target_link_libraries(test_cmake PRIVATE sub_mod1)
target_include_directories(test_cmake 
PUBLIC
#include
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>  #不能使用相对路径
$<INSTALL_INTERFACE:include>   #可以使用相对路径，相对于CMAKE_INSTALL_PREFIX
)
#set_target_properties(test_cmake PROPERTIES PUBLIC_HEADER "include/version.h")
install(TARGETS test_cmake EXPORT test_import

RUNTIME 
  DESTINATION bin
  COMPONENT runtime
LIBRARY
  DESTINATION lib
  COMPONENT runtime
#PUBLIC_HEADER
#  DESTINATION include1
  #COMPONENT dev
  #INCLUDES 
  #DESTINATION include
  #COMPONENT dev
)

install(EXPORT test_import FILE test.cmake DESTINATION cmake)