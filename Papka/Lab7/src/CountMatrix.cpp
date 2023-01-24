#include<fstream>
#include"Func.hpp"

namespace esp
{
	int CountMatrix()
	{
		std::ifstream in("input.txt", std::ios::in);
		int el;
		int count = 0;
		while (!in.eof())
		{
			in >> el;
			count++;
		}

		return count;
	}
}