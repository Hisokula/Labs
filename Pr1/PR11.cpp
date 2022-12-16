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

    std::string sum = esp::Sum(str1, str2);

    std::cout << "Sum: " << sum << std::endl;

    std::cout << "Mult: " << esp::Mult(str1, str2) << std::endl;

}