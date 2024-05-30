// реализовать алгоритм Рабина для поиска по образцу

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int d = 256;  // Количество возможных символов (всего символов в алфавите)
const int q = 101;  // Простое число для вычисления хэш-значений

// Функция для вычисления хэш-значения строки
int computeHash(const std::string& str, int length) {
    int hash = 0;
    for (int i = 0; i < length; ++i) {
        hash = (d * hash + str[i]) % q;
    }
    return hash;
}

// Функция для поиска образца в тексте с помощью алгоритма Рабина-Карпа
std::vector<int> RabinKarpSearch(const std::string& text, const std::string& pattern) {
    std::vector<int> result;
    int n = text.size();
    int m = pattern.size();

    if (m > n) return result; // Если образец длиннее текста, то совпадений нет

    // Вычисляем хэш-значение для образца и начальной подстроки текста
    int patternHash = computeHash(pattern, m);
    int textHash = computeHash(text, m);

    // Предварительно вычисляем значение d^(m-1) % q
    int h = 1;
    for (int i = 0; i < m - 1; ++i) {
        h = (h * d) % q;
    }

    // Ищем совпадения
    for (int i = 0; i <= n - m; ++i) {
        // Если хэш-значения совпадают, проверяем символы
        if (patternHash == textHash) {
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                result.push_back(i);
            }
        }
        // Вычисляем хэш-значение для следующей подстроки текста
        if (i < n - m) {
            textHash = (d * (textHash - text[i] * h) + text[i + m]) % q;
            if (textHash < 0) {
                textHash += q;
            }
        }
    }

    return result;
}

int main() 
{
    setlocale(LC_ALL, "Russian");

    std::ifstream file("input.txt");
    if (!file.is_open()) {
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
    std::vector<int> occurrences = RabinKarpSearch(text, pattern);

    // Вывод результатов
    if (occurrences.empty()) {
        std::cout << "Образец не найден.\n";
    }
    else {
        std::cout << "Образец найден на позициях: ";
        for (int pos : occurrences) {
            std::cout << pos << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
