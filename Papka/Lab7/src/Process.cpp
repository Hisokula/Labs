#include<fstream>
#include<iostream>
#include"Func.hpp"

namespace esp
{
	void Process(int mas[100][100])
	{
		bool T = esp::Test(mas);
		if (T == true)
		{

			int ms[100];
			for (int i = 0; i < sqrt(esp::CountMatrix()); i++)
			{
				for (int t = 0; t < sqrt(esp::CountMatrix()); t++)
				{
					ms[t] = mas[t][i];
				}
				int sq = esp::Squares(ms);

				mas[esp::Minim(ms)][i] = sq;

			}
		}
	}
}