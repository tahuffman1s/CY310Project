#!/usr/bin/env bash
# This script compiles the code
g++ -std=gnu++11 strm.hpp encrypt.hpp encrypt.cpp strm.cpp auth.hpp auth.cpp commands.hpp commands.cpp main.cpp -o project -lcryptopp -lcurl
