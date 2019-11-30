#include <cryptopp/aes.h>
#include <cryptopp/filters.h>
#include <cryptopp/modes.h>
#include <cryptopp/osrng.h>
#include <iostream>
#include <stack>

class encrypt {
private:
public:
  void encryptf(std::string);
  void decryptf(std::string);
};
