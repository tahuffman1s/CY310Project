#!/usr/bin/env bash
# This script compiles the code
g++ -std=gnu++11 strm.h encrypt.h encrypt.cpp strm.cpp auth.h auth.cpp main.cpp -o project -lcryptopp -lcurl
