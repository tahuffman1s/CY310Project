#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include "auth.h"
#include "strm.h"
#include "encrypt.h"

// This Function returns whether or not a username exists
bool auth::check(std::string in) {
        std::ifstream fin;
        std::string line;
        std::vector<std::string> test, empty;
        strm t;
        fin.open("cden.txt");
        bool ret, question;
        if(fin.fail()) {
                std::cout << "No cden.txt\n";
                return false;
        }
        else {
                while(std::getline(fin, line)) {
                        test = empty;
                        line = "log " + line;
                        t.flags(line, test);
                        if(test[0] == in) {
                                return true;
                        }
                }
                return false;
        }
}

// This command logins a user in. It relies on an integer to hold priveldge, so that there are multiple levels of authentication.

void auth::login(std::vector<std::string> vec, int &priv, std::string &user) {
        std::ifstream fin;
        std::string line;
        std::vector<std::string> temp, empty;
        strm in;
        auth test;
        std::fstream create;
        encrypt en;
        en.decryptf("./users/"+ user + "/cred.txt");
        fin.open("./users/"+ user + "/cred.txt");
        if(fin.fail()) {
                std::cout << "No user named " << user << std::endl;
        }
        else {
                while(std::getline(fin,line)) {
                        temp = empty;
                        line = "log " + line;
                        in.flags(line, temp);
                        if(temp[0] == vec[0]) {
                                if(temp[1] == vec[1]) {
                                        std::system("clear");
                                        std::cout << "Logged in!\n";
                                        if(temp[2] == "user") {
                                                std::cout << "Welcome " << temp[0] << " you are a user.\n";
                                                en.encryptf("./users/"+ user + "/cred.txt");
                                                priv = 1;
                                                break;
                                        }
                                        else if(temp[2] == "mod") {
                                                std::cout << "Welcome " << temp[0] << " you are a mod.\n";
                                                en.encryptf("./users/"+ user + "/cred.txt");
                                                priv = 2;
                                                break;
                                        }
                                        else if(temp[2] == "admin") {
                                                std::cout << "Welcome " << temp[0] << " you are an admin.\n";
                                                en.encryptf("./users/"+ user + "/cred.txt");
                                                priv = 3;
                                                break;
                                        }
                                }
                                else {
                                        std::cout << "Incorrect Password!\n";
                                        priv = 0;
                                        break;
                                }

                        }

                }
        }
}


// Will be written later
void auth::reg(std::vector<std::string> vec, int &priv) {

}
