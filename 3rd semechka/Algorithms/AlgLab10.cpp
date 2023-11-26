// сортировка слиянием
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

void Sort(std::vector<int>& v, int ind, int size)
{
    if (size == ind)
    {
        return;
    }

    int middle = (size + ind) / 2;
    
    Sort(v, ind, middle);
    Sort(v, middle + 1, size);

    int i = ind;
    int j = middle + 1;

    std::vector<int> tmp(size - ind + 1, 0);

    for (int k = 0; k < size - ind + 1; k++)
    {
        if ((j > size) || ((i <= middle) && (v[i] < v[j])))
        {
            tmp[k] = v[i];
            i++;
        }
        else
        {
            tmp[k] = v[j];
            j++;
        }

        std::cout << "[Sorting]" << std::endl;
        Outp(v);
    }

    for (int k = 0; k < size - ind + 1; k++)
    {
        v[ind + k] = tmp[k];
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

    Sort(v, 0, v.size() - 1);

    std::cout << "Sorted: " << std::endl;
    Outp(v);

}
/*
10

12412
23
23623461
32
1
5
632
4
25
434
*/