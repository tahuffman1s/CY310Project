#!/usr/bin/env bash
# This script compiles the code
g++ -std=c++17 strm.h strm.cpp main.cpp -o project -lncurses -ltinfo
