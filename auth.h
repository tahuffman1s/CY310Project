// Cy310 project
// Cmd Class

#include <iostream>
#include <vector>
#include <string>
#include <queue>

class auth {
private:

public:
bool check(std::string);
void login(std::vector<std::string>, int &priv, std::string &user, std::priority_queue<std::string> &cmdqueue);
void reg(std::vector<std::string>, int &priv);
};
