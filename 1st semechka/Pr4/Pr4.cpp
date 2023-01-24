#include <iostream>
const int N = 5;

//целые числа от 0 до 17
// 17 = 0b00010001

/*
Порядок выполнения :
1.	Определите минимальное количество бит на число(5). Если получается так, что в 1 байт вы можете записать 2.5 числа(???), например, то задействуйте 2 байта.
2.	Разработайте операции добавления и извлечения чисел.
    char a = 0b00000000;
    char b = 0b00011111;
    char c = 0b00010001;
*/

int main()
{
	int pack[N] = {0, 12, 3, 17, 7};
	unsigned long long key = 0;



	for (int i = 0; i < std::size(pack); i++)
	{
		key = key | pack[i];
		if (i < (std::size(pack) - 1))
		{
			key = key << N;
		}
	}

	for (int j = std::size(pack) - 1; j >= 0; j--)
	{
		int unpacked = (key << (64 - N) >> (64 - N));
		key = key >> 5;
		std::cout << unpacked << ' ';
	}

}