/*
На вход подаётся математическое выражение.Элементы - числа.Операции - "+ - * /".
Также есть скобочки. Окончанием выражения служит "=".
Программа должна вывести результат выражения

Пример ввода:
2+7*(3/9)-5=

Замечание:
Программа также должна делать "проверку на дурака": нет деления на 0, все скобки стоят верно (см лабу №1) и т.п.

*/

#include<iostream>
#include<vector>
#include<string>
#include<Windows.h>

std::vector<std::string> splited_str;

bool Brackets(std::string str)
{
	bool existence = 1;

	std::vector<char> stacked_brackets;

	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] == '(') or (str[i] == '[') or (str[i] == '{'))
		{
			stacked_brackets.push_back(str[i]);
		}
		else if ((str[i] == ')') or (str[i] == ']') or (str[i] == '}'))
		{
			if (stacked_brackets.empty() == 1)
			{
				existence = 0;
				break;
			}
			else
			{
				if (int(str[i] - stacked_brackets.back()) <= 2)
				{
					stacked_brackets.pop_back();
					existence = 1;
				}
			}
		}
	}

	if ((stacked_brackets.empty() == 1) and (existence == 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}


}

bool FoolCheck(std::string str)
{
	bool fool = 0;
	for (int i = 1; i < str.length() - 1; i++)
	{
		if (((str[i] == '+', '-', '*', '/', '=')) and ((str[i + 1] == '+', '-', '*', '/', '=')))
		{
			fool = 1;
		}
	}
	if ((str[0] == '+') or (str[0] == '-') or (str[0] == '*') or (str[0] == '/') or (str[0] == '='))
	{
		fool = 1;
	}
	return fool;
}

bool SignCheck(char s)
{
	if (((s == '+') or (s == '-') or (s == '*') or (s == '/') or (s == '=') or (s == '(') or (s == ')')))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void SplitTheString(std::string str)
{
	std::string tmp;
	for (int i = 0; i < str.length() - 1; i++)
	{
		if ((str[i] <= '9') and (str[i] >= '0'))
		{
			tmp += str[i];

			if (SignCheck(str[i + 1]))
			{
				splited_str.push_back(tmp);
				tmp = "";
			}
		}
		else if (SignCheck(str[i]))
		{
			std::string t = "";
			t += str[i];
			splited_str.push_back(t);
		}
	}
}

int Priority(char sign)
{
	switch (sign)
	{
	case('+'): return 1;
	case('-'): return 1;
	case('*'): return 2;
	case('/'): return 2;
	case('('): return -1;
	default: return 0;
	}
}

float Arithmetic(float a, float b, char sign)
{
	switch (sign)
	{
	case('+'): return a + b;
	case('-'): return a - b;
	case('*'): return a * b;
	case('/'): {if (b != 0) { return a / b; }};
	}
}

float Solve(std::string str)
{
	SplitTheString(str);

	std::vector<char> stacked_signs;
	std::vector<float> stacked_numbers;

	for (int i = 0; i < splited_str.size(); i++)
	{
		if (SignCheck(splited_str[i][0]))
		{

			if ((stacked_signs.size() >= 2) and (Priority(stacked_signs[i]) <= Priority(stacked_signs[i - 1])))
			{
				stacked_signs.push_back(splited_str[i][0]);
				stacked_numbers.push_back(Arithmetic(stacked_numbers[stacked_numbers.size() - 1], stacked_numbers[stacked_numbers.size()], stacked_signs[i]));
				stacked_numbers.erase(stacked_numbers.end() - 2);
				stacked_numbers.erase(stacked_numbers.end() - 2);
				stacked_signs.erase(stacked_signs.end() - 1);
			}
			else if ((stacked_signs.size() >= 2) and (Priority(stacked_signs[i]) > Priority(stacked_signs[i - 1])))
			{
				stacked_signs.push_back(splited_str[i][0]);
			}
			else if (Priority(splited_str[i][0]) == -1)
			{
				stacked_signs.push_back(splited_str[i][0]);
			}
			else if (Priority(splited_str[i][0]) == -2)
			{
				while (stacked_signs[stacked_signs.size()] != '(')
				{
					if (stacked_numbers[stacked_numbers.size()] == 0)
					{
						break;
					}
					stacked_numbers.push_back(Arithmetic(stacked_numbers[stacked_numbers.size() - 1], stacked_numbers[stacked_numbers.size()], stacked_signs[i]));
					stacked_numbers.erase(stacked_numbers.end() - 2);
					stacked_numbers.erase(stacked_numbers.end() - 2);
					stacked_signs.erase(stacked_signs.end() - 1);
				}
			}
			else
			{
				stacked_signs.push_back(splited_str[i][0]);
			}

		}
		else
		{
			stacked_numbers.push_back(std::stoi(splited_str[i]));
		}

	}
	float res = 0;
	//
	std::cout << "size: " << stacked_numbers.size() << std::endl;
	std::cout << "size: " << stacked_signs.size() << std::endl;
	//
	int size = stacked_numbers.size();
	while ( size != 1)
	{
		res = (Arithmetic(stacked_numbers[size], stacked_numbers[size - 1], stacked_signs[stacked_signs.size()]));
		stacked_signs.pop_back();
		size--;

	}

	return res;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");

	std::cout << "Введите строку: " << std::endl;

	std::string str;

	while (str != "0")
	{
		std::cin >> str;


		if (Brackets(str) and FoolCheck(str))
		{
			std::cout << Solve(str) << std::endl;

		}

		splited_str.clear();
	}
	

}





//std::cout << Brackets(str) << std::endl;
//std::cout << FoolCheck(str) << std::endl;

/*

*/
