#include<iostream>

/*
Реализуйте спецификацию шаблона для вектора из булевских значений. Помните, что на каждое значение должен быть потрачен только 1 бит памяти.
Предусмотрите следующие операции :
1.	Метод добавления в конец вектора
2.	Метод и оператор получения и изменения значения по индексу
3.	Метод size															+
4.	Метод insert и erase

Продемонстрируйте работу с классом.

mas[0]						mas[1]								...
|1||2||3||4||5||6||7||8|	|9||10||11||12||13||14||15||16|		...

*/

class VecBool
{
private:

	size_t m_n = 1;
	bool* m_vec = new bool[m_n];

public:

	VecBool(bool* vec)
	{
		m_vec = vec;
		m_n = sizeof(m_vec);

		size_t key = 0;

		size_t c = m_n / 8 + 1;

		for (int i = 0; i < c; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				key = key | m_vec[j];					//воооооот с этим разберись
				key = key << 1;
			}

			m_vec[i] = key;
		}

		std::cout << "Construct" << std::endl;
	}

	VecBool(const VecBool& other) : VecBool(other.m_vec) { }

	void PushBack(bool el)
	{
		bool* v = new bool[m_n + 1];
		for (int i = 0; i < m_n; i++)
		{

			v[i] = this->m_vec[i];
		}
		this->m_n++;
		VecBool other(v);
		other.m_vec[this->m_n - 1] = el;
		this->m_vec = other.m_vec;

		delete[]v;
	}

	size_t SizeOfVec()
	{
		return sizeof(this->m_vec);
	}

	size_t Size()
	{
		return this->m_n;
	}

	~VecBool()
	{
		//delete[]m_vec;
		std::cout << "Destruct" << std::endl;
	}
};

int main()
{
	bool mas[3] = { 1, 0, 1 };
	std::cout << sizeof(mas) << std::endl;
	VecBool vc(mas);
	vc.PushBack(0);
	std::cout << vc.SizeOfVec() << std::endl;
}