#include <iostream>
#include <string>

class commands {
private:
public:
  void help(std::string, int);
  void ftp(std::string, int);
  void sftp(int);
  void promote(std::string, int);
  void demote(std::string, int);
  void deleteuser(std::string, int);
  void say(std::string, int);
};
