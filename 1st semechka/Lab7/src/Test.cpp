#include<fstream>
#include"Func.hpp"

namespace esp
{
	bool Test(int mas[100][100])
	{
		bool F1 = 1;
		bool F2 = 0;
		for (int p = 0; p < sqrt(esp::CountMatrix()); p++)
		{
			if (mas[p][p] < 0)
			{
				F1 = 0;
				break;
			}
			if ((mas[p][p] == 3) || (mas[p][p] == 5))
			{
				F2 = 1;
			}
		}
		if (F1 == F2 == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}