﻿#include <iostream>
#include <algorithm>

/*
Реализуйте шаблонный класс для описания матриц (в частном случае, векторов). Предусмотрите 3 шаблонных параметра: тип элемента, размеры матрицы N и M (N, M <= 3)
	В составе класса должны быть:
1.	Конструктор копирования													+
2.	Оператор присваивания копированием										+
3.	Оператор ввода и вывода													++
4.	Операторы +, +=, *, *=													++
5.	Оператор ++, который увеличивает все элементы матрицы на 1
6.	Метод вычисления определителя
7.	Метод или оператор для получения и изменения элемента матрицы по индексу
*/


template <typename T>
class Matrix
{
private:

	size_t m_i = 0;
	size_t m_j = 0;
	T m_mx[3][3] = {};

public:

	template <typename T>
	friend std::ostream& operator << (std::ostream& out, const Matrix<T>& mx);
	template <typename T>
	friend std::istream& operator >> (std::istream& in, Matrix<T>& mx);

	~Matrix() { };

	explicit Matrix(size_t i1, size_t j1)
	{
		m_i = i1;
		m_j = j1;
	}

	explicit Matrix(size_t i1, size_t j1, T* mx)
	{
		m_i = i1;
		m_j = j1;
		m_mx = mx;
	}

	template <typename T>
	Matrix(const Matrix& other) : Matrix(other.m_i, other.m_j, other.m_mx) { }


	Matrix& operator = (const Matrix& other)
	{
		Matrix tmp = other;

		std::swap(this->m_i, tmp.m_i);
		std::swap(this->m_j, tmp.m_j);

		for (int i = 0; i < tmp.m_i; i++)
		{
			for (int j = 0; j < tmp.m_j; j++)
			{
				tmp.m_mx[i][j] = other.m_mx[i][j];
				std::swap(tmp.m_mx[i][j], this->m_mx[i][j]);
			}
		}

		return *this;
	}

	Matrix& operator += (const Matrix& other)
	{
		if ((this->m_i != other.m_i) or (this->m_j != other.m_j))
		{
			std::cout << "Error! Matrices cannot be summed." << std::endl;
		}
		else
		{
			for (int i = 0; i < this->m_i; i++)
			{
				for (int j = 0; j < this->m_j; j++)
				{
					this->m_mx[i][j] += other.m_mx[i][j];
				}
			}
		}

		return *this;
	}

	Matrix operator + (const Matrix& other) const
	{
		if ((this->m_i != other.m_i) or (this->m_j != other.m_j))
		{
			std::cout << "Error! Matrices cannot be summed." << std::endl;
		}
		else
		{
			Matrix tmp = *this;
			tmp += other;

			return tmp;
		}
	}

	Matrix& operator *= (const Matrix& other)
	{
		if ((this->m_i != other.m_j)and(this->m_j!=other.m_i))
		{
			std::cout << "Error! Matrices cannot be multiplied." << std::endl;
		}
		else
		{
			long long el = 0;
			long long elsum = 0;
			
			this->m_j = other.m_j;



			Matrix tmp(this->m_i, this->m_j);

			for (int x = 0; x < this->m_i; x++)
			{
				for (int y = 0; y < this->m_j; y++)
				{
					for (int i = 0; i < this->m_i; i++)
					{
						for (int j = 0; j < this->m_j; j++)
						{
							el = this->m_mx[i][j] * other.m_mx[j][i];		// хьюстон, у нас проблемы
							elsum += el;
						}
						tmp.m_mx[x][y] = elsum;
						elsum = 0;
					}


				}
			}

			std::swap(tmp.m_mx, this->m_mx);
		}

		return *this;
	}

};

template <typename T>
std::ostream& operator << (std::ostream& out, const Matrix<T>& mx)
{
	for (int i = 0; i < mx.m_i; i++)
	{
		out << "( ";
		for (int j = 0; j < mx.m_j; j++)
		{
			out << mx.m_mx[i][j] << " ";
		}
		out << ")" << std::endl;
	}
	return out;
}

template <typename T>
std::istream& operator >> (std::istream& in, Matrix<T>& mx)
{
	for (int i = 0; i < mx.m_i; i++)
	{
		for (int j = 0; j < mx.m_j; j++)
		{
			in >> mx.m_mx[i][j];
		}
	}
	return in;
}

int main()
{
	Matrix<int> m(2, 2);
	std::cin >> m;
	Matrix<int> x(2, 2);
	std::cin >> x;
	Matrix<int> t = m + x;
	m *= x;
	std::cout << std::endl;
	std::cout << m << std::endl;
	std::cout << t << std::endl;
}