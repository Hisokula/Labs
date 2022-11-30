#include <iostream>
#include<string>
#include"Header.hpp"

int main()
{
    std::string str1;
    std::string str2;
   
    std::string sum;

    std::cin >> str1;
    std::cin >> str2;

    esp::FlagSort(&str1, &str2);

    //esp::Sum(str1, str2, sum);                <<<<<<<<<<<-----------------

    esp::Output(str1, str2);
    //OutStrMas(sum);
}