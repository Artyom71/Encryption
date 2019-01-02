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
        bool check = false;
        FILE* fOut = fopen(deFile.c_str(), "r+t");
        char* deMass;
        if (fOut != NULL)
        {
            std::cout << std::endl;
            std::cout << "Файл для записи открыт!" << std::endl;
            for (size_t i = 0; i < 2*N; i++)
            {
                fseek(fOut, 0 + 4 * i, 0);
                deMass = Encryption(enFile, i);
                if (deMass != NULL)
                {
                    if (i == 0)
                    {
                        std::cout << "Файл для чтения открыт!" << std::endl;
                        check = true;
                    }
                    for (size_t j = 0; j < 4; j++)
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
        char* dedeMass;
        if (fileOut != NULL)
        {
            std::cout << std::endl;
            std::cout << "Файл для записи открыт!" << std::endl;
            for (size_t i = 0; i < 2*N; i++)
            {
                fseek(fileOut, 0 + 4 * i, 0);
                dedeMass = Decryption(deFile, i);
                if (dedeMass != NULL)
                {
                    if (i == 0)
                    {
                        std::cout << "Файл для чтения открыт!" << std::endl;
                        check = true;
                    }
                    for (size_t j = 0; j < 4; j++)
                    {
                        fwrite(&dedeMass[j], sizeof(char), 1, fileOut);
                    }
                }
                else
                {
                    break;
                }
            }
            fputs('\0', fileOut);
            fclose(fileOut);
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
char* Encryption(const std::string& fileEn,/* const std::string& fileDe,*/ int I)
{
    setlocale(LC_ALL, "Russian");
    char data1[2] = ""; // массив чаров для первой половины
    char data2[2] = ""; // массив чаров для второй половины
    char data3[2] = ""; // массив чаров для первой половины выходного файла
    char data4[2] = ""; // массив чаров для второй половины выходного 
    char* data5 = new char[4];
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
        data5 = NULL;
        return data5;
    }
    fclose(fIn);

    for (size_t i = 0; i < 2; i++)
    {
        data3[i] = data1[i] ^ K; // XOR
        data4[i] = LeftShift(data2[i]); // <<
        data4[i] = ModPlus(data3[i], data4[i]); // mod M
        std::swap(data3[i], data4[i]); // Зеркальный повтор
    }
    for (size_t i = 0; i < 4; i++)
    {
        if (i < 2)
        {
            data5[i] = data3[i];
        }
        else
        {
            data5[i] = data4[i - 2];
        }
    }
    data5[4] = '\0';
    return data5;
}

unsigned char LeftShift(unsigned char a)
{
    unsigned char bits = a >> R; // 8-1=7, 1 старший бит станет младшим
    a <<= 1; // Сдвиг влево на 1 бит
    return a | bits;
}

unsigned char RightShift(unsigned char a)
{
    unsigned char bits = a << R; // 8-1=7, 1 младший бит станет старшим
    a >>= 1; // Сдвиг вправо на 1 бит
    return a | bits;
}

char* Decryption(const std::string& fileDe, int I)
{
    setlocale(LC_ALL, "Russian");
    char data1[2] = ""; // массив чаров для первой половины
    char data2[2] = ""; // массив чаров для второй половины
    char data3[2] = ""; // массив чаров для первой половины выходного файла
    char data4[2] = ""; // массив чаров для второй половины выходного файла
    char* data5 = new char[4];
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
        data5 = NULL;
        return data5;
    }
    fclose(fIn);

    for (size_t i = 0; i < 2; i++)
    {
        std::swap(data1[i], data2[i]);
        data3[i] = data1[i] ^ K; // XOR
        data4[i] = ModMinus(data2[i], data1[i]); // mod M
        data4[i] = RightShift(data4[i]); // >>
    }
    for (size_t i = 0; i < 4; i++)
    {
        if (i < 2)
        {
            data5[i] = data3[i];
        }
        else
        {
            data5[i] = data4[i - 2];
        }
    }
    data5[4] = '\0';
    return data5;
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
