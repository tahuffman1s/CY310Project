#include <iostream>
#include <string>
#include "commands.h"
#include "strm.h"
#include "auth.h"
#include "encrypt.h"

void commands::help(std::string cmd, int priv){
        if(priv == 1) {
                std::cout << "Help Menu\n";
        }
        if(priv == 2) {
                std::cout << "Help Menu 2\n";
        }
        if(priv == 3) {
                std::cout << "Help Menu 3\n";
        }
}
