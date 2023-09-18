/*
На вход подаётся математическое выражение. Элементы - числа. Операции - "+ - * /".
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


float Solve(std::string str)
{
	std::vector<char> stacked_signs;
	std::vector<float> stacked_numbers;

	for (int i = 0; i < str.length(); i++)
	{
		if (i == 0)
		{
			if ((str[i] >= 48) and (str[i] <= 57))
			{
				stacked_numbers.push_back(int(str[i]));
			}
			else if (str[i] == 40, 91, 123)
			{
				stacked_signs.push_back(str[i]);
			}
			else
			{
				std::cout << "Некорректная строка." << std::endl;
			}
		}

		if ((str[1] >= 48) and (str[1] <= 57))
		{
			stacked_numbers.push_back(int(str[i]));
		}
		else if (str[i] == 40, 91, 123)
		{
			stacked_signs.push_back(str[i]);
		}
		else if (str[i] == 41, 93, 125)
		{

		}
		else
		{
			std::cout << "Некорректная строка." << std::endl;
		}
	}
	return 0;
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");

	std::cout << "Введите строку: " << std::endl;

	std::string str;
	std::cin >> str;


	if (Brackets(str) and FoolCheck(str))
	{
		SplitTheString(str);

		for (int i = 0; i < splited_str.size(); i++)
		{
			std::cout << splited_str[i] << " ";
		}




	}

	

}





//std::cout << Brackets(str) << std::endl;
//std::cout << FoolCheck(str) << std::endl;
}
