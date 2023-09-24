#include <iostream>
#include <vector>

int main()
{
    int x;
    std::cin >> x;

    std::vector<int> X;

    for (int i = 1; i < x; i++)
    {
        int k3 = 1;
        int l5 = 1;
        int m7 = 1;

        for (int k = 0; k < i; k++)
        {
            for (int l = 0; l < i; l++)
            {
                for (int m = 0; m < i; m++)
                {
                    if (k3 * l5 * m7 == i)
                    {
                        X.push_back(i);
                    }
                    m7 = m7 * 7;
                }
                l5 = l5 * 5;
                m7 = 1;
            }
            k3 = k3 * 3;
            l5 = 1;
            m7 = 1;
        }
    }


    std::cout << "size " << X.size() << std::endl;
    for (int i = 0; i < X.size(); i++)
    {
        std::cout << X[i] << std::endl;
    }
}