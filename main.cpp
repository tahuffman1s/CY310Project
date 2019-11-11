#include <iostream>
#include <cstddef>
#include <vector>
#include <signal.h>
#include <cctype>
#include "strm.h"
#include "auth.h"
#include <queue>
#include <cryptopp/aes.h>
#include <cryptopp/osrng.h>
#include "encrypt.h"
#include <ctime>
#include "commands.h"



void ctrl_cz_block(int signum) {

}

int main() {
        std::string i = "", checker, user = "";
        std::string out, stime;
        int priv = 0;
        bool first = true, email = false;
        std::string fix;
        int fixlen;
        std::string em = "travis";
        strm input;
        std::vector<std::string> cmdvec, empty;
        commands command;
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
                        std::cout << "Type login [Username] to login\n";
                        std::cout << "Type register [Username] [Email] to register\n";
                        std::cout << "> ";
                        std::getline(std::cin, i);
                        fixlen = i.length() - 1;
                        if(i[fixlen] == ' ') {
                                fix = i;
                                i = "";
                                for(int lo = 0; lo < fix.length() - 1; lo++) {
                                        i = i + fix[lo];
                                }
                        }
                        checker = input.frontcut(i,input.gfsin(i) - 1);
                        std::transform(checker.begin(),checker.end(),checker.begin(), ::tolower);

                        if(checker == "login" ) {
                                input.flags(i,cmdvec);
                                if(cmdvec[0] != "") {
                                        user = cmdvec[0];
                                        reg.login(cmdvec,priv, user, false);
                                }
                                else {
                                        std::cout << "Must enter a username!\n";
                                }
                        }
                        else if(checker == "register") {
                                input.flags(i,cmdvec);
                                if(cmdvec.size() != 2) {
                                        std::cout << "Please provide an email!\n";
                                }
                                else if(cmdvec[0] != "" || cmdvec[0] != " " || cmdvec[1] != " " || cmdvec[1] != "") {
                                        em = cmdvec[1];

                                        for(int i = 0; i < em.length(); i++) {
                                                if(em[i] == '@') {
                                                        email = true;
                                                }
                                        }
                                        if (email == true) {
                                                user = cmdvec[0];
                                                reg.reg(cmdvec, priv, user);
                                                reg.login(cmdvec, priv, user, true);
                                        }
                                        else{
                                                std::cout << "Not a valid email!\n";
                                        }

                                }
                                else {
                                        std::cout << "Must enter a username, and email.\n";
                                }

                        }

                }
                else {
                        if(first == true) {
                                std::cout << "Use help for a list of commands!" << std::endl;
                        }
                        first = false;
                        std::cout << "> ";
                        std::getline(std::cin, i);
                        input.wlog(i, user);
                        std::transform(i.begin(),i.end(),i.begin(), ::tolower);
                        input.flags(i,cmdvec);
                        if(input.cifs(i) ==  true) {
                                i = input.frontcut(i,input.gfsin(i) - 1);
                        }
                        if(i == "help") {
                                command.help(cmdvec[0], priv);
                        }
                        if(i == "clear") {
                                system("clear");
                        }
                }
        }
}
