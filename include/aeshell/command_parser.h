#ifndef AESHELL_COMMAND_PARSER_H_
#define AESHELL_COMMAND_PARSER_H_

#include <vector>
#include <string>

namespace aeshell {

class CommandParser {
public:
  CommandParser();
  std::vector<std::string> Parse(const std::string& command);
};

}


#endif // AESHELL_COMMAND_PARSER_H_
