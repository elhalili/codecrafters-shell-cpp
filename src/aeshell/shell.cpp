#include "aeshell/shell.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <unistd.h>
#include <sstream>

namespace aeshell {

const StringVect Shell::Builtins = { "echo", "exit", "type" };

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
  StringVect commands = this->cmd_parser.Parse(command);

  // skip
  if (commands.size() == 0) {
    return;
  }
  
  // TODO: skip empty
  auto cmd = commands.front();
  commands.erase(commands.begin());

  if (cmd == "exit") {
    // uses exit from cstdlib
    this->Exit(commands);
  }
  
  if (cmd == "echo") {
    this->Echo(commands);
    return;
  }   

  if (cmd == "type") {
    for (auto &str: commands) {
      this->Type(str);
    }
    return;
  }

  std::cout << command << ": command not found" << std::endl;
}

void Shell::Exit(const StringVect& args) {
  int exit_code = 0;
  if (args.size() > 0) {
    exit_code = std::atoi(args[1].c_str());
  }

  exit(exit_code);
}

void Shell::Echo(const StringVect& args) {
  bool after_start = false;

  for (auto &x: args) {
    if (after_start) {
      std::cout << ' ';
    }
    after_start = true;

    std::cout << x;
  }
  std::cout << std::endl;
}


void Shell::Type(const std::string& cmd) {

  auto it = std::find(Shell::Builtins.begin(), Shell::Builtins.end(), cmd);
  if (it != Shell::Builtins.end()) {
    std::cout << cmd << " is a shell builtin" << std::endl;
    return;
  }

  StringVect paths = this->LoadEnvPaths();
  for (auto& path: paths) {
    std::string file_path = path + cmd;
    if (access(file_path.c_str(), F_OK) == -1) {
      std::cout << cmd << " is " << path << cmd << std::endl;
      return;
    }
  }

  std::cout << cmd << ": not found" << std::endl;
}


StringVect Shell::LoadEnvPaths() {
  StringVect paths;
  std::string path = std::getenv("PATH");
  std::istringstream iss(path);
  
  std::string entry;
  while (std::getline(iss, entry, ':')) {
    if (!entry.ends_with("/")) {
      entry = entry + "/";
    }

    paths.push_back(entry);
  }
  
  std::sort(paths.begin(), paths.end());

  return paths;
}

}
