#include "commands.hpp"
#include "auth.hpp"
#include "encrypt.hpp"
#include "strm.hpp"
#include <iostream>
#include <string>

void commands::help(std::string cmd, int priv) {
  if (priv == 1) {
    if (cmd == "" || cmd == " ") {
      std::cout << "Help Menu - Standard User\n";
      std::cout << "Available Commands:\n";
      std::cout << "clear - clears the screen\n";
    }
  }
  if (priv == 2) {
    std::cout << "Help Menu 2\n";
  }
  if (priv == 3) {
    std::cout << "Help Menu 3\n";
  }
}
