﻿#include <iostream>

/* 
Вашей задачей будет создать шаблонный класс для реализации стека. В нем нужно предусмотреть методы:
1.	Конструктор с указанием размера стека                                                                        +
2.	Метод size                                                                                                   +
3.	Метод empty – возвращает true или false                                                                      +
4.	Метод push, чтобы положить в элемент в стек                                                                  +
5.	Метод pop, чтобы извлечь элемент из стека                                                                    +
6.	Метод top, чтобы посмотреть верхний элемент стека, но не извлекать его.                                      +

Добавьте обработку некорректных ситуаций через исключения:
1.	Невозможно выделить необходимый участок памяти под стек (std::bad_alloc).                                    ?
2.	Невозможно добавить новый элемент в стек (например, std::overflow_error)
3.	Невозможно извлечь элемент из стека, так как стек пустой (например, std::out_of_range)
4.	Невозможно посмотреть элемент на вершине стека, так как стек пустой (например, std::logic_error).

*/

template<typename T>
class Stack
{
private:
    size_t m_size = 0;
    T* m_stack = new T[m_size];
    int m_top = -1;
    bool m_isEmpty = 1;

public:
    Stack(size_t size)
    {
        m_size = size;
        delete[] m_stack;
        m_stack = new T[size];
        std::cout << "[construction]" << std::endl;
    }

    size_t size()
    {
        return m_size;
    }

    bool empty()
    {
        return m_isEmpty;
    }

    void push(T el)
    {
        if (m_top == m_size)
        {
            std::cout << "[Full stack]" << std::endl;
        }
        else
        {
            m_top++;
            m_stack[m_top] = el;
            m_isEmpty = 0;
        }
    }

    void pop()
    {
        if (m_isEmpty)
        {
            std::cout << "[Empty stack]" << std::endl;
        }
        else
        {
            m_top--;
            if (m_top == -1)
            {
                m_isEmpty = 1;
            }
        }
    }

    T top()
    {
        if (m_top != -1)
        {
            return m_stack[m_top];
        }
        else
        {
            std::cout << "[Empty stack]" << std::endl;
            //return reinterpret_cast<T> (nullptr);
        }
    }

    ~Stack()
    {
        delete[] m_stack;
        std::cout << "[destruction]" << std::endl;
    }
};

int main()
{
    Stack<int> s(5);
    s.push(3);
    s.push(6);
    s.push(1);
    s.pop();
    s.pop();
    s.pop();
    std::cout << s.top() << std::endl; //консоль шалит и выводит какое-то неведомое число при выполнение второго условия. удивительно.
}