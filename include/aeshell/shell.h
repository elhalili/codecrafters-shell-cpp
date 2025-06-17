#ifndef AESHELL_SHELL_H_
#define AESHELL_SHELL_H_
#include <string>
#include <vector>
#include "aeshell/command_parser.h"

namespace aeshell {
  
class Shell {
private:
  CommandParser cmd_parser;
public:
  Shell();
  void Run();
  void HandleCommand(const std::string& command);
  void Exit(const std::vector<std::string>& args);
  void Echo(const std::vector<std::string>& args);
};

}

#endif // AESHELL_SHELL_H_
