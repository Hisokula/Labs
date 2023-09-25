#include <iostream>
#include<functional>
#include"Header.hpp"

int main()
{
	std::function<double(double)> f = [](double x) { return x * x; };
	LeftDiff LD(2, 0.001);
	RightDiff RD(2, 0.001);
	CentralDiff CD(2, 0.001);

	std::cout << LD.DiffCalc(f, 2) << std::endl;
	std::cout << RD.DiffCalc(f, 2) << std::endl;
	std::cout << CD.DiffCalc(f, 2) << std::endl;


}