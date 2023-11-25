// пирамидальная сортировка
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


// Делаем макс-хип с помощью Heaping, самый большой элемент находится в корне.
// 
// Заменяем корень на последний элемент, уменьшаем размер на единицу, конец массива 
// таким образом будет отсортированна количество элементов, равное текущей итерации в Sort.
// 
// Повторяем, пока в куче больше 1 элемента.

void Heaping(std::vector<int>& v, int size, int root) 
{
    int current_root = root;

    int left_child = 2 * root + 1;
    int right_child = 2 * root + 2;

    if (left_child < size && v[left_child] > v[current_root])
    {
        current_root = left_child;
    }

    if (right_child < size && v[right_child] > v[current_root])
    {
        current_root = right_child;
    }

    if (current_root != root)
    {
        std::swap(v[root], v[current_root]);

        Heaping(v, size, current_root);
    }
}

void Sort(std::vector<int>& v)
{
    int n = v.size();

    for (int i = n / 2 - 1; i >= 0; i--)    // построение кучи
    {
        Heaping(v, n, i);
    }
    
    for (int i = n - 1; i >= 0; i--)    // сортировка с уменьшением размера кучи
    {
        std::swap(v[0], v[i]);

        Heaping(v, i, 0);
        
        std::cout << "Sorting: [" << i << "]" << std::endl;
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