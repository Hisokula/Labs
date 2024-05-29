// алгоритм нахождения эйлерова цикла в неориентированном графе, заданном матрицей смежности

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>

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

// Функция для проверки, является ли граф Эйлеровым
bool isEulerian(const vector<vector<int>>& graph)
{
    int odd = 0;  // Количество вершин с нечетной степенью
    for (const auto& row : graph)
    {
        int degree = 0;
        for (int val : row)
        {
            if (val != 0)
            {
                degree++;
            }
        }
        if (degree % 2 != 0)
        {
            odd++;
        }
    }
    return (odd == 0);  // Граф Эйлеров, если все вершины имеют четную степень
}

// Функция для нахождения Эйлерова цикла
void findEulerianCycle(vector<vector<int>>& graph)
{
    // Проверяем, является ли граф Эйлеровым
    if (!isEulerian(graph))
    {
        cout << "The graph is not Eulerian.\n";
        return;
    }

    stack<int> currentPath;  // Стек для текущего пути
    vector<int> circuit;  // Вектор для хранения Эйлерова цикла

    currentPath.push(0);  // Начинаем с вершины 0
    int currentVertex = 0;  // Текущая вершина

    while (!currentPath.empty())
    {
        if (any_of(graph[currentVertex].begin(), graph[currentVertex].end(), [](int i) { return i != 0; }))
        {
            // Если есть еще инцидентные ребра
            currentPath.push(currentVertex);
            // Находим следующую вершину, соединенную с currentVertex
            for (int i = 0; i < graph.size(); ++i)
            {
                if (graph[currentVertex][i] != 0)
                {
                    graph[currentVertex][i]--;  // Удаляем ребро
                    graph[i][currentVertex]--;  // Граф неориентированный, удаляем симметричное ребро
                    currentVertex = i;  // Переходим к следующей вершине
                    break;
                }
            }
        }
        else
        {
            // Если инцидентных ребер нет, добавляем вершину в цикл
            circuit.push_back(currentVertex);
            currentVertex = currentPath.top();
            currentPath.pop();
        }
    }

    // Выводим Эйлеров цикл
    cout << "Eulerian Cycle: ";
    for (int vertex : circuit)
    {
        cout << vertex << " ";
    }
    cout << "\n";
}

int main()
{
    string filePath = "graph.txt";  // Путь к файлу с матрицей смежности
    vector<vector<int>> matrix = readAdjacencyMatrix(filePath);  // Считываем матрицу

    findEulerianCycle(matrix);  // Ищем и выводим Эйлеров цикл

    return 0;  // Завершаем выполнение программы
}