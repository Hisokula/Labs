#include <iostream>
#include<functional>
#include"Header.hpp"

int main()
{
	std::function<double(double)> f = [](double x) { return x * x; }; // функция для проверки - x^2

	//создание объектов наследных классов
	LeftDiff LD(2, 0.001);
	RightDiff RD(2, 0.001);
	CentralDiff CD(2, 0.001);

	//вывод результата дифференцирования и точности
	std::cout << "Left diff: " << LD.DiffCalc(f, 2) << " Accuracy: " << LD.GetAccuracy() << std::endl;
	std::cout << "Right diff: " << RD.DiffCalc(f, 2) << " Accuracy: " << RD.GetAccuracy() << std::endl;
	std::cout << "Central diff: " << CD.DiffCalc(f, 2) << " Accuracy: " << CD.GetAccuracy() << std::endl;

}