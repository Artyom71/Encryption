//Copyright 2018 by Akopyan Artyom
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "windows.h" // CopyFile
#include <cstdio>
#include <stdio.h>
#include <algorithm>

const unsigned long int M = 0xffffffff; // 2^32 - 1
const int R = 13;
const int K = 0x1234;
const int N = 16;

void Menu();
std::vector<char> Encryption(const std::string&, int); // шифрование
std::vector<char> Decryption(const std::string&, int); // расшифровка
void Help();
int Exit();
const std::string& CFile(const std::string&, const std::string&);
unsigned char LeftShift(unsigned char); // побитовый сдвиг влево <<
unsigned char RightShift(unsigned char); // побитовый сдвиг право >>
unsigned char ModPlus(unsigned char, unsigned char);
unsigned char ModMinus(unsigned char, unsigned char);
long _10_to_2_(int x);
