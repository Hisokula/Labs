#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

class AnimatedText
{
private:

    int m_time = 0;
    float m_OneSymbolTime = 0;

public:

    std::string m_Stroka = "";

    AnimatedText(const std::string& Stroka, int time)
    {
        m_Stroka = Stroka;
        m_time = time;
    }

    void Timing()
    {
        m_OneSymbolTime = (float(m_time) * 1000000 / m_Stroka.length());
    }

    void Sleep() const
    {
        std::this_thread::sleep_for(std::chrono::microseconds(int(m_OneSymbolTime)));
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

    AnimatedText SfmlAT(stroka, time);
    
    sf::RenderWindow window(sf::VideoMode(500, 500), "AimatedTest");

    sf::Text TEXT;
    sf::Font FONT;

    FONT.loadFromFile("times.ttf");
    TEXT.setFont(FONT);
    TEXT.setFillColor(sf::Color::Cyan);
    TEXT.setStyle(sf::Text::Bold);
    TEXT.setCharacterSize(35);
    TEXT.setString(SfmlAT.m_Stroka);
    SfmlAT.Timing();

    std::string StrHelper = "";

    int k = 0;

    while (window.isOpen())
    {
        window.setFramerateLimit(20);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        
        /*
        for (int i = 0; i < SfmlAT.m_Stroka.length(); i++)
        {
            StrHelper += SfmlAT.m_Stroka[i];
            TEXT.setString(StrHelper);
            window.draw(TEXT);
            SfmlAT.Sleep();
            window.display();
            window.clear(sf::Color::Black);
        }
        */

        if (k < SfmlAT.m_Stroka.length())
        {
            StrHelper += SfmlAT.m_Stroka[k];
            TEXT.setString(StrHelper);
            window.draw(TEXT);
            SfmlAT.Sleep();
            window.display();
            window.clear(sf::Color::Black);
        }

        k++;

        //SfmlAT.Sleep();
        //window.display();
        //window.clear(sf::Color::Black);

    }
    
    
    for (int i = 0; i < stroka.length(); i++)
    {
        std::cout << AT.m_Stroka[i];
        AT.Sleep();
    }
}

// Hello, world!