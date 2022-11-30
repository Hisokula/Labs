#include<iostream>
#include"Func.hpp"

namespace esp
{
	int Squares(int mas[100])
	{
		int x = 0;
		for (int i = 0; i < sqrt(esp::CountMatrix()); i++)
		{
			x = x + mas[i] * mas[i];
		}

		return x;
	}
}