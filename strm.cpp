// Implementation of string manipulation class

#include <iostream>
#include <limits>
#include <string>
#include "strm.h"

// Default Input function

std::string strm::dinput(std::string input) {
        std::cout << "> ";
        getline(input,std::cin);

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
        std::string return_string;

}
