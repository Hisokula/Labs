//сортировка Шелла
#include<iostream>
#include<vector>

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
    for (int gap = v.size() / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < v.size(); i++)
        {
            int tmp = v[i];
            int j;
            for (j = i; (j >= gap) and (v[j - gap] > tmp); j -= gap)
            {
                v[j] = v[j - gap];
            }
            v[j] = tmp;
        }

        std::cout << "Gap: " << gap << std::endl;
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

    std::cout << "[Sorted]: " << std::endl;
    Outp(v);
}

// 8 
// 6 5 7 1 2 4 3 8
