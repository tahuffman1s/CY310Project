// String Manipulation Class

#include <iostream>
#include <vector>
#include <string>
#include <queue>

class strm {
private:

public:
std::string dinput(std::string, int &priv, std::string &user, std::priority_queue<std::string> &cmdqueue);
bool cifs(std::string);
int gfsin(std::string);
std::string frontcut(std::string, int);
std::string backcut(std::string, int);
void flags(std::string, std::vector<std::string>&ret);
void wlog(std::priority_queue<std::string> &cmdqueue);
int spcnt(std::string);
};
