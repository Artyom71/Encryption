//Copyright 2018 by Akopyan Artyom
#define _CRT_SECURE_NO_WARNINGS
#include "header.hpp"

void Menu()
{
    int menu = 0;
    std::string enFile;
    std::string deFile;
    std::string deEnFile;
    setlocale(LC_ALL, "Russian");
    while (menu != 1 && menu != 2 && menu != 3 && menu != 4)
    {
        std::cout << std::endl;
        std::cout << "-------------------------" << std::endl;
        std::cout << "          Меню" << std::endl;
        std::cout << " 1. Шифрование файла " << std::endl;
        std::cout << " 2. Расшифрование файла " << std::endl;
        std::cout << " 3. Помощь " << std::endl;
        std::cout << " 4. Выход" << std::endl;
        std::cout << "-------------------------" << std::endl;
        std::cout << "Выберите один из пунктов меню: ";
        std::cin >> menu;
        std::cout << std::endl;
    }
    if (menu == 1) // шифрование
    {
        std::cout << "Зашифровка: " << std::endl;
        std::cout << "Введите путь до файла: ";
        std::cin >> enFile;
        std::cout << "Введите путь до выходного файла: ";
        std::cin >> deFile;
        bool check = false; // проверка на успешную шифровку
        FILE* fOut = fopen(deFile.c_str(), "r+t");
        std::vector<char> deMass;
        if (fOut != NULL)
        {
            std::cout << std::endl;
            std::cout << "Файл для записи открыт!" << std::endl;
            for (size_t i = 0; i < N; i++)
            {
                fseek(fOut, 0 + 4 * i, 0);
                deMass = Encryption(enFile, i);
                if (deMass.size() != 0)
                {
                    if (i == 0)
                    {
                        std::cout << "Файл для чтения открыт!" << std::endl;
                        check = true;
                    }
                    for (size_t j = 0; j < deMass.size(); j++)
                    {
                        fwrite(&deMass[j], sizeof(char), 1, fOut);
                    }
                }
                else
                {
                    break;
                }
            }
            fclose(fOut);
            if (check)
            {
                std::cout << "Зашифровка прошла успешно!" << std::endl << std::endl;
            }
            else
            {
                std::cout << "Зашифровка  НЕ прошла успешно!" << std::endl << std::endl;
            }
        }
        else
        {
            std::cout << std::endl;
            std::cout << "Ошибка открытия файла записи!" << std::endl;
            std::cout << "Зашифровка  НЕ прошла успешно!" << std::endl << std::endl;
        }
        Menu();
    }
    if (menu == 2) // расшифровка
    {
        std::cout << "Расшифровка: " << std::endl;
        std::cout << "Введите путь до зашифрованного файла: ";
        std::cin >> deFile;
        std::cout << "Введите путь до выходного файла: ";
        std::cin >> deEnFile;
        bool check = false;
        FILE* fileOut = fopen(deEnFile.c_str(), "r+t");
        std::vector<char> dedeMass;
        if (fileOut != NULL)
        {
            std::cout << std::endl;
            std::cout << "Файл для записи открыт!" << std::endl;
            for (size_t i = 0; i < N; i++)
            {
                fseek(fileOut, 0 + 4 * i, 0);
                dedeMass = Decryption(deFile, i);
                if (dedeMass.size() != 0)
                {
                    if (i == 0)
                    {
                        std::cout << "Файл для чтения открыт!" << std::endl;
                        check = true;
                    }
                    for (size_t j = 0; j < dedeMass.size(); j++)
                    {
                        fwrite(&dedeMass[j], sizeof(char), 1, fileOut);
                    }
                }
                else
                {
                    break;
                }
            }
            fclose(fileOut);
            if (check)
            {
                std::cout << "Расшифровка прошла успешно!" << std::endl << std::endl;
            }
            else
            {
                std::cout << "Расшифровка  НЕ прошла успешно!" << std::endl << std::endl;
            }
        }
        else
        {
            std::cout << std::endl;
            std::cout << "Ошибка открытия файла записи!" << std::endl;
            std::cout << "Расшифровка  НЕ прошла успешно!" << std::endl << std::endl;
        }
        Menu();
    }
    if (menu == 3) // помощь
    {
        Help();
        Menu();
    }
    if (menu == 4) // выход
    {
        Exit();
    }
}

int Exit()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Выход..." << std::endl;
    return 0;
}

void Help()
{
    char stp = 0;
    setlocale(LC_ALL, "Russian");
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << " Помощь по работе в приложении:" << std::endl;
    std::cout << std::endl;
    std::cout << " 1. Шифрование: после выбора соответствующего пункта меню" << std::endl;
    std::cout << " необходимо ввести полный путь до файла," << std::endl;
    std::cout << " который необходимо зашифровать, и полный путь до нового," << std::endl;
    std::cout << " в котором будет зашифрованное содержимое." << std::endl;
    std::cout << std::endl;
    std::cout << " Пример:" << std::endl;
    std::cout << " Введите путь до файла:" << std::endl;
    std::cout << " C:/path/to/file.txt" << std::endl;
    std::cout << " Введите путь до выходного файла:" << std::endl;
    std::cout << " C:/path/to/crypt_file.txt" << std::endl;
    std::cout << std::endl;
    std::cout << " 2. Расшифрование: после выбора соответствующего пункта меню" << std::endl;
    std::cout << " необходимо ввести полный путь до файла," << std::endl;
    std::cout << " который необходимо расшифровать, и полный путь до нового," << std::endl;
    std::cout << " в котором будет расшифрованное содержимое." << std::endl;
    std::cout << std::endl;
    std::cout << " Пример:" << std::endl;
    std::cout << " Введите путь до файла:" << std::endl;
    std::cout << " C:/path/to/crypt_file.txt" << std::endl;
    std::cout << " Введите путь до выходного файла:" << std::endl;
    std::cout << " C:/path/to/decrypt_file.txt" << std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;
    system("pause");
}

const std::string& CFile(const std::string& En, const std::string& EnCopy)
{
    std::ifstream fileIn;
    fileIn.open(En);
    std::ofstream fileOut;
    fileOut.open(EnCopy);
    fileOut.clear();
    char sym;
    if (fileIn.is_open())
    {
        std::cout << "OK_1" << std::endl;
        if (fileOut.is_open())
        {
            std::cout << "OK_2" << std::endl;
            do
            {
                sym = fileIn.get();
                fileOut << sym;
            } while (!fileIn.eof());
        }
    }
    fileIn.close();
    fileOut.close();
    return EnCopy;
}

std::vector<char> Encryption(const std::string& fileEn,/* const std::string& fileDe,*/ int I)
{
    setlocale(LC_ALL, "Russian");
    char data1[2] = ""; // массив чаров для первой половины
    char data2[2] = ""; // массив чаров для второй половины
    char data3[2] = ""; // массив чаров для первой половины выходного файла
    char data4[2] = ""; // массив чаров для второй половины выходного 
    std::vector<char> data5;
    char buffer = 0; // переменная для считывания каждого символа
    FILE* fIn = fopen(fileEn.c_str(), "r+t");
    if (fIn != NULL)
    {
        fseek(fIn, 0 + 4*I, 0);
        for (size_t i = 0; i < 4; i++)
        {
            if ((buffer = getc(fIn)) != EOF)
            {
                if (i < 2)
                {
                    data1[i] = buffer;
                }
                else
                {
                    data2[i - 2] = buffer;
                }
            }
        }
    }
    else
    {
        return data5;
    }
    fclose(fIn);
    if (data1[0] == 0 || data1[1] == 0 || data2[0] == 0 || data2[1] == 0)
    {
        //int countExit = 0;
        if (data1[0] == 0)
        {
            return data5;
        }
        else if (data1[1] == 0)
        {
            //countExit += 1;
            data5.push_back(data1[0] ^ K);
        }
        else if (data2[0] == 0)
        {
            //countExit += 2;
            data5.push_back(data1[0] ^ K);
            data5.push_back(data1[1] ^ K);
        }
        else if (data2[1] == 0)
        {
            //countExit += 3;
            data5.push_back(data1[0] ^ K);
            data5.push_back(data1[1] ^ K);
            data5.push_back(ModPlus(data5[0], LeftShift(data2[0])));
        }
        /*if (countExit == 1)
        {
            data5[1] = '\0';
        }
        if (countExit == 2)
        {
            data5[2] = '\0';
        }
        if (countExit == 3)
        {
            data5[3] = '\0';
        }*/
        return data5;
    }
    data3[0] = data1[0] ^ K; // XOR
    data3[1] = data1[1] ^ K; // XOR
    data4[0] = LeftShift(data2[0]); // <<
    data4[1] = LeftShift(data2[1]); // <<
    data4[0] = ModPlus(data3[0], data4[0]); // mod M
    data4[1] = ModPlus(data3[1], data4[1]); // mod M

    data4[0] = data4[0] ^ K; // XOR
    data4[1] = data4[1] ^ K; // XOR
    data3[0] = LeftShift(data3[0]); // <<
    data3[1] = LeftShift(data3[1]); // <<
    data3[0] = ModPlus(data4[0], data3[0]); // mod M
    data3[1] = ModPlus(data4[1], data3[1]); // mod M
    for (size_t i = 0; i < 4; i++)
    {
        if (i < 2)
        {
            data5.push_back(data3[i]);
        }
        else
        {
            data5.push_back(data4[i - 2]);
        }
    }
    return data5;
}

std::vector<char> Decryption(const std::string& fileDe, int I)
{
    setlocale(LC_ALL, "Russian");
    char data1[2] = ""; // массив чаров для первой половины
    char data2[2] = ""; // массив чаров для второй половины
    char data3[2] = ""; // массив чаров для первой половины выходного файла
    char data4[2] = ""; // массив чаров для второй половины выходного файла
    std::vector<char> data5;
    char buffer = 0; // переменная для считывания каждого символа
    FILE* fIn = fopen(fileDe.c_str(), "r+t");
    
    if (fIn != NULL)
    {
        fseek(fIn, 0 + 4 * I, 0);
        for (size_t i = 0; i < 4; i++)
        {
            if ((buffer = getc(fIn)) != EOF)
            {
                if (i < 2)
                {
                    data1[i] = buffer;
                }
                else
                {
                    data2[i - 2] = buffer;
                }
            }
        }
    }
    else
    {
        return data5;
    }
    fclose(fIn);
    if (data1[0] == 0 || data1[1] == 0 || data2[0] == 0 || data2[1] == 0)
    {
        //int countExit = 0;
        if (data1[0] == 0)
        {
            return data5;
        }
        else if (data1[1] == 0)
        {
            //countExit += 1;
            data5.push_back(data1[0] ^ K);
        }
        else if (data2[0] == 0)
        {
            //countExit += 2;
            data5.push_back(data1[0] ^ K);
            data5.push_back(data1[1] ^ K);
        }
        else if (data2[1] == 0)
        {
            //countExit += 3;
            
            data5.push_back(data1[0] ^ K);
            data5.push_back(data1[1] ^ K);
            data5.push_back(RightShift(ModMinus(data2[0], data1[0])));
        }
        /*if (countExit == 1)
        {
            data5[1] = '\0';
        }
        if (countExit == 2)
        {
            data5[2] = '\0';
        }
        if (countExit == 3)
        {
            data5[3] = '\0';
        }*/
        return data5;
    }

    data3[0] = ModMinus(data1[0], data2[0]); // mod M
    data3[1] = ModMinus(data1[1], data2[1]); // mod M
    data3[0] = RightShift(data3[0]); // >>
    data3[1] = RightShift(data3[1]); // >>
    data4[0] = data2[0] ^ K; // XOR
    data4[1] = data2[1] ^ K; // XOR

    data4[0] = ModMinus(data4[0], data3[0]); // mod M
    data4[1] = ModMinus(data4[1], data3[1]); // mod M
    data3[0] = data3[0] ^ K;
    data3[1] = data3[1] ^ K;
    data4[0] = RightShift(data4[0]); // >>
    data4[1] = RightShift(data4[1]); // >>
    for (size_t i = 0; i < 4; i++)
    {
        if (i < 2)
        {
            data5.push_back(data3[i]);
        }
        else
        {
            data5.push_back(data4[i - 2]);
        }
    }
    return data5;
}

unsigned char LeftShift(unsigned char a)
{
    unsigned char ret;
    unsigned int number10 = (unsigned int)a;
    int number2 = _10_to_2_(number10);
    int buf = 0;
    std::vector<unsigned int> num;
    while (number2 != 0)
    {
        buf = number2 % 2;
        number2 /= 10;
        num.push_back(buf);
    }
    while (num.size() < 8)
    {
        num.push_back(0);
    }
    std::reverse(num.begin(), num.end()); // число в двоичной сс в нормальном виде
    int tmp = 0;
    for (size_t i = 0; i < R; i++)
    {
        tmp = num[0];
        for (size_t j = 0; j < num.size() - 1; j++)
        {
            num[j] = num[j + 1];
        }
        num[num.size() - 1] = tmp;
    }
    int value10 = 0;
    int g = 0;
    for (size_t i = num.size() - 1; i > 0; i--)
    {
        if (i == 1)
        {
            value10 += num[g] * pow(2, i);
            value10 += num[g + 1];
            break;
        }
        value10 += num[g] * pow(2, i);
        g++;
    }
    ret = (unsigned char)value10;
    return ret;
}

unsigned char RightShift(unsigned char a)
{
    unsigned char ret;
    unsigned int number10 = (unsigned int)a;
    int number2 = _10_to_2_(number10);
    int buf = 0;
    std::vector<int> num;
    while (number2 != 0)
    {
        buf = number2 % 2;
        number2 /= 10;
        num.push_back(buf);
    }
    while (num.size() < 8)
    {
        num.push_back(0);
    }
    std::reverse(num.begin(), num.end()); // число в двоичной сс в перевернутом виде
    int tmp = 0;
    for (size_t i = 0; i < R; i++)
    {
        tmp = num[num.size() - 1];
        for (size_t j = num.size() - 1; j > 0; j--)
        {
            num[j] = num[j - 1];
        }
        num[0] = tmp;
    }
    int value10 = 0;
    int g = 0;
    for (size_t i = num.size() - 1; i > 0; i--)
    {
        if (i == 1)
        {
            value10 += num[g] * pow(2, i);
            value10 += num[g + 1];
            break;
        }
        value10 += num[g] * pow(2, i);
        g++;
    }
    ret = (unsigned char)value10;
    return ret;
}

unsigned char ModPlus(unsigned char a, unsigned char b)
{
    unsigned char mod;
    int aT = (int)a;
    int bT = (int)b;
    mod = (char)((aT + bT) % M);
    return mod;
}

unsigned char ModMinus(unsigned char a, unsigned char b)
{
    unsigned char mod;
    int aT = (int)a;
    int bT = (int)b;
    mod = (char)((aT - bT) % M);
    return mod;
}

long _10_to_2_(int x)
{

    int i;
    int mod;
    long double_ = 0;

    for (i = 0; x > 0; i++)
    {
        mod = x % 2;
        x = (x - mod) / 2;
        double_ += mod * pow((double)10, i);
    }
    return double_;
}
