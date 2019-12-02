#include "commands.hpp"
#include "auth.hpp"
#include "encrypt.hpp"
#include "strm.hpp"
#include <fstream>
#include <iostream>
#include <string>

void commands::help(std::string cmd, int priv) {
  if (priv == 1) {
    if (cmd == "clear") {
      std::cout << "clear - clears the screen\n";
    } else if (cmd == "logout") {
      std::cout << "logout - logs you out.\n";
    } else {
      std::cout << "Help Menu - Unverified User\n";
      std::cout << "Available Commands:\n";
      std::cout << "clear - clears the screen\n";
      std::cout << "help [command] - shows this menu, can be used to show more "
                   "details about a specific command.\n";
      std::cout << "logout - logs you out.\n";
    }
  }
  if (priv == 2) {
    if (cmd == "clear") {
      std::cout << "clear - clears the screen\n";
    } else if (cmd == "sftp") {
      std::cout << "sftp - shows ftp credentials\n";
    } else if (cmd == "logout") {
      std::cout << "logout - logs you out.\n";
    } else {
      std::cout << "Help Menu - Moderator\n";
      std::cout << "Available Commands:\n";
      std::cout << "clear - clears the screen\n";
      std::cout << "help [command] - shows this menu, can be used to show more "
                   "details about a specific command.\n";
      std::cout << "sftp - shows ftp credentials.\n";
      std::cout << "logout - logs you out.\n";
    }
  }
  if (priv == 3) {
    if (cmd == "clear") {
      std::cout << "clear - clears the screen\n";
    } else if (cmd == "sftp") {
      std::cout << "sftp - shows ftp credentials\n";
    } else if (cmd == "promote") {
      std::cout << "promote [user] - promotes an unverified user to a verified "
                   "user.\n";
    } else if (cmd == "delete") {
      std::cout << "delete [user] - deletes a user.\n";
    } else if (cmd == "demote") {
      std::cout
          << "demote [user] - demotes a moderator down to standard user.\n";
    } else if (cmd == "ftp") {
      std::cout << "ftp -on - turns on the ftp server.\n";
      std::cout << "ftp -off - turns off the ftp server.\n";
      std::cout << "ftp -r - restarts the ftp server.\n";
    } else if (cmd == "shutdown") {
      std::cout << "shutdown - shutsdown the sever.\n";
    } else if (cmd == "reboot") {
      std::cout << "reboot - reboots the server.\n";
    } else if (cmd == "logout") {
      std::cout << "logout - logs you out.\n";
    } else if (cmd == "say") {
      std::cout << "say - sends a message to the server use quotes\n";
    } else {
      std::cout << "Help Menu - Admin\n";
      std::cout << "Available Commands:\n";
      std::cout << "clear - clears the screen\n";
      std::cout << "help [command] - shows this menu, can be used to show more "
                   "details about a specific command.\n";
      std::cout << "sftp - shows ftp credentials.\n";
      std::cout << "promote [user] - promotes a user to a moderator\n";
      std::cout
          << "demote [user] - demotes a moderator down to standard user.\n";
      std::cout << "delete [user] - deletes a user.\n";
      std::cout << "ftp [command] - turns on or off the ftp server.\n";
      std::cout << "shutdown - shutsdown the sever.\n";
      std::cout << "reboot - reboots the server.\n";
      std::cout << "logout - logs you out.\n";
      std::cout << "say - sends a message to the server use quotes\n";
    }
  }
}

void commands::sftp(int priv) {
  if (priv >= 2) {
    std::cout << "FTP Server Address: \n";
    std::cout << "FTP port: 41020 \n";
    std::cout << "FTP Username: CY310\n";
    std::cout << "FTP Password: password\n";
  }
}

void commands::promote(std::string user, int priv) {
  encrypt en;
  std::ifstream in;
  std::ofstream out;
  std::vector<std::string> vec;
  strm ln;
  std::string line, outline, file;
  file = "./users/" + user + "/cred.txt";
  if (priv == 3) {
    in.open(file);
    if (in.fail()) {
      std::cout << "No user named " << user << std::endl;
    } else {
      std::getline(in, line);
      if (user != ln.frontcut(line, ln.gfsin(line) - 1)) {
        in.close();
        en.decryptf(file);
        in.open(file);
        std::getline(in, line);
        ln.flags(line, vec);
        if (vec[1] == "user") {
          in.close();
          outline = user + " " + vec[0] + " mod " + vec[2];
          out.open(file);
          out << outline;
          out.close();
          en.encryptf(file);
        } else {
          std::cout << user << " is already a verfied user or admin!\n";
          en.encryptf(file);
          in.close();
        }

      } else {
        std::cout << "Corrupted User, fixing...\n";
        en.encryptf(file);
      }
    }
  }
}

void commands::demote(std::string user, int priv) {
  encrypt en;
  std::ifstream in;
  std::ofstream out;
  std::vector<std::string> vec;
  strm ln;
  std::string line, outline, file;
  file = "./users/" + user + "/cred.txt";
  if (priv == 3) {
    in.open(file);
    if (in.fail()) {
      std::cout << "No user named " << user << std::endl;
    } else {
      std::getline(in, line);
      if (user != ln.frontcut(line, ln.gfsin(line) - 1)) {
        in.close();
        en.decryptf(file);
        in.open(file);
        std::getline(in, line);
        ln.flags(line, vec);
        if (vec[1] == "mod") {
          in.close();
          outline = user + " " + vec[0] + " user " + vec[2];
          out.open(file);
          out << outline;
          out.close();
          en.encryptf(file);
        } else {
          std::cout << user << " is already a unverified user!\n";
          en.encryptf(file);
          in.close();
        }

      } else {
        std::cout << "Corrupted User, fixing...\n";
        en.encryptf(file);
      }
    }
  }
}

void commands::deleteuser(std::string user, int priv) {
  std::string cmd = "rm -r ./users/" + user;
  if (priv == 3) {
    system(cmd.c_str());
  }
}

void commands::say(std::string text, int priv) {
  std::string cmd = "wall " + text;
  if (priv == 3) {
    system(cmd.c_str());
  }
}

void commands::ftp(std::string flag, int priv) {
  if (priv == 3) {
    if (flag == "-on") {
      std::cout << "Starting up ftp server.\n";
      system("sudo service vsftpd start");
    } else if (flag == "-off") {
      std::cout << "Shutting down ftp server.\n";
      system("sudo service vsftpd stop");
    } else if (flag == "-r") {
      std::cout << "Restarting ftp server.\n";
      system("sudo service vsftpd restart");
    } else {
      std::cout << "Command ftp has no modifier " << flag << std::endl;
      std::cout << "Use command help ftp to view available modifiers\n";
    }
  }
}