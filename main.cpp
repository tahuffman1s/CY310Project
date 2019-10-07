#include <iostream>
#include <cstddef>
#include <vector>
#include <signal.h>
#include <cctype>
#include "strm.h"
#include "auth.h"
#include <cryptopp/aes.h>
#include <cryptopp/osrng.h>



void ctrl_cz_block(int signum) {

}

int main() {
        std::string i = "", checker;
        int priv = 0;
        strm input;
        std::vector<std::string> cmdvec, empty;
        auth reg;
        signal(SIGINT, &ctrl_cz_block);
        signal(SIGTSTP, &ctrl_cz_block);
        signal(SIGQUIT, &ctrl_cz_block);
        std::cout << "*********************************\n";
        std::cout << "|  FTP Managment Server         |\n";
        std::cout << "|  By: Travis                   |\n";
        std::cout << "|      Sam                      |\n";
        std::cout << "|      Victoria                 |\n";
        std::cout << "|      Jacob                    |\n";
        std::cout << "|      Chase                    |\n";
        std::cout << "*********************************\n";

        for(;;) {
                if(priv == 0) {
                        cmdvec = empty;
                        std::cout << '\n';
                        std::cout << "Type login [Username] [Password] to login\n";
                        std::cout << "Type register [Username] [Password] to register\n";
                        std::cout << "> ";
                        std::getline(std::cin, i);
                        checker = input.frontcut(i,input.gfsin(i) - 1);
                        std::transform(checker.begin(),checker.end(),checker.begin(), ::tolower);
                        if(checker == "login" ) {
                                input.flags(i,cmdvec);
                                if(cmdvec[0] != "" || cmdvec[1] != "") {
                                        reg.login(cmdvec,priv);
                                }
                                else {
                                        std::cout << "Must enter a username and password.\n";
                                }
                        }
                        else if(checker == "register") {
                                input.flags(i,cmdvec);
                                if(cmdvec[0] != "" || cmdvec[1] != "") {
                                        reg.reg(cmdvec,priv);
                                        reg.login(cmdvec,priv);
                                }
                                else {
                                        std::cout << "Must enter a username and password.\n";
                                }

                        }
                }
                else {
                        input.dinput(i, priv);
                }
        }
}
