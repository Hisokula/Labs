#include <iostream>

/*
Вам предлагается создать класс, который опишет умный динамический массив из целых чисел. Количество чисел заранее неизвестно. Ограничением служит размер доступной оперативной памяти компьютера, но использовать память все же надо рационально.

Что он должен уметь:
1.	Добавлять элемент в конец. +
2.	Выдавать текущее количество элементов. +
3.	Выдавать элемент по индексу. +
4.	Изменять элемент по индексу. +
5.	Удалять элемент по индексу. +
6.	Вставлять элемент по индексу. +

*/

class Mas
{
private:
    int m_N = 1;
    int* m_mas = new int[m_N];

public:
    Mas(int el)
    {
        m_N = 1;
        m_mas[0] = el;
    }

    void PushBack(int el)
    {
        int* ms = new int[m_N + 1];
        for (int i = 0; i < m_N; i++)
        {
            ms[i] = m_mas[i];
        }
        ms[m_N] = el;
        delete[]m_mas;
        m_mas = ms;
        m_N++;
    }

    int SizeOfMass()
    {
        return m_N;
    }

    int ElOfMass(int ind)
    {
        return m_mas[ind];
    }

    void ChangeElOfMass(int ind ,int el)
    {
        m_mas[ind] = el;
    }

    void DeleteElMass(int ind)
    {
        for (int i = ind; i < m_N - 1; i++)
        {
            m_mas[i] = m_mas[i + 1];
        }

        m_N--;
    }

    void InsertElMass(int ind, int el)
    {
        int* ms = new int[m_N + 2];

        for (int i = 0; i < ind; i++)
        {
            ms[i] = m_mas[i];
        }

        ms[ind] = el;

        for (int i = ind + 1; i < m_N + 1; i++)
        {
            ms[i] = m_mas[i - 1];
        }

        m_N++;
        delete[]m_mas;
        m_mas = ms;

    }

    void Outp()
    {
        for (int i = 0; i < m_N; i++)
        {
            std::cout << m_mas[i] << " ";
        }
    }

};

int main()
{
    Mas mass(5);
    mass.PushBack(6);
    std::cout << "Size of mass: " << mass.SizeOfMass() << std::endl;
    std::cout << "Element of mass[1]: " << mass.ElOfMass(1) << std::endl;
    mass.PushBack(7);
    mass.PushBack(8);
    std::cout << "PushBack 7&8: " << std::endl;
    mass.Outp();
    mass.InsertElMass(2, 76);
    std::cout << "Insert(2, 76): " << std::endl;
    mass.Outp();


}
