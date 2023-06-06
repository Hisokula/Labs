#include <iostream>


class KinematicSolver
{
private:

    float m_L1, m_L2, m_L3 = 1;
    float m_alpha, m_beta, m_gamma = 0;
    int m_x, m_y = 0;

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
        m_L1 = L1;
        Solve(m_x, m_y);
        m_L3 = sqrt(m_L1 * m_L1 + m_L2 * m_L2 - 2 * m_L1 * m_L2 * cos(m_beta));

    }

    void Link2(size_t L2)
    {
        m_L2 = L2;
        Solve(m_x, m_y);
        m_L3 = sqrt(m_L1 * m_L1 + m_L2 * m_L2 - 2 * m_L1 * m_L2 * cos(m_beta));

    }

    void Print()
    {
        std::cout << "Link 1: " << m_L1 << "    Link 2: " << m_L2 << "    Link 3: " << m_L3 << " " << std::endl;
        std::cout << "Alpha: " << m_alpha << "    Beta: " << m_beta << "    Gamma: " << m_gamma << std::endl;
    }

    void Solve(int x, int y)
    {
        m_alpha = acos((m_L2 * m_L2 + m_L3 * m_L3 - m_L1 * m_L1) / (2 * m_L2 * m_L3)) * (180 / acos(-1));
        m_beta = acos((m_L1 * m_L1 + m_L3 * m_L3 - m_L2 * m_L2) / (2 * m_L1 * m_L3)) * (180 / acos(-1));
        m_gamma = 180 - m_alpha - m_beta;
    }

};

int main()
{
    KinematicSolver s1(1, 1, 1, 1);
    s1.Print();
    s1.Link1(4);
    s1.Link2(2);
    s1.Print();
}
