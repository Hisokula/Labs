#include<iostream>
#include"Func.hpp"

namespace esp
{
	int Minim(int mas[100])
	{
		int mm = mas[0];
		int number = 0;
		for (int i = 0; i < sqrt(esp::CountMatrix()); i++)
		{
			if (mas[i] < mm)
			{
				mm = mas[i];
				number = i;
			}
		}
		return number;
	}
}