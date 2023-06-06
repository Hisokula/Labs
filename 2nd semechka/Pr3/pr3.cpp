#include <iostream>

class KinematicSolver
{
private:

    float m_L1, m_L2, m_L3 = 1;
    float m_alpha, m_beta, m_gamma = 0;
    float m_angle_A, m_angle_B = 0;
    int m_x, m_y = 0;
    int errormark = 0;

public:

    KinematicSolver(int x, int y, float L1, float L2)
    {
        m_x = x;
        m_y = y;
        m_L1 = L1;
        m_L2 = L2;
        m_L3 = sqrt(x * x + y * y);
        this->Solve(m_x, m_y);
    }

    void Link1(size_t L1)
    {
        if (L1 == 0)
        {
            std::cout << "Cannot be solved. Incorrect data." << std::endl;
            errormark = 0;
        }
        else
        {
            m_L1 = L1;
            Solve(m_x, m_y);
            errormark++;
        }
    }

    void Link2(size_t L2)
    {
        if (L2 == 0)
        {
            std::cout << "Cannot be solved. Incorrect data." << std::endl;
            errormark = 0;
        }
        else
        {
            m_L2 = L2;
            Solve(m_x, m_y);
            errormark++;
        }
    }

    void Print()
    {
        if (errormark >= 3)
        {
            std::cout << "Link 1: " << m_L1 << "    Link 2: " << m_L2 << "    Link 3: " << m_L3 << " " << std::endl;
            std::cout << "Alpha: " << m_alpha << "    Beta: " << m_beta << "    Gamma: " << m_gamma << std::endl;
            std::cout << "A: " << m_angle_A << "    B: " << m_angle_B << std::endl;
        }
    }

    void Solve(int x, int y)
    {
        if (abs((m_L2 * m_L2 + m_L3 * m_L3 - m_L1 * m_L1) / (2 * m_L2 * m_L3)) > 1)
        {
            std::cout << "Cannot be solved." << std::endl;
            m_alpha = -1;
            m_beta = -1;
            m_gamma = -1;
            errormark = 0;
        }
        else
        {
            m_alpha = acos((m_L2 * m_L2 + m_L3 * m_L3 - m_L1 * m_L1) / (2 * m_L2 * m_L3)) * (180 / acos(-1));
            m_beta = acos((m_L1 * m_L1 + m_L3 * m_L3 - m_L2 * m_L2) / (2 * m_L1 * m_L3)) * (180 / acos(-1));
            m_gamma = 180 - m_alpha - m_beta;
            errormark+=3;
            Angles();
        }
    }

    void Angles()
    {
        m_angle_A = m_alpha - atan((-m_y) / (-m_x));
        m_angle_B = 180 - m_beta;
    }

};

int main()
{
    KinematicSolver s1(1, 2, 1, 2);
    s1.Print();
    float a = 1;
    s1.Link1(0);
    s1.Link2(a);
    s1.Print();
}
