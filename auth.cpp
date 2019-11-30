#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include "auth.h"
#include "strm.h"
#include "encrypt.h"
#include <termios.h>
#include <unistd.h>

void HideStdinKeystrokes() {
        termios tty;
        tcgetattr(STDIN_FILENO, &tty);
        tty.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

void ShowStdinKeystrokes()
{
        termios tty;
        tcgetattr(STDIN_FILENO, &tty);
        tty.c_lflag |= ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

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

void auth::login(std::vector<std::string> vec, int &priv, std::string &user, bool skip) {
        std::ifstream fin;
        std::string line, password, line2;
        std::vector<std::string> temp, empty;
        strm in;
        bool plaincheck = false;
        auth test;
        std::fstream create;
        int fails = 0;
        encrypt en;
        fin.open("./users/"+ user + "/cred.txt");
        if(fin.fail()) {
                std::cout << "No user named " << user << std::endl;
        }
        else {
                std::getline(fin,line2);
                fin.close();
                if(user != in.frontcut(line2,in.gfsin(line2) - 1)) {
                        en.decryptf("./users/"+ user + "/cred.txt");
                        fin.open("./users/"+ user + "/cred.txt");
                        std::getline(fin,line);
                        temp = empty;
                        line = "log " + line;
                        in.flags(line, temp);
                        while(fails < 3) {
                                if(temp[0] == user) {
                                        if(skip == false) {
                                                std::cout << "Please enter password: ";
                                                HideStdinKeystrokes();
                                                getline(std::cin, password);
                                                ShowStdinKeystrokes();
                                                std::cout << '\n';
                                                if(temp[1] == password) {
                                                        std::system("clear");
                                                        std::cout << "Logged in!\n";
                                                        if(temp[2] == "user") {
                                                                std::cout << "Welcome " << temp[0] << " you are a user.\n";
                                                                en.encryptf("./users/"+ user + "/cred.txt");
                                                                in.wlog(user + " Logged in on", user);
                                                                priv = 1;
                                                                break;
                                                        }
                                                        else if(temp[2] == "mod") {
                                                                std::cout << "Welcome " << temp[0] << " you are a mod.\n";
                                                                en.encryptf("./users/"+ user + "/cred.txt");
                                                                in.wlog(user + " Logged in on", user);
                                                                priv = 2;
                                                                break;
                                                        }
                                                        else if(temp[2] == "admin") {
                                                                std::cout << "Welcome " << temp[0] << " you are an admin.\n";
                                                                en.encryptf("./users/"+ user + "/cred.txt");
                                                                in.wlog(user + " Logged in on", user);
                                                                priv = 3;
                                                                break;
                                                        }
                                                }
                                                else {
                                                        fails++;
                                                        std::cout << "Incorrect Password! Number of attempts remaining: " << 3 - fails << '\n';
                                                        en.encryptf("./users/"+ user + "/cred.txt");
                                                }
                                        }
                                        else{
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
                                }
                        }
                }
                else {
                        std::cout << "Error with account! Try logging in again!\n";
                        en.encryptf("./users/" + user + "/cred.txt");
                }
        }
}


// Will be written later
void auth::reg(std::vector<std::string> vec, int &priv, std::string &user) {

        std::string password, email = vec[1], folderlocation = "./users/" + user + '/', command = "mkdir " + folderlocation;
        std::cout << "Please enter a password: ";
        HideStdinKeystrokes();
        getline(std::cin, password);
        ShowStdinKeystrokes();
        std::cout << '\n';
        std::ifstream input;
        std::fstream output;
        input.open(folderlocation + "cred.txt");
        encrypt en;
        if(input.fail()) {
                system(command.c_str());
                output.open(folderlocation + "cred.txt", std::fstream::out);
                output << user << " " << password << " user " << email;
                output.close();
                en.encryptf(folderlocation + "cred.txt");
        }
        else if (!input.fail()) {
                std::cout <<  "User already exists!\n";
        }

}
