#include <iostream>

/*
1.	Базовый конструктор																		+
2.	Конструктор копирования																	+
3.	Оператор присваивания копированием														+
4.	Деструктор																				+
5.	Операторы += и +, *= и *																+
6.	Оператор ++ префиксный и постфиксный (увеличение действительной части числа на 1)		+
7.	Операторы ввода и вывода																+

*/

struct Complex
{
private:

	long long m_real = 0;
	long long m_imag = 0;

public:

	friend std::ostream& operator << (std::ostream& out, const Complex& c);
	friend std::istream& operator >> (std::istream& in, Complex& c);

	explicit Complex() : m_real(0), m_imag(0) { }

	Complex(long long r, long long i) : m_real(r), m_imag(i) { }

	Complex(long long r) : m_real(r), m_imag(0) { }


	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	~Complex() { }
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


	Complex(const Complex& other) : Complex(other.m_real, other.m_imag) {}


	Complex& operator = (const Complex& other)
	{
		Complex tmp = other;
		std::swap(this->m_real, tmp.m_real);
		std::swap(this->m_imag, tmp.m_imag);

		return *this;
	}

	Complex& operator += (const Complex& other)
	{
		long long real = this->m_real + other.m_real;
		long long imag = this->m_imag + other.m_imag;
		
		Complex tmp(real, imag);

		std::swap(this->m_real, tmp.m_real);
		std::swap(this->m_imag, tmp.m_imag);

		return *this;
	}

	Complex operator + (const Complex& other) const
	{
		Complex tmp = *this;
		tmp += other;
		return tmp;

	}

	Complex& operator *= (const Complex& other)
	{
		long long real = this->m_real * other.m_real - this->m_imag * other.m_imag;
		long long imag = this->m_imag * other.m_real + this->m_real * other.m_imag;

		Complex tmp(real, imag);

		std::swap(this->m_real, tmp.m_real);
		std::swap(this->m_imag, tmp.m_imag);

		return *this;

		// (5 + 6i)*(3 + 4i) = 15 - 24 + 20i + 18i = -9 + 38i
	}

	Complex operator * (const Complex& other) const
	{
		Complex tmp = *this;
		tmp *= other;
		return tmp;

	}

	Complex& operator ++ ()			//префикс
	{
		this->m_real++;
		return *this;

	}

	Complex operator ++ (int)		//постфикс
	{
		Complex tmp = *this;
		++this->m_real;
		return tmp;
	}
};

std::ostream& operator << (std::ostream& out, const Complex& c)
{

	if (c.m_imag < 0)
	{
		out << c.m_real << " - " << c.m_imag * (-1) << "i";
	}
	else
	{
		out << c.m_real << " + " << c.m_imag << "i";
	}

	return out;
}

std::istream& operator >> (std::istream& in, Complex& c)
{
	in >> c.m_real;
	in >> c.m_imag;

	return in;
}

int main()
{
	Complex c1(3, 4);
	Complex c2(5, 6);
	//std::cin >> c1;
	Complex c3 = c1 + c2;
	c1 *= c2;
	std::cout << "c: " << c1 << std::endl;
	Complex ppc = ++c1;
	std::cout << "++c: " << ppc << std::endl;
	std::cout << "c: " << c1 << std::endl;
	Complex cpp = c1++;
	std::cout << "c++: " << cpp << std::endl;
}