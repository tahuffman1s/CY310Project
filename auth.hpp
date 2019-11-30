// Cy310 project
// Cmd Class

#include <iostream>
#include <queue>
#include <string>
#include <vector>

class auth {
private:
public:
  bool check(std::string);
  void login(std::vector<std::string>, int &priv, std::string &user, bool);
  void reg(std::vector<std::string>, int &priv, std::string &user);
};
