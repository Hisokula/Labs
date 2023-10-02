// сортировака выбором
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

void Sort(std::vector<int>& v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            std::swap(v[i], v[min]);
        }
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

// 8 
// 6 5 7 1 2 4 3 8