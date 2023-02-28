#include <iostream>

const int N = 1000;

void Copying(int* mas1, int* mas2)
{
    std::cout << "Copying... " << std::endl;

    size_t* tmp1 = reinterpret_cast<size_t*>(mas1);
    size_t* tmp2 = reinterpret_cast<size_t*>(mas2);

    for (int i = 0; i < N / 2; i++)
    {
        *tmp1 = *tmp2;
        tmp1++;
        tmp2++;
    }

    char* tmp1_2 = reinterpret_cast<char*>(mas1);
    char* tmp2_2 = reinterpret_cast<char*>(mas2);

    for (int i = N - (N / 2); i < N; i++)
    {
        *tmp1_2 = *tmp2_2;
        tmp1_2++;
        tmp2_2++;
    }
    
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
    int mas1[N] = { 1, 2, 3, 4, 5 };
    int mas2[N] = { 2, 7, 4 };

    Outp1(mas1);
    Outp2(mas2);

    Copying(mas1, mas2);

    Outp1(mas1);
    Outp2(mas2);
}