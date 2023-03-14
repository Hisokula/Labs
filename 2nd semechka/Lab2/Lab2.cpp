#include <iostream>

/*
1.	Базовый конструктор                                  +
2.	Конструктор копирования (правило 3-х)
3.	Оператор присваивания копированием (правило 3-х)
4.	Деструктор (правило 3-х)                             +
5.	Операторы + и +=
6.	Оператор [] – чтение и изменение элемента
7.	Операторы <, >, ==
8.	Операторы ввода и вывода в поток
9.	Метод find – поиск первого вхождения символа в строку слева
10.	 Метод length – длина строки
11.	 Метод c_str – получить массив char
12.	 Метод at для получения доступа (чтение и изменение) к элементу строки с проверкой на выход за пределы строки
*/

struct String
{
private:
	size_t m_size = 0;
	char* m_str = nullptr;

public:

	String() = default;

	String(int c, rsize_t size) = delete;

	String(const char* str) : m_size(strlen(str) + 1), m_str(new char[m_size])
	{
		std::copy(str, str + m_size, m_str);
	}

	String(char c, size_t size) : m_size(size), m_str(new char(size))
	{
		std::copy(m_str, m_str + m_size, c);
	}

	~String()
	{
		if (m_str != nullptr)
			delete[] m_str;
	}




	size_t Size() const
	{
		return m_size;
	}

	void Print() const
	{
		for (int i = 0; i < m_size; i++)
			std::cout << m_str[i];
		std::cout << std::endl;
	}

};

int main()
{
	String s1("Hello, world!");
	s1.Print();
	String s2('a', 3);
	s2.Print();
}