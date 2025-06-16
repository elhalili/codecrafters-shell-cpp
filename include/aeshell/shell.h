#ifndef AESHELL_SHELL_H_
#define AESHELL_SHELL_H_
#include <string>
#include "aeshell/command_parser.h"

namespace aeshell {
  
class Shell {
private:
  CommandParser cmd_parser;
public:
  Shell();
  void Run();
  void HandleCommand(const std::string& command);
};

}

#endif // AESHELL_SHELL_H_
