#include<fstream>
#include"Func.hpp"

namespace esp
{
	int ReadMatrix(int x)
	{
		std::ifstream in("input.txt", std::ios::in);
		int el;
		int count = 0;
		int mas[10000];
		while (!in.eof())
		{
			in >> el;
			mas[count] = el;
			count++;
		}

		return mas[x];
	}
}