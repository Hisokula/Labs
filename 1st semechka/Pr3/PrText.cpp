#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <algorithm>

namespace esp
{

    void Transformation(int LIST[8][2])
    {
        std::string str;

        std::string letters = "";

        int List[8] = {};

        for (int o = 0; o < 8; o++)
        {
            List[o] = LIST[o][1];
        }

        std::string Alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
        std::string AlphaLIST = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        std::string Alphalist = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";

        int i = -1;



        std::ifstream in("input.txt", std::ios::in);

        std::ofstream out("output.txt", std::ios::out);

        while (!in.eof())
        {
            i++;

            int schet = 0;

            in >> str;

            for (int p = 0; p < str.length(); p++)
            {
                letters += '0';
            }

            for (int t = 0; t < str.length(); t++)
            {
                for (int s = 0; s < 8; s++)
                {
                    if ((str[t] == AlphaLIST[List[s]]) || (str[t] == Alphalist[List[s]]))
                    {
                        if (std::count(letters.begin(), letters.end(), str[t]) == 0)
                        {
                            letters[schet] = str[t];
                            schet++;
                        }

                    }
                }

            }

            if (schet >= 5)
            {
                for (int t = 0; t < str.length(); t++)
                {
                    for (int p = 0; p < Alphalist.length(); p++)
                    {
                        if (str[t] == Alphalist[p])
                        {
                            str[t] = AlphaLIST[p];
                        }
                    }
                }

                /*for (int t = 0; t < letters.length(); t++)
                {
                    for (int p = 0; p < letters.length(); p++)
                    {
                        
                    }
                }
                */
                std::string outp;

                outp = str + "(";

                for (int g = 0; g < schet; g++)
                {
                    outp = outp + letters[g] + "," + " ";
                }

                outp = outp + ')' + " ";
                outp[str.length() + schet*3 - 1] = ' ';
                schet = 0;

                out << outp;
                outp = "";
            }
            else
            {
                out << str << " ";
            }


            letters = "";
        }
    }

    std::string Process(std::string Text)
    {
        std::string Alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";

        int LCount[66] = {};

        int LetterCount[33] = {};

        int MaxCount[8][2] = {};

        for (int m = 0; m < 8; m++)
        {
            for (int n = 0; n < 2; n++)
            {
                MaxCount[m][n] = 0;
            }
        }

        for (int i = 0; i < Alphabet.length(); i++)
        {
            LCount[i] = std::count(Text.begin(), Text.end(), Alphabet[i]);

        }

        int ml = 0;
        int chet = 0;
        int Chetchik[8] = {};


        for (int i = 0; i < 33; i++)
        {
            LetterCount[i] = LCount[i + 33];
        }

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 33; j++)
            {
                if (LetterCount[j] > ml)
                {
                    ml = LetterCount[j];
                    chet = j;
                }
            }
            Chetchik[i] = chet;
            MaxCount[i][0] = ml;

            LetterCount[chet] = -LetterCount[chet];
            ml = -1;
        }


        for (int j = 0; j < 8; j++)
        {
            MaxCount[j][1] = Chetchik[j];
        }

        esp::Transformation(MaxCount);

        return Text;
    }

    std::string Input()
    {
        std::string Inp;
        std::string str;

        std::ifstream in("input.txt", std::ios::in);
        while (!in.eof())
        {
            in >> str;
            Inp += " " + str;
        }

        in.clear();

        return Inp;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUSSIAN");

    std::string a;
    a = esp::Input();

    a = esp::Process(a);

}

// Русские буквы в ASCII
// Заглавные 128-159(от А до Я без Ё)
// Строчные 160-175(от а до п без ё)
// 224-239(от р до я)
// 240(Ё), 241(ё)

// Итого 128-175 + 224-241

//МИР ТАКОВ, КАКОВ ОН ЕСТЬ
//(По А.Моруа)