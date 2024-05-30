//  решить задачу о раскраске графа

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

// Функция для раскраски графа
void graphColoring(std::vector<std::list<int>>& adjList, int V) {
    // Массив для хранения цветов узлов, инициализируем все узлы как неокрашенные (-1)
    std::vector<int> result(V, -1);

    // Первый узел красим первым цветом
    result[0] = 0;

    // Массив для хранения доступности цветов для всех узлов
    std::vector<bool> available(V, true);

    // Начинаем с 1-го узла (первый уже окрашен)
    for (int u = 1; u < V; ++u) {
        // Помечаем все цвета соседних узлов как недоступные
        for (int neighbor : adjList[u]) {
            if (result[neighbor] != -1) {
                available[result[neighbor]] = false;
            }
        }

        // Находим первый доступный цвет
        int cr;
        for (cr = 0; cr < V; ++cr) {
            if (available[cr]) {
                break;
            }
        }

        // Присваиваем найденный цвет текущему узлу
        result[u] = cr;

        // Сбрасываем доступность цветов для следующего узла
        for (int neighbor : adjList[u]) {
            if (result[neighbor] != -1) {
                available[result[neighbor]] = true;
            }
        }
    }

    // Выводим результат
    for (int u = 0; u < V; ++u) {
        std::cout << "Vertex " << u << " --->  Color " << result[u] << std::endl;
    }
}

int main() {
    // Пример графа (число вершин V и список смежности adjList)
    int V = 5;
    std::vector<std::list<int>> adjList(V);

    // Добавление рёбер в граф
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(0);
    adjList[1].push_back(2);
    adjList[1].push_back(3);
    adjList[2].push_back(0);
    adjList[2].push_back(1);
    adjList[2].push_back(3);
    adjList[3].push_back(1);
    adjList[3].push_back(2);
    adjList[3].push_back(4);
    adjList[4].push_back(3);

    // Вызов функции раскраски графа
    graphColoring(adjList, V);

    return 0;
}
