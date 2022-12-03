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

    void FlagSort(std::string* str1, std::string* str2)                             
    {
        if ((*str1).length() < (*str2).length())
        {
            std::swap(*str1, *str2);
        }
        if ((*str1).length() != (*str2).length())
        {
            while ((*str2).length() != (*str1).length())
            {
                *str2 = "0" + *str2;
            }
        }
    }


    std::string Sum(std::string str1, std::string str2)
    {
        std::string StrokaSum = "0" + str1;
        for (int i = 0; i < StrokaSum.length(); i++)
        {
            StrokaSum[i] = '0';
        }

        bool f = 0;
        int help = 0;

        for (int i = 1; i < str1.length() + 1; i++)
        {
            int c1 = int(str1[str1.length() - i]) - 48;
            int c2 = int(str2[str2.length() - i]) - 48;

            std::cout << "-> " << c1 << "\t" << c2 << std::endl;

            int a = 0;

            if (c1 + c2 + help > 9)
            {
                f = 1;
                a = (c1 + c2 + help) % 10;
                help = (c1 + c2 + help) / 10;

            }

            if (f == 1)
            {
                StrokaSum[str1.length() - i + 1] = char(a) + 48;

            }
            else
            {
                int c = c1 + c2 + help;
                help = 0;
                StrokaSum[str1.length() - i + 1] = char(c) + 48;

 
            }

            f = 0;

        }

        std::cout << StrokaSum << std::endl;
        return StrokaSum;

    }

    void Mult(std::string str1, std::string str2)
    {
        std::string StrokaMult = str1 + str1;

        for (int i = 0; i < str1.length() * 2; i++)
        {
            StrokaMult[i] = '0';
        }

        std::string Step = StrokaMult;

        bool flag = 0;
        int helper = 0;

        for (int i = 0; i < str1.length(); i++)
        {
            for (int j = 0; j < str2.length(); j++)
            {
                int c1 = int(str1[str1.length() - i - 1]) - 48;
                int c2 = int(str2[str2.length() - j - 1]) - 48;

                int num = 0;

                if (c1 * c2 + helper > 9)
                {
                    flag = 1;
                    num = (c1 * c2) % 10 + helper;
                    helper += 1;
                }

                if (flag == 1)
                {
                    Step[str1.length() - i + 1] = char(num + 48);
                }
                else
                {
                    int c = c1 * c2;
                    Step[str1.length() - i + 1] = char(c + 48);
                    helper = helper % 10;
                }

                FlagSort(&StrokaMult, &Step);
                StrokaMult = Sum(StrokaMult, Step);
                StrokaMult.erase(StrokaMult.find("0"), 1);

                flag = 0;
            }
        }
        std::cout << StrokaMult << std::endl;
    }

}