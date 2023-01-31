#include <iostream>
#include <string>


/*
    Реализуйте класс, который будет выполнять шифрование и дешифрование сообщения на английском языке.
    Длина сообщения не более 30 слов. Словом называется последовательность символов до первого пробела.
    Знак препинания после символов тоже входит в слово.
    Ключом является последовательность Фибоначчи.
    В классе реализуйте методы Encode и Decode, предусмотрите возможность ВВЕСТИ И ВЫВЕСТИ КЛЮЧ(+), а также ОБРАБОТКУ ОШИБОК(+) при некорректном вводе.
*/

class Coder
{
private:

    int m_CurrentKey[30] = {};
    int m_FibKey[30] = { 1, 2 };
    std::string m_Message;
    std::string m_Words[30];
    int m_isKeyCorrect = 0;
    int WordCount = 1;


    void Fibonacci()
    {
        for (int i = 2; i < WordCount; i++)
        {
            m_FibKey[i] = m_FibKey[i - 1] + m_FibKey[i - 2];
        }
    }

    void WordsCount(std::string Message)
    {
        for (int i = 0; i < Message.length(); i++)
        {
            if (Message[i] == ' ')
            {
                WordCount++;
            }
        }
    }

public:

    Coder(std::string Message)
    {
        m_Message = Message;

        WordsCount(Message);

        Fibonacci();

        int counter = -1;

        for (int i = 0; i < WordCount; i++)
        {
            counter++;

            while (Message[counter] != ' ')
            {
                m_Words[i] += Message[counter];
                if (counter < Message.length())
                {
                    counter++;
                }
                else break;
            }
        }
    }

    void Encode()
    {
        for (int i = 0; i < WordCount; i++)
        {
            for (int j = 0; j < WordCount; j++)
            {
                if (m_CurrentKey[i] == m_FibKey[j])
                {
                    std::swap(m_Words[i], m_Words[j]);
                }
            }
        }
    }

    void Decode()
    {
        for (int i = WordCount; i > 0; i--)
        {
            for (int j = WordCount; j > 0; j--)
            {
                if (m_CurrentKey[i] == m_FibKey[j])
                {
                    std::swap(m_Words[i], m_Words[j]);
                }
            }

        }

    }

    void Output()
    {
        std::cout << std::endl;

        for (int i = 0; i < WordCount; i++)
        {
            std::cout << m_Words[i] << " ";
        }
    }

    void InputKey()
    {
        std::cout << "Input key: ";

        for (int i = 0; i < WordCount; i++)
        {
            std::cin >> m_CurrentKey[i];
        }
    }

    void OutputCurrentKey()
    {
        int flag = 0;

        std::cout << "Current key: ";

        for (int i = 0; i < WordCount; i++)
        {
            for (int j = 0; j < WordCount; j++)
            {
                if (m_CurrentKey[i] == m_FibKey[j])
                {
                    flag++;
                }
            }

        }

        if (flag == WordCount) m_isKeyCorrect = 1;


        if (m_isKeyCorrect == 1)
        {
            for (int i = 0; i < WordCount; i++)
            {
                std::cout << m_CurrentKey[i] << " ";
            }
        }
        else if (m_isKeyCorrect == 0)
        {
            std::cout << "Incorrect key!";
        }
    }
};


int main()
{
    std::string Message;
    std::getline(std::cin, Message);
    Coder Cd(Message);
    Cd.Encode();
    Cd.Decode();
    Cd.InputKey();
    Cd.OutputCurrentKey();
    Cd.Output();
}