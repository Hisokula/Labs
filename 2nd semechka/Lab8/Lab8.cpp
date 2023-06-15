#include <iostream>

/* 
Вашей задачей будет создать шаблонный класс для реализации стека. В нем нужно предусмотреть методы:
1.	Конструктор с указанием размера стека                                                                        +
2.	Метод size                                                                                                   +
3.	Метод empty – возвращает true или false                                                                      +
4.	Метод push, чтобы положить в элемент в стек                                                                  +
5.	Метод pop, чтобы извлечь элемент из стека                                                                    +
6.	Метод top, чтобы посмотреть верхний элемент стека, но не извлекать его.                                      +

Добавьте обработку некорректных ситуаций через исключения:
1.	Невозможно выделить необходимый участок памяти под стек (std::bad_alloc).                                    +
2.	Невозможно добавить новый элемент в стек (например, std::overflow_error)                                     +
3.	Невозможно извлечь элемент из стека, так как стек пустой (например, std::out_of_range)                       +
4.	Невозможно посмотреть элемент на вершине стека, так как стек пустой (например, std::logic_error).

*/

template<typename T>
class Stack
{
private:
    size_t m_size = 0;
    T* m_stack = new T[m_size];
    int m_top = 0;
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

    void push(const T& el)
    {
        if (m_top >= m_size)
        {
            throw std::out_of_range("[Full stack!]");
        }
        else
        {
            m_stack[m_top] = el;
            m_top++;
            m_isEmpty = 0;
        }
    }

    void pop()
    {
        if (m_isEmpty)
        {
            throw std::out_of_range("[Empty stack!]");
        }
        else
        {
            m_top--;
            if (m_top == 0)
            {
                m_isEmpty = 1;
            }
        }
    }

    T top()
    {
        if (m_isEmpty == 0)
        {
            return m_stack[m_top - 1];
        }
        else
        {
            throw std::logic_error("[Top does not exist!]");
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
    try
    {
        Stack<int> s(2);
        s.push(3);
        s.push(6);
        s.pop();
        s.pop();
        s.pop();
    }

    catch (const std::out_of_range& error)
    {
        std::cerr << "You cannot delete elements because of " << error.what() << " >:(" << std::endl;
    }
    catch (const std::logic_error& error)
    {
        std::cerr << "You cannot refer to the top element because of " << error.what() << " >:(" << std::endl;
    }
}