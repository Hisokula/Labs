#include <iostream>

const int N = 999;

template<typename T>
void Copying(T* mas1, T* mas2)
{
    std::cout << "Copying... " << std::endl;

    size_t* tmp1 = reinterpret_cast<size_t*>(mas1);
    size_t* tmp2 = reinterpret_cast<size_t*>(mas2);

    for (int i = 0; i < N / (sizeof(*tmp1) / sizeof(T)); i++)
    {
        *tmp1 = *tmp2;
        tmp1++;
        tmp2++;
    }

    char* tmp1_2 = reinterpret_cast<char*>(mas1) + N - (N % (sizeof(*tmp1) / sizeof(T)));
    char* tmp2_2 = reinterpret_cast<char*>(mas2) + N - (N % (sizeof(*tmp1) / sizeof(T)));

    for (int i = N - (N % (sizeof(*tmp1) / sizeof(T))); i < N; i++)
    {
        *tmp1_2 = *tmp2_2;
        tmp1_2++;
        tmp2_2++;
    }

}

template<typename T>
void Outp1(const T mas[1000])
{
    std::cout << "Mas1: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void Outp2(const T mas[1000])
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
