// поразрядная сортировка
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>

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
    int max_el = *max_element(v.begin(), v.end());
    std::string str_max = std::to_string(max_el);
    int max = str_max.length();

    int base = 10;
    std::vector<std::vector<int>> bins;

    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            int digit = (v[j] / int(pow(base, i))) % base; //??????????????
            bins[digit].push_back(j);
        }

        // вот тут херня, разберись
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