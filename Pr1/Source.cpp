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
        if ((*str1).length() > (*str2).length())
        {
            while ((*str2).length() < (*str1).length())
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

        bool flag = 0;
        int help = 0;

        for (int i = 1; i < str1.length() + 1; i++)
        {
            int c1 = int(str1[str1.length() - i]) - 48;
            int c2 = int(str2[str2.length() - i]) - 48;

            int a = 0;

            if (c1 + c2 + help > 9)
            {
                flag = 1;
                a = (c1 + c2) - 10 + help;
                help = 0;
            }

            if (flag == 1)
            {
                StrokaSum[str1.length() - i + 1] = char(a + 48);
                help += 1;
            }
            else if (flag == 0)
            {
                int c = c1 + c2;
                StrokaSum[str1.length() - i + 1] = char(c + 48) + help;
                help = 0;

            }

            flag = 0;

        }

        if (help != 0)
        {
            StrokaSum[0] = char(int(StrokaSum[0]) + help);
        }

        return StrokaSum;
    }


    std::string Mult(std::string str1, std::string str2)
    {
        std::string Stroka = str1 + str2;

        for (int u = 0; u < str1.length() + str2.length(); u++)
        {
            Stroka[u] = '0';
        }

        std::string Result = Stroka;

        std::string Emptyness = Result;


        for (int i = 0; i < str1.length(); i++)
        {
            for (int j = 0; j < str2.length(); j++)
            {
                int el1 = str1[str1.length() - i - 1] - 48;
                int el2 = str2[str2.length() - j - 1] - 48;

                int mult = el1 * el2;

                Stroka[Stroka.length() - j - i - 1] = char(mult % 10 + 48);
                Stroka[Stroka.length() - j - i - 2] = char(mult / 10 + 48);


                while (Result.length() > Stroka.length())
                {
                    Stroka = '0' + Stroka;
                }
                Result = Sum(Result, Stroka);

                Stroka = Emptyness;
            }

        }

        return Result;
    }

}