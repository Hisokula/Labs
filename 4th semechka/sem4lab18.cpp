// решить задачу о суммах подмножеств, используя жадный алгоритм.

#include <iostream>
#include <vector>
#include <algorithm>

// Функция для решения задачи о суммах подмножеств с использованием жадного алгоритма
bool subsetSumGreedy(const std::vector<int>& nums, int target, std::vector<int>& result) {
    // Сортируем элементы в порядке убывания
    std::vector<int> sorted_nums = nums;
    std::sort(sorted_nums.rbegin(), sorted_nums.rend());

    int current_sum = 0;

    for (int num : sorted_nums) {
        if (current_sum + num <= target) {
            current_sum += num;
            result.push_back(num);
        }
        if (current_sum == target) {
            return true;
        }
    }
    return false;
}

int main() {
    // Набор чисел и целевая сумма
    std::vector<int> nums = { 3, 34, 4, 12, 5, 2 };
    int target = 9;

    // Вектор для хранения результата
    std::vector<int> result;

    // Вызов функции для поиска суммы подмножества
    if (subsetSumGreedy(nums, target, result)) {
        std::cout << "Subset with the given sum found: ";
        for (int num : result) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "No subset with the given sum found." << std::endl;
    }
}
