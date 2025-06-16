#include "aeshell/command_parser.h"
#include <vector>
#include <string>
#include <sstream>

namespace aeshell {

CommandParser::CommandParser() {
  // to implement
}

std::vector<std::string> CommandParser::Parse(const std::string& command) {
  std::istringstream input(command);
  std::vector<std::string> commands;

  std::string entry;
  while (std::getline(input, entry, ' ')) {
    commands.push_back(entry);
  }

  return commands;
}

}
