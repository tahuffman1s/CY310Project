#include <iostream>
#include <string>

class commands {
private:
public:
  void help(std::string, int);
  void ftp(char, int);
  void sftp(int);
  void promote(std::string, int);
  void demote(std::string, int);
  void rp(int);
  void chr(int);
};
