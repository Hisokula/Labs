#include<iostream>
#include<fstream>
#include"Func.hpp"

int main()
{
	int matrix[10000];
	int mas[100][100];
	
	esp::Inp(matrix, mas);

	esp::Process(mas);
	
	esp::Outp(mas);
		
}