#include <iostream>

class Triangle
{
private:
        double m_FirstSide = 0;
        double m_SecondSide = 0;
        double m_ThirdSide = 0;
        double m_Area = 0;

        bool Flag(double a, double b, double c)
        {
            if ((a > 0) and (b > 0) and (c > 0) &&
                a + b > c && a + c > b && b + c > a)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        double Area(double a, double b, double c)
        {
            if (Flag(a, b, c) == true)
            {
                double p = (a + b + c) / 2;
                double area = sqrt(p * (p - a) * (p - b) * (p - c));
                std::cout << area << std::endl;
                return area;
            }
            else
            {
                std::cout << "Area error! " << std::endl;
                return m_Area;
            }
        }
public:
    Triangle (double a,double b, double c)
    {
        m_FirstSide = a;
        m_SecondSide = b;
        m_ThirdSide = c;
        m_Area = Area(a, b, c);
    }
    ~Triangle()
    {
        std::cout << "It works!";
    }
    
    //
    void OutpArea()
    {
        if (m_Area == 0)
            std::cout << "Area does not exist..." << std::endl;
        else
            std::cout << "Area equals: " << m_Area << std::endl;
    }
};

int main()
{
    double a, b, c = 0;
    std::cout << "Enter statements:" << std::endl;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    Triangle sus(a, b, c);
    sus.OutpArea();
}
