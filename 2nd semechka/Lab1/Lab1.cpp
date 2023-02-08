#include <iostream>
#include <string>
#include <chrono>
#include <thread>

class AnimatedText
{
private:


    std::string m_Str = "";

    int m_time = 0;
    float m_OneSymbolTime = 0;
    int m_t = 0;

public:

    std::string m_Stroka = "";

    AnimatedText(std::string Stroka, int time)
    {
        m_Stroka = Stroka;
        m_time = time;
    }

    void Timing()
    {
        m_OneSymbolTime = (float(m_time)/m_Stroka.length());
        m_t = round(m_OneSymbolTime);
    }

    void Sleep()
    {
        std::this_thread::sleep_for(std::chrono::seconds(m_t));
    }

};


int main()
{
    std::string stroka;
    std::getline(std::cin, stroka);

    int time;
    std::cin >> time;

    AnimatedText AT(stroka, time);

    AT.Timing();

    for (int i = 0; i < stroka.length(); i++)
    {
        std::cout << AT.m_Stroka[i];
        AT.Sleep();
    }
}
