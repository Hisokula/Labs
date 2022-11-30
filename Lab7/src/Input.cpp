#include<fstream>
#include"Func.hpp"

namespace esp
{
	void Inp(int matrix[10000], int mas[100][100])
	{
		int count = 0;

		for (int i = 0; i < esp::CountMatrix(); i++)
		{
			matrix[i] = esp::ReadMatrix(i);
		}

		for (int p = 0; p < sqrt(esp::CountMatrix()); p++)
		{
			for (int k = 0; k < sqrt(esp::CountMatrix()); k++)
			{
				mas[p][k] = matrix[count];
				count++;
			}
		}
	}
}
