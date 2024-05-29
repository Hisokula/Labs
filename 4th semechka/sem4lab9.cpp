// алгоритм Беллмана-Форда поиска кратчайших путей из одной вершины

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;


struct Edge
{
    int src, dest, weight;
};


vector<vector<int>> readAdjacencyMatrix(const string& filePath)
{
    ifstream file(filePath);
    vector<vector<int>> matrix;
    string line;

    while (getline(file, line))
    {
        vector<int> row;
        int value;
        istringstream iss(line);
        while (iss >> value)
        {
            row.push_back(value);
        }
        matrix.push_back(row);
    }

    file.close();
    return matrix;
}


vector<Edge> matrixToEdgeList(const vector<vector<int>>& matrix)
{
    vector<Edge> edges;
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] != 0)  // Если вес ребра ненулевой
            {
                edges.push_back({ i, j, matrix[i][j] });
            }
        }
    }
    return edges;
}



vector<int> bellmanFord(int n, const vector<Edge>& edges, int src)
{
    vector<int> dist(n, numeric_limits<int>::max());  // Вектор для хранения кратчайшего расстояния до каждой вершины
    dist[src] = 0;  // Расстояние от источника до самого себя равно 0

    // Повторяем (n-1) раз, где n - количество вершин
    for (int i = 1; i <= n - 1; ++i)
    {
        // Проходим по каждому ребру и обновляем расстояния
        for (const auto& edge : edges)
        {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;
            if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Проверка на наличие циклов отрицательного веса
    for (const auto& edge : edges)
    {
        int u = edge.src;
        int v = edge.dest;
        int weight = edge.weight;
        if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v])
        {
            throw runtime_error("Graph contains a negative weight cycle");
        }
    }

    return dist;
}

int main()
{
    string filePath = "graph.txt";
    vector<vector<int>> matrix = readAdjacencyMatrix(filePath);
    vector<Edge> edges = matrixToEdgeList(matrix);

    int n = matrix.size();  // Количество вершин в графе
    int src = 0;  // Начальная вершина (источник)
    
    vector<int> distances = bellmanFord(n, edges, src);


    cout << "Vertex        Distance from Source\n";
    for (int i = 0; i < distances.size(); i++)
    {
        cout << i << "              " << distances[i] << "\n";
    }

}
