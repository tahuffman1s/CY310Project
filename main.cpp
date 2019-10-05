#include <iostream>                                                             // Standard
#include <cstddef>
#include <vector>
#include <signal.h>                                                             // Used to read signals i.e. ctrl c and ctrl z
#include "strm.h"                                                               // Custom string manipulation class

void ctrl_cz_block(int signum) {                                                // This function is called whenever CTRL-C or CTRL-Z is pressed.

}

int main() {
        std::string i = "";
        strm input;
        signal(SIGINT, &ctrl_cz_block);
        signal(SIGTSTP, &ctrl_cz_block);
        signal(SIGQUIT, &ctrl_cz_block);
        for(;;) {
                i = input.dinput(i);
        }
}
