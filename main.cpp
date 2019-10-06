#include <iostream>
#include <cstddef>
#include <vector>
#include <signal.h>
#include "strm.h"
#include <cryptopp/aes.h>
#include <cryptopp/osrng.h>



void ctrl_cz_block(int signum) {

}

int main() {
        std::string i = "";
        strm input;
        signal(SIGINT, &ctrl_cz_block);
        signal(SIGTSTP, &ctrl_cz_block);
        signal(SIGQUIT, &ctrl_cz_block);
        std::cout << "Key length: " << CryptoPP::AES::DEFAULT_KEYLENGTH << std::endl;
        CryptoPP::AutoSeededRandomPool rnd;
        CryptoPP::SecByteBlock key(0x00, CryptoPP::AES::DEFAULT_KEYLENGTH);
        rnd.GenerateBlock( key, key.size() );

        CryptoPP::SecByteBlock iv(CryptoPP::AES::BLOCKSIZE);
        rnd.GenerateBlock(iv, iv.size());

        for(;;) {
                i = input.dinput(i);
        }
}
