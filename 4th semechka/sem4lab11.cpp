// реализовать алгоритм поиска по образцу с помощью конечного автомата

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

// Функция для построения таблицы переходов для КДА
std::vector<std::unordered_map<char, int>> buildTransitionTable(const std::string& pattern) 
{
    int m = pattern.size();
    std::vector<std::unordered_map<char, int>> transitionTable(m + 1);

    for (int state = 0; state <= m; ++state) 
    {
        for (char ch = 'a'; ch <= 'z'; ++ch) 
        { // предполагаем, что символы - это только строчные буквы
            int nextState = 0;
            if (state < m&& ch == pattern[state]) 
            {
                nextState = state + 1;
            }
            else 
            {
                for (int ns = state; ns > 0; --ns) 
                {
                    if (pattern[ns - 1] == ch) 
                    {
                        bool match = true;
                        for (int k = 0; k < ns - 1; ++k) 
                        {
                            if (pattern[k] != pattern[state - ns + 1 + k]) 
                            {
                                match = false;
                                break;
                            }
                        }
                        if (match) 
                        {
                            nextState = ns;
                            break;
                        }
                    }
                }
            }
            transitionTable[state][ch] = nextState;
        }
    }

    return transitionTable;
}

// Функция для поиска образца в тексте с помощью КДА
std::vector<int> searchPattern(const std::string& text, const std::string& pattern) 
{
    std::vector<int> result;
    int n = text.size();
    int m = pattern.size();

    // Построение таблицы переходов
    auto transitionTable = buildTransitionTable(pattern);

    // Поиск в тексте
    int state = 0;
    for (int i = 0; i < n; ++i) 
    {
        state = transitionTable[state][text[i]];
        if (state == m) 
        {
            result.push_back(i - m + 1);
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
    std::vector<int> occurrences = searchPattern(text, pattern);

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