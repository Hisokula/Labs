﻿//  решить дискретную задачу о рюкзаке

#include <iostream>
#include <vector>
#include <algorithm>

// Функция для решения задачи о рюкзаке методом динамического программирования
int knapsack(int W, const std::vector<int>& weights, const std::vector<int>& values, int n) {
    // Создаем двумерный массив для хранения промежуточных результатов
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    // Заполняем таблицу dp
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Возвращаем максимальную стоимость, которую можно получить при весе W
    return dp[n][W];
}

int main() {
    // Пример данных: веса и стоимости предметов, а также максимальный вес рюкзака
    std::vector<int> weights = { 2, 3, 4, 5 };
    std::vector<int> values = { 3, 4, 5, 6 };
    int W = 5;
    int n = weights.size();

    // Вызов функции решения задачи о рюкзаке
    int max_value = knapsack(W, weights, values, n);

    // Вывод результата
    std::cout << "Maximum value in Knapsack = " << max_value << std::endl;

    return 0;
}
