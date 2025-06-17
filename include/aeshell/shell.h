#ifndef AESHELL_SHELL_H_
#define AESHELL_SHELL_H_
#include <string>
#include <vector>
#include "aeshell/command_parser.h"

namespace aeshell {

using StringVect = std::vector<std::string>;

class Shell {
private:
  static const StringVect Builtins;
  CommandParser cmd_parser;
public:
  Shell();
  void Run();
  void HandleCommand(const std::string& command);
  void Exit(const StringVect& args);
  void Echo(const StringVect& args);
  void Type(const std::string& args);
  void Exec(const std::string& cmd, const StringVect& args);
  StringVect LoadEnvPaths();
};

}

#endif // AESHELL_SHELL_H_
