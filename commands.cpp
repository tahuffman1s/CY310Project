#include "commands.hpp"
#include "auth.hpp"
#include "encrypt.hpp"
#include "strm.hpp"
#include <iostream>
#include <string>

void commands::help(std::string cmd, int priv) {
  if (priv == 1) {
    if (cmd == "clear") {
      std::cout << "clear - clears the screen\n";
    } else if (cmd == "rp") {
      std::cout << "rp - request promotion to moderator\n";
    } else {
      std::cout << "Help Menu - Standard User\n";
      std::cout << "Available Commands:\n";
      std::cout << "clear - clears the screen\n";
      std::cout << "help [command] - shows this menu, can be used to show more "
                   "details about a specific command.\n";
      std::cout << "rp - request promotion to moderator.\n";
      std::cout << "logout - logs you out."
    }
  }
  if (priv == 2) {
    if (cmd == "clear") {
      std::cout << "clear - clears the screen\n";
    } else if (cmd == "sftp") {
      std::cout << "sftp - shows ftp credentials\n";
    } else {
      std::cout << "Help Menu - Standard User\n";
      std::cout << "Available Commands:\n";
      std::cout << "clear - clears the screen\n";
      std::cout << "help [command] - shows this menu, can be used to show more "
                   "details about a specific command.\n";
      std::cout << "sftp - shows ftp credentials.\n";
    }
  }
  if (priv == 3) {
    if (cmd == "clear") {
      std::cout << "clear - clears the screen\n";
    } else if (cmd == "sftp") {
      std::cout << "sftp - shows ftp credentials\n;"
    } else if (cmd == "promote") {
      std::cout << "promote [user] - promotes a user to a moderator.\n";
    } else if (cmd == "delete") {
      std::cout << "delete [user] - deletes a user.\n";
    } else if (cmd == "chr") {
      std::cout << "chr - checks requests for moderator promotions.\n";
    } else if (cmd == "demote") {
      std::cout
          << "demote [user] - demotes a moderator down to standard user.\n";
    } else if (cmd == "ftp") {
      std::cout << "ftp -on - turns on the ftp server.\n";
      std::cout << "ftp -off - turns off the ftp server.\n";
    } else if (cmd == "shutdown") {
      std::cout << "shutdown - shutsdown the sever.\n";
    } else if (cmd == "reboot") {
      std::cout << "reboot - reboots the server.\n";
    } else {
      std::cout << "Help Menu - Standard User\n";
      std::cout << "Available Commands:\n";
      std::cout << "clear - clears the screen\n";
      std::cout << "help [command] - shows this menu, can be used to show more "
                   "details about a specific command.\n";
      std::cout << "rp - request promotion to moderator\n";
      std::cout << "sftp - shows ftp credentials.\n";
      std::cout << "promote [user] - promotes a user to a moderator\n";
      std::cout
          << "demote [user] - demotes a moderator down to standard user.\n";
      std::cout << "delete [user] - deletes a user.\n";
      std::cout << "chr - checks requests for moderator promotions.\n";
      std::cout << "ftp [command] - turns on or off the ftp server.\n";
      std::cout << "shutdown - shutsdown the sever.\n";
      std::cout << "reboot - reboots the server.\n";
    }
  }
}

void commands::ft