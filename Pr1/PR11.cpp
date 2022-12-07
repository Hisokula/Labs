#include <iostream>
#include<string>
#include"Header.hpp"

int main()
{
    std::string str1;
    std::string str2;

    std::cin >> str1;
    std::cin >> str2;

    esp::FlagSort(&str1, &str2);

    std::cout << "Sum: " << esp::Sum(str1, str2) << std::endl;

    std::cout << "Mult: " << esp::Mult(str1, str2) << std::endl;

    //esp::Output(str1, str2);
}