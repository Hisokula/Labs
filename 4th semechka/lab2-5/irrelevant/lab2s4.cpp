#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

/*
В лабораторных работах №2-10 исходный граф вводится с помощью матрицы смежности, записанной в некоторый файл с данными. 
Программа читает информацию из файла и реализует соответствующий алгоритм. Вывод результата записывается в итоговый файл.

Поиск в ширину
2.	Найти в заданном графе кратчайшие пути из заданной вершины до всех остальных вершин с помощью поиска в ширину
3.	Найти в заданном графе количество и состав компонент связности с помощью поиска в ширину.

Поиск в глубину
4.	Найти в заданном графе количество и состав компонент связности с помощью поиска в глубину
5.	Найти в заданном орграфе количество и состав сильно связных компонент с помощью поиска в глубину.
*/

std::vector<int> DFS(std::vector<std::vector<int>>& graph, int v, std::vector<bool> visited)
{
    std::vector<int> stack;
    stack.push_back(v);
    visited[v] = 1;

    while (stack.empty() != 1)
    {
        v = stack.front();
        stack.pop_back();

        for (int i = 0; i < graph.size(); i++)
        {
            if (visited[i] != 1)
            {
                visited[i] = true;
                stack.push_back(i);
            }
        }
    }
    return stack;
}

std::vector<int> BFS(std::vector<std::vector<int>>& graph, int v, std::vector<bool> used)
{
    std::vector<int> stack;
    return stack;
}

int main()
{
    std::vector<std::vector<int>> graph;
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);
    std::string str, tmp;

    std::getline(fin, str);
    std::stringstream s(str);

    int i = 0;

    while (s >> tmp)
    {

        graph[i].push_back(stoi(tmp));
        i++;
    }


}

/*
    while (!fin.eof())
    {

    }


    for (auto& item : graph)
    {
        std::cout << item.first << " " << item.second << std::endl;
    }

    for (auto& item : graph)
    {
        std::cout << item.first << " " << item.second << std::endl;
    }

        for (int i = 0; i < graph.size(); i++)
    {
        std::cout << graph[i]. << " _ " << graph[i] << std::endl;
    }
*/