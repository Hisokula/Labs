// реализовать алгоритм Кнута-Морриса-Пратта для поиска по образцу

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Функция для вычисления префикс-функции
std::vector<int> computePrefixFunction(const std::string& pattern) 
{
    int m = pattern.size();
    std::vector<int> prefixFunction(m);
    int k = 0;

    for (int i = 1; i < m; ++i) 
    {
        while (k > 0 && pattern[k] != pattern[i]) 
        {
            k = prefixFunction[k - 1];
        }
        if (pattern[k] == pattern[i]) 
        {
            ++k;
        }
        prefixFunction[i] = k;
    }

    return prefixFunction;
}

// Функция для поиска образца в тексте с помощью алгоритма КМП
std::vector<int> KMPSearch(const std::string& text, const std::string& pattern) 
{
    std::vector<int> result;
    int n = text.size();
    int m = pattern.size();

    // Вычисление префикс-функции
    std::vector<int> prefixFunction = computePrefixFunction(pattern);

    int q = 0; // количество символов, совпадающих с префиксом образца
    for (int i = 0; i < n; ++i) 
    {
        while (q > 0 && pattern[q] != text[i]) 
        {
            q = prefixFunction[q - 1];
        }
        if (pattern[q] == text[i]) 
        {
            ++q;
        }
        if (q == m) 
        {
            result.push_back(i - m + 1);
            q = prefixFunction[q - 1];
        }
    }

    return result;
}

int main() 
{
    setlocale(LC_ALL, "Russian");

    std::ifstream file("input.txt");
    if (!file.is_open()) 
    {
        std::cerr << "Не удалось открыть файл.\n";
        return 1;
    }

    std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    // Ввод образца с клавиатуры
    std::string pattern;
    std::cout << "Введите строку поиска: ";
    std::cin >> pattern;

    // Поиск образца в тексте
    std::vector<int> occurrences = KMPSearch(text, pattern);

    // Вывод результатов
    if (occurrences.empty()) 
    {
        std::cout << "Образец не найден.\n";
    }
    else 
    {
        std::cout << "Образец найден на позициях: ";
        for (int pos : occurrences) 
        {
            std::cout << pos << " ";
        }
        std::cout << "\n";
    }
}
