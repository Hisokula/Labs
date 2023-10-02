// сортировка прочёсыыванием
#include <iostream>
#include <vector>

void Outp(std::vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void Sort(std::vector<int> &v)
{
    int step = v.size() - 1;

    while (step >= 1)
    {
        for (int i = 0; i < v.size() - step; i++)
        {
            if (v[i] > v[i + step])
            {
                std::swap(v[i], v[i + step]);
            }
        }
        step--;

        std::cout << "Sorting:" << std::endl;
        Outp(v);
    }
}

int main()
{
    int size = 0;

    std::vector<int> v;

    std::cout << "Input size:" << std::endl;
    std::cin >> size;
    std::cout << "Input elements:" << std::endl;
    
    for (int i = 0; i < size; i++)
    {
        int el = 0;
        std::cin >> el;
        v.push_back(el);
    }

    Sort(v);

    std::cout << "Sorted: " << std::endl;
    Outp(v);

}
