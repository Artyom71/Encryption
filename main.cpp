//Copyright 2018 by Akopyan Artyom
#include <iostream>
#include <vector>
#include <string>
#include "header.hpp"

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "            Приложение для шифрования и дешифрования файлов" << std::endl;
    std::cout << "! Перед использованием приложения создайте файл для шифровки и расшифровки !" << std::endl;
    std::cout << std::endl;

    Menu();
}
