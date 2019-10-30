// Implementation of string manipulation class

#include <iostream>
#include <limits>
#include <string>
#include <queue>
#include <fstream>
#include <ctime>
#include "strm.h"

// Default Input function

std::string strm::dinput(std::string input, int &priv, std::string &user, std::priority_queue<std::string> &cmdqueue) {
        std::cout << "> ";
        strm log;
        std::getline(std::cin,input);
        time_t now = time(0);
        char* dt = ctime(&now);
        cmdqueue.push(input + " " + dt);
        log.wlog(cmdqueue, user);
        while(!cmdqueue.empty()) {
                cmdqueue.pop();
        }
        return input;
}

// cifs checks if there is a space in an input string
// returns true if and only if there is a space

bool strm::cifs(std::string input) {
        int i = 0;
        while(i != input.length()) {
                if(input[i] == ' ') {
                        return true;
                }
                ++i;
        }
        return false;
}

// gfsin returns the index value of the first space
// Used to cut strings int the right parts for processing

int strm::gfsin(std::string input) {
        int i = 0;
        if (cifs(input) != false) {
                while(i != input.length()) {
                        if(input[i] == ' ') {
                                return i;
                        }
                        ++i;
                }
        }
        else {
                return 0;
        }

}

// frontcut cuts the string at the index point
// frontcut starts at the beginning

std::string strm::frontcut(std::string input, int index) {
        std::string return_string = "";
        int i = 0;
        if(index < input.length() && index > 0) {
                while(i <= index) {
                        return_string = return_string + input[i];
                        i++;
                }
        }

        return return_string;
}

// Backcut cuts the string at the index point
// Backcut starts from the end of a string.

std::string strm::backcut(std::string input, int index) {
        std::string return_string = "";
        int i = index;
        if(index < input.length() && index > 0) {
                while(i < input.length()) {
                        return_string = return_string + input[i];
                        i++;
                }
        }

        return return_string;
}

// Flags stores flags into a vector and returns the vector.
// Works via recursion.
// Supports a theoretically infinite number of Flags.

void strm::flags(std::string input, std::vector<std::string>&ret) {
        strm in;
        std::string flag;
        input = in.backcut(input,in.gfsin(input) + 1);
        if(in.cifs(input) == false) {
                ret.push_back(input);
        }
        else {
                flag = in.frontcut(input,in.gfsin(input) - 1);
                ret.push_back(flag);
                in.flags(input, ret);
        }

}


// Counts the number of spaces in a string.

int strm::spcnt(std::string input) {
        int ret = 0, count = 0;
        while(count != input.length()) {
                if(input[count] == ' ') {
                        ret++;
                }
                count++;
        }
        return ret;
}

void strm::wlog(std::priority_queue<std::string> &cmdqueue, std::string user){
        std::fstream fout;
        std::string line;
        std::priority_queue<std::string> combo, combotemp = cmdqueue, stor, temp = cmdqueue;
        std::string loc = "./log/users/" + user + ".txt";
        fout.open(loc, std::fstream::in);
        while(getline(fout,line)) {
                stor.push(line);
        }
        while(!combotemp.empty()) {
                combo.push(combotemp.top());
                combotemp.pop();
        }
        while(!stor.empty()) {
                combo.push(stor.top());
                stor.pop();
        }
        cmdqueue = combo;
        temp = cmdqueue;
        fout.close();
        fout.open(loc, std::fstream::out);
        while(!temp.empty()) {
                fout << temp.top() << '\n';
                temp.pop();
        }
}
