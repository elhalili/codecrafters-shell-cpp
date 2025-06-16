#include "aeshell/shell.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

namespace aeshell {

Shell::Shell(): cmd_parser() {
  // to implement
}

void Shell::Run() {

  while (true) {
    // Flush after every std::cout / std:cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    std::cout << "$ ";

    std::string input;
    std::getline(std::cin, input);

    HandleCommand(input);
  }
}


void Shell::HandleCommand(const std::string& command) { 
  std::vector<std::string> commands = this->cmd_parser.Parse(command);
  if (commands[0] == "exit") {
    int exit_code = 0;
    if (commands.size() > 1) {
      exit_code = std::atoi(commands[1].c_str());
    }
    exit(exit_code);
  }
  std::cout << command << ": command not found" << std::endl;
}

}
