#include <iostream>                                                             // Standard
#include <limits>                                                             // Used for INT_MAX
#include <cstddef>
#include <signal.h>                                                             // Used to read signals i.e. ctrl c and ctrl z
#include <ncurses.h>                                                             // Used for keyup event detection
#include <stack>                                                                // Used to hold the string stack
#include "strm.h"                                                               // Custom string manipulation class

void ctrl_cz_block(int signum) {                                                // This function is called whenever CTRL-C or CTRL-Z is pressed.

}

int main() {
        std::string i = "", gfsint = "meme machine", cifsteststr = "no";        // Makes the test strings, and the input string.
        strm input;
        std::stack<std::string> strstack;                                       // Creates a stack to hold the user input to navigate.
        int gfsintest = input.gfsin(gfsint);                                    // Debugging tests gfsin
        bool cifstest = input.cifs(cifsteststr);                                // Debugging tests cifs
        std::cout << gfsintest << std::endl;                                    // Outputs gfsin test;
        if(cifstest == false) {
                std::cout << "Cifs works\n";                                    // Ouputs cifs test;
        }
        signal(SIGINT, &ctrl_cz_block);
        signal(SIGTSTP, &ctrl_cz_block);
        for(;;) {
                i = input.dinput(i);
                strstack.push(i);
        }
}
