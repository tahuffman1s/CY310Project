// Implementation of string manipulation class

#include <iostream>
#include <limits>
#include <string>
#include "strm.h"

// Default Input function

std::string strm::dinput(std::string input) {
        std::cout << "> ";
        std::getline(std::cin,input);

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
                flag = input;
                ret.push_back(flag);
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
