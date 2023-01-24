#include <iostream>
#include<string>

const std::string str1;
const std::string str2;



namespace esp
{
    void Output(std::string str1, std::string str2)
    {
        for (int i = 1; i < str1.length(); i++)
        {
            std::cout << str1 << std::endl;
            std::cout << str2 << std::endl;
        }

    }

    void FlagSort(std::string str1, std::string str2)
    {
        if (str1.length() < str2.length())
        {
            std::string tmp = str1;
            str1 = str2;
            str2 = tmp;
        }
        if (str1.length() != str2.length())
        {
            while (str1.length() != str2.length())
            {
                str2 = "0" + str2;
            }
        }
        //Output(str1, str2);
    }

    //__________________________________________________________________________________________________________________________//

    void Sum(std::string str1, std::string str2, std::string sum)
    {
        std::string StrokaSum[2000];

        bool f = 0;
        int help = 0;

        for (int i = 0; i < str1.length(); i++)
        {
            int c1 = int(str1[str1.length() - i]);
            int c2 = int(str2[str1.length() - i]);

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
                StrokaSum[i] = std::to_string(c);
                help = 0;

            }

            bool f = 0;

        }
        std::cout << sum << "yee";
        for (int s = 0; s < 2000; s++)
        {
            sum = StrokaSum[s];
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

int main()
{
    std::string str1;
    std::string str2;

    std::string sum;
    for (int s = 0; s < 2000; s++)
    {
        sum[s] = 0;
    }

    std::cin >> str1;
    std::cin >> str2;

    esp::FlagSort(str1, str2);

    esp::Sum(str1, str2, sum);

    //esp::Output(str1, str2);
    for (int i = 0; sum.length(); i++)
    {
        std::cout << sum[i];
    }

    //OutStrMas(sum);
}