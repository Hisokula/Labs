//алгоритм Крускала нахождения минимального покрывающего дерева

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

// структура для хранения ребра графа
struct Edge
{
    int src, dest, weight;
};

// функция для чтения матрицы смежности из файла
vector<vector<int>> readAdjacencyMatrix(const string& filePath)
{
    ifstream file(filePath);
    vector<vector<int>> matrix;
    string line;

    // читаем файл построчно
    while (getline(file, line))
    {
        vector<int> row;
        int value;
        istringstream iss(line);  // создаём строковой поток из строки, читаем все числа из строки и добавляем их в строку матрицы
        while (iss >> value)
        {
            row.push_back(value);
        }
        matrix.push_back(row);  // добавляем строку в матрицу
    }

    file.close();
    return matrix;
}

// класс для объединения и поиска
class UnionFind
{
private:

    vector<int> parent, rank;  // векторы для хранения родителей и рангов

public:

    UnionFind(int n)
    {
        parent.resize(n);  // инициализация вектора родителей
        rank.resize(n, 0);  // инициализация рангов всех элементов нулями
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;  // каждый элемент сам себе родитель
        }
    }

    // функция для нахождения корня элемента с использованием сжатия пути
    int find(int u)
    {
        if (u != parent[u])
        {
            parent[u] = find(parent[u]);  // cжимаем путь
        }
        return parent[u];
    }

    // функция для объединения двух множеств
    void unionSets(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV)
        {
            // объединяем деревья по рангу
            if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV])
            {
                parent[rootU] = rootV;
            }
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// функция для преобразования матрицы смежности в список ребер
vector<Edge> matrixToEdgeList(const vector<vector<int>>& matrix)
{
    vector<Edge> edges;
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (matrix[i][j] != 0)
            {
                edges.push_back({ i, j, matrix[i][j] });
            }
        }
    }
    return edges;
}

pair<vector<Edge>, int> kruskal(int n, vector<Edge>& edges)
{
    // сортируем ребра по весу
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.weight < b.weight; });

    UnionFind uf(n);  // создаем объект Union-Find для обработки объединений и поисков
    vector<Edge> mst;  // список ребер минимального остовного дерева
    int mst_cost = 0;  // общая стоимость минимального дерева

    // проходим по всем ребрам
    for (const auto& edge : edges)
    {
        // если вершины ребра принадлежат разным компонентам
        if (uf.find(edge.src) != uf.find(edge.dest))
        {
            uf.unionSets(edge.src, edge.dest);  // объединяем компоненты
            mst.push_back(edge);  // добавляем ребро в mst
            mst_cost += edge.weight;  // увеличиваем стоимость mst
        }
    }
    return { mst, mst_cost };
}

int main()
{
    string filePath = "graph.txt";

    vector<vector<int>> matrix = readAdjacencyMatrix(filePath);
    vector<Edge> edges = matrixToEdgeList(matrix);

    int n = matrix.size();


    auto result = kruskal(n, edges);

    vector<Edge> mst = result.first;  // список ребер mst
    int mst_cost = result.second;  // общая стоимость mst


    cout << "Edges in the minimum spanning tree:" << endl;
    for (const auto& edge : mst)
    {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }

    cout << "Total cost of MST: " << mst_cost << endl;
}
