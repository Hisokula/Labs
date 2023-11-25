// поразрядная сортировка
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>

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
    std::vector<std::vector<int>> bins(base, std::vector<int>());
    std::queue<int> q;

    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            int digit = (v[j] / static_cast<int>(pow(base, i))) % base; //??????????????
            bins[digit].push_back(v[j]);
        }

        v.clear();

        for (const auto& q : bins)
        {
            v.insert(v.end(), q.begin(), q.end());
        }

        std::cout << "Iteration " << i + 1 << ": " << std::endl;
        Outp(v);
        
        bins.assign(base, std::vector<int>());
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