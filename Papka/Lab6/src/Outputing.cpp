#include<fstream>
#include"Func.hpp"

namespace esp
{
	void Outp(int mas[100][100])
	{
		std::ifstream in("input.txt", std::ios::in);
		std::ofstream out("output.txt", std::ios::out);

		for (int i = 0; i < sqrt(esp::CountMatrix()); i++)
		{
			for (int j = 0; j < sqrt(esp::CountMatrix()); j++)
			{
				out << mas[i][j] << " ";
			}
			out << std::endl;
		}
	}
}