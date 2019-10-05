#!/usr/bin/env bash
# This script compiles the code
g++ -std=c++17 tomcrypt.h strm.h aes.c strm.cpp main.cpp -o project 
