#include "ext_mod/header_ext.hpp"
#include "sub_mod1/import1.h"
#include "version.h"
#include <iostream>
int main() {
  std::cout << "hello world" << std::endl;
  sub_mod1_pf();
  ext_pf();
  std::cout << "version is " << VERSION << std::endl;
}