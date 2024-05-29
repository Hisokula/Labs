// алгоритм Прима нахождения минимального покрывающего дерева

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

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

// Функция для нахождения вершины с минимальным значением ключа, которая ещё не включена в MST
int minKey(const vector<int>& key, const vector<bool>& mstSet, int n)
{
    int min = numeric_limits<int>::max(), min_index;

    for (int v = 0; v < n; v++)
    {
        if (!mstSet[v] && key[v] < min)
        {
            min = key[v], min_index = v;
        }
    }

    return min_index;
}

void primMST(const vector<vector<int>>& graph)
{
    int n = graph.size();  // Количество вершин в графе
    vector<int> parent(n, -1);  // Массив для хранения MST
    vector<int> key(n, numeric_limits<int>::max());  // Значения ключей для минимизации веса
    vector<bool> mstSet(n, false);  // Вектор для отслеживания вершин, включенных в MST

    key[0] = 0;  // Начинаем с первой вершины
    parent[0] = -1;  // Первая вершина является корнем MST

    // MST будет содержать n вершин
    for (int count = 0; count < n - 1; count++)
    {
        int u = minKey(key, mstSet, n);  // Выбираем вершину с минимальным значением ключа

        mstSet[u] = true;  // Добавляем вершину в MST

        // Обновляем значение ключа и родителя соседних вершин выбранной вершины
        for (int v = 0; v < n; v++)
        {
            // graph[u][v] - вес ребра u-v
            // mstSet[v] - false если v ещё не включена в MST
            // key[v] - обновляем только если graph[u][v] меньше текущего key[v]
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Выводим MST
    cout << "Edge   Weight" << endl;
    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }
}

int main()
{
    string filePath = "graph.txt";
    vector<vector<int>> matrix = readAdjacencyMatrix(filePath);

    primMST(matrix);
}
