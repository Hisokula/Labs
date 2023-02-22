#include <iostream>

const int N = 1000;

void Copying(int mas1[N], int mas2[N])
{

}

void Outp1(int mas[1000])
{
    std::cout << "Mas1: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
}

void Outp2(int mas[1000])
{
    std::cout << "Mas2: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    int mas1[N] = {1, 2, 3, 4, 5};
    int mas2[N] = {2, 7, 4};
    
    Outp1(mas1);
    Outp2(mas2);



}