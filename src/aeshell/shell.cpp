#include "aeshell/shell.h"
#include <iostream>

namespace aeshell {

Shell::Shell() {
  // to implement
}

void Shell::Run() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while (true) {
    std::cout << "$ ";

    std::string input;
    std::getline(std::cin, input);
    std::cout << input << ": command not found" << std::endl;
  }
}

}
