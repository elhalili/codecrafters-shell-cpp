#include "aeshell/command_parser.h"
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

namespace aeshell {

CommandParser::CommandParser() {
  // to implement
}

bool isBlank(std::string str) {
  return str.empty() || std::all_of(str.begin(), str.end(), [](unsigned char c) { return std::isspace(c); });
}

std::vector<std::string> CommandParser::Parse(const std::string& command) {
  std::istringstream input(command);
  std::vector<std::string> commands;

  std::string entry;
  while (std::getline(input, entry, ' ')) {
    if (isBlank(entry)) continue;
    commands.push_back(entry);
  }

  return commands;
}

}
