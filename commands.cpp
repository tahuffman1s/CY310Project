#include <iostream>
#include <string>
#include "commands.h"
#include "strm.h"
#include "auth.h"
#include "encrypt.h"

void cmd(std::string command, int priv){
        std::vector<std::string> cmdvec;

        if(command == "help") {
                help(priv);
        }
        if(command == "log") {

        }
}

void help(int priv){
        if(priv == 1) {
                std::cout << "Help Menu\n";
        }
        if(priv == 2) {
                std::cout << "Help Menu2\n";
        }
        if(priv == 3) {
                std::cout << "Help Menu 3\n";
        }
}
