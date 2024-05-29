// алгоритм Дейкстры поиска кратчайших путей из одной вершины

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

// Структура для хранения ребра графа
struct Edge
{
    int src, dest, weight;
};

// Функция для чтения матрицы смежности из файла
vector<vector<int>> readAdjacencyMatrix(const string& filePath)
{
    ifstream file(filePath);  // Открываем файл
    vector<vector<int>> matrix;  // Создаем вектор для хранения матрицы
    string line;

    // Читаем файл построчно
    while (getline(file, line))
    {
        vector<int> row;
        int value;
        istringstream iss(line);  // Создаем строковой поток из строки
        // Читаем все числа из строки и добавляем их в строку матрицы
        while (iss >> value)
        {
            row.push_back(value);
        }
        matrix.push_back(row);  // Добавляем строку в матрицу
    }

    file.close();  // Закрываем файл
    return matrix;  // Возвращаем считанную матрицу
}

// Функция для нахождения вершины с минимальным расстоянием, которая ещё не включена в SPT (Shortest Path Tree)
int minDistance(const vector<int>& dist, const vector<bool>& sptSet, int n)
{
    int min = numeric_limits<int>::max(), min_index;

    for (int v = 0; v < n; v++)
    {
        if (!sptSet[v] && dist[v] <= min)
        {
            min = dist[v], min_index = v;
        }
    }

    return min_index;
}


vector<int> dijkstra(const vector<vector<int>>& graph, int src)
{
    int n = graph.size();  // Количество вершин в графе
    vector<int> dist(n, numeric_limits<int>::max());  // Вектор для хранения кратчайшего расстояния до каждой вершины
    vector<bool> sptSet(n, false);  // Вектор для отслеживания вершин, включенных в SPT

    dist[src] = 0;  // Расстояние от источника до самого себя равно 0

    // Находим кратчайший путь до всех вершин
    for (int count = 0; count < n - 1; count++)
    {
        int u = minDistance(dist, sptSet, n);  // Выбираем вершину с минимальным расстоянием

        sptSet[u] = true;  // Помечаем вершину как включенную в SPT

        // Обновляем значение расстояния для соседних вершин выбранной вершины
        for (int v = 0; v < n; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    return dist;
}

int main()
{
    string filePath = "graph.txt";
    vector<vector<int>> matrix = readAdjacencyMatrix(filePath);

    int src = 0;  // Начальная вершина/источник
    vector<int> distances = dijkstra(matrix, src);

    // Выводим кратчайшие расстояния от источника до всех вершин
    cout << "Vertex    Distance from Source" << endl;
    for (int i = 0; i < distances.size(); i++)
    {
        cout << i << "                  " << distances[i] << endl;
    }
}
