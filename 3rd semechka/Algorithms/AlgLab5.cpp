// сортировака вставками
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
    for (int j = 1; j < v.size(); j++)
    {
        int key = v[j];
        int i = j - 1;
        while ((i >= 0) and (v[i] > key))
        {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = key;

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
