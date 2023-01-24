#include <iostream>
#include <string>


/*
    Реализуйте класс, который будет выполнять шифрование и дешифрование сообщения на английском языке.
    Длина сообщения не более 30 слов. Словом называется последовательность символов до первого пробела.
    Знак препинания после символов тоже входит в слово.
    Ключом является последовательность Фибоначчи.

    В классе реализуйте методы Encode и Decode, предусмотрите возможность ВВЕСТИ И ВЫВЕСТИ КЛЮЧ, а также ОБРАБОТКУ ОШИБОК при некорректном вводе.

*/

class Coder
{
private:

    int m_CurrentKey[30] = {};
    int m_FibKey[30] = {};
    std::string m_Message;
    std::string m_Words[30];
    bool m_isKeyCorrect;

public:

    int WordCount = 1;

    Coder(std::string Message)
    {
        m_Message = Message;

        WordsCount(Message);

        for (int i = 0; i < WordCount; i++)
        {
            for (int j = 0; j < Message.length(); j++)
            {
                if (Message[j] != ' ')
                {
                    m_Words[i] += Message[j];
                }
                else if (Message[i] == ' ')
                {
                    break;
                }
            }
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

    void Encode()
    {

    }

    void Decode()
    {

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
        std::cout << "Current key: ";
        for (int i = 0; i < WordCount; i++)
        {
            std::cout << m_CurrentKey[i] << " ";
        }

    }

};


int main()
{
    std::string Message;
    std::getline(std::cin, Message);
    Coder Cd(Message);
    Cd.InputKey();
    Cd.OutputCurrentKey();
}