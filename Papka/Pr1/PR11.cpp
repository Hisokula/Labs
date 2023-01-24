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
    sum.erase(0, sum.find_first_not_of('0'));

    std::cout << "Sum: " << sum << std::endl;

    std::string mult = esp::Mult(str1, str2);
    mult.erase(0, mult.find_first_not_of('0'));

    std::cout << "Mult: " << mult << std::endl;

}