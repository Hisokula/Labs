#include"Header.hpp";
#include<iostream>;
#include<string>;

namespace esp
{
    void Output(std::string str1, std::string str2)
    {
        std::cout << str1 << std::endl;
        std::cout << str2 << std::endl;
    }

    void FlagSort(std::string* str1, std::string* str2)                              // it works
    {
        if ((*str1).length() < (*str2).length())
        {
            std::swap(*str1, *str2);
        }
        if ((*str1).length() != (*str2).length())
        {
            while ((*str1).length() != (*str2).length())
            {
                *str2 = "0" + *str2;
            }
        }
    }

    //__________________________________________________________________________________________________________________________// it is not

    void Sum(std::string str1, std::string str2, std::string sum)
    {
        std::string StrokaSum[2000];

        for (int s = 0; s < 2000; s++)
        {
            StrokaSum[s] = "";
        }

        bool f = 0;
        int help = 0;

        for (int i = 0; i < str1.length(); i++)
        {
            int c1 = int(str1[str1.length() - i]);
            int c2 = int(str2[str2.length() - i]);

            int a = 0;

            if (c1 + c2 > 9)
            {
                bool f = 1;
                a = (c1 + c2) - 10 + help;
                help += 1; ////////////////////
            }

            if (f == 1)
            {
                StrokaSum[i] = std::to_string(a);
            }
            else
            {
                int c = c1 + c2;
                StrokaSum[i] = std::to_string(a);
                help = 0;

            }

            bool f = 0;

        }
        for (int s = 0; s < str1.length() * 2; s++)
        {
            std::cout << StrokaSum[s];
        }
    }
    //__________________________________________________________________________________________________________________________//

    void OutStrMas(std::string sum)
    {
        for (int i = 0; sum.length(); i++)
        {
            std::cout << sum[i];
        }
    }
}