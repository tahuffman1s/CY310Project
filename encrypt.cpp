#include "encrypt.hpp"
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>
#include <cryptopp/aes.h>
#include <cryptopp/osrng.h>
#include <iostream>
#include <fstream>
#include <stack>
byte key[ CryptoPP::AES::DEFAULT_KEYLENGTH ], iv[ CryptoPP::AES::BLOCKSIZE ];
void encrypt::encryptf(std::string fname) {

        std::fstream input, output;
        std::stack<std::string> ciphertext;
        std::string line, cipherline;
        input.open(fname,std::fstream::in);
        if (input.fail()) {

        }
        else{

                memset( key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH );
                memset( iv, 0x00, CryptoPP::AES::BLOCKSIZE );
                CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
                CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption( aesEncryption, iv );
                while(getline(input, line)) {
                        cipherline = "";
                        CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink( cipherline ) );
                        stfEncryptor.Put( reinterpret_cast<const unsigned char*>( line.c_str() ), line.length() );
                        stfEncryptor.MessageEnd();
                        ciphertext.push(cipherline);
                }
                input.close();
                output.open(fname, std::fstream::out);
                while(!ciphertext.empty()) {
                        output << ciphertext.top() << '\n';
                        ciphertext.pop();
                }
                output.close();
        }

}

void encrypt::decryptf(std::string fname) {
        std::fstream input, output;
        std::stack<std::string> plaintext;
        std::string cipherline, line;
        input.open(fname,std::fstream::in);
        if (input.fail()) {

        }
        else{
                CryptoPP::AES::Decryption aesDecryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
                CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption( aesDecryption, iv );
                while(getline(input,cipherline)) {
                        line = "";
                        CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink( line ) );
                        stfDecryptor.Put( reinterpret_cast<const unsigned char*>( cipherline.c_str() ), cipherline.length() );
                        stfDecryptor.MessageEnd();
                        plaintext.push(line);
                }
                input.close();
                output.open(fname, std::fstream::out);
                while(!plaintext.empty()) {
                        output << plaintext.top() << '\n';
                        plaintext.pop();
                }
                output.close();
        }
}
