﻿#include <iostream>
#include <string>
#include <vector>
#include <stack>

// бинарное дерево
struct Tree
{
    int data;
    int level;  //Уровень узла для вывода дерева на экран
    Tree* left;
    Tree* right;
    Tree* parent;
};

// создание узла в дереве
Tree* CreateRoot(int data, Tree* p) // узел инициализируется с помощью ссылки на родителя и данных, в нём содержащихся
{
    // создание новой вершины дерева
    Tree* q = new Tree;
    q->data = data;
    // используем тернарный оператор
    q->level = (p == nullptr ? 0 : p->level + 1);
    q->left = nullptr;
    q->right = nullptr;
    q->parent = p;

    return q;
}

// добавление элемента (по данным и указателю на указатель нужного корня)
void AddElement(int data, Tree*& root)
{
    if (root == nullptr) // корень дерева пуст => создаём корень
    {
        root = CreateRoot(data, nullptr);
        return;
    }

    Tree* v = root;

    // помещаем данный элемент в левый или правый потомок
    while (((data < v->data) && (v->left != nullptr)) || ((data > v->data) && (v->right != nullptr)))
    {
        if (data < v->data)
        {
            v = v->left;
        }
        else
        {
            v = v->right;
        }
    }

    // если значение потомка равно значению родителя, бездействуем
    if (data == v->data)
    {
        return;
    }

    // создаем новую вершину
    Tree* u = CreateRoot(data, v);
    if (data < v->data)
    {
        v->left = u;
    }
    else
    {
        v->right = u;
    }
}

// добавление элемента на основе скобочной записи
void AddBracketElement(int data, Tree*& root, bool is_left)
{
    Tree* v = root;
    Tree* u = CreateRoot(data, v);
    if (is_left)
    {
        v->left = u;
    }
    else
    {
        v->right = u;
    }
}

// заполнение бинарного дерева
void FillTree(std::string& str, int& i, Tree*& root)
{
    int value = 0;

    while (str[i] != '\0')
    {
        switch (str[i])
        {
        case '(':                                                           // '(' => двигаемся по дереву влево
        {
            i++;
            value = 0;
            while ((str[i] >= '0') && (str[i] <= '9'))                      // является ли этот элемент цифрой?
            {
                value = value * 10 + str[i] - '0';
                i++;
            }

            if (value != 0)
            {
                AddBracketElement(value, root, true);                       // добавление элемента
                if (str[i] == '(')                                          // если после '(' стоит '(' => рекурсивно вызываем данную функцию
                {
                    FillTree(str, i, root->left);
                }
            }
            value = 0;
            break;
        }
        case ',':                                                           // ',' => двигаемся по дереву вправо
        {
            i++;
            value = 0;
            while ((str[i] >= '0') && (str[i] <= '9'))
            {
                value = value * 10 + str[i] - '0';
                i++;
            }

            if (value != 0)
            {
                AddBracketElement(value, root, false);
                if (str[i] == '(')
                {
                    FillTree(str, i, root->right);
                }
            }
            value = 0;
            break;
        }

        case ')':                                                           // ')' останавливает предыдущую рекурсию, рассматривается следующий элемент
        {
            i++;
            return;
        }
        default:
        {
            break;
        }
        }
    }
}

// прямой обход дерева
void Pass(Tree* v)
{
    if (v == nullptr)
    {
        return;
    }
    Pass(v->left);
    std::cout << v->data << std::endl;
    Pass(v->right);
}

// поиск элемента
Tree* SearchElement(int data, Tree* v)
{
    if (v == nullptr)
    {
        return v;
    }
    if (v->data == data)
    {
        return v;
    }
    if (data < v->data)
    {
        return SearchElement(data, v->left);
    }
    else
    {
        return SearchElement(data, v->right);
    }
}

// удаление элемента
void DeleteElement(int data, Tree*& root)
{
    Tree* u = SearchElement(data, root);

    if (u == nullptr)
    {
        return;
    }

    if (u->left == nullptr && u->right == nullptr && u == root)         // элемент — корень, значит удаляем его
    {
        delete root;
        root = nullptr;
        return;
    }

    if (u->left == nullptr && u->right != nullptr && u == root)         // есть правый потомок => меняем элемент с самым маленьким элементом, находящимся справа
    {
        Tree* t = u->right;
        while (t->left != nullptr)
        {
            t = t->left;
        }
        u->data = t->data;
        u = t;
    }

    if (u->left != nullptr && u->right == nullptr && u == root)         // есть левый потомок => меняем элемент с самым большим из левой части
    {
        Tree* t = u->left;
        while (t->right != nullptr)
        {
            t = t->right;
        }
        u->data = t->data;
        u = t;
    }

    if (u->left != nullptr && u->right != nullptr)                      // есть оба потомка => меняем наш элемент с самым маленьким из правой части
    {
        Tree* t = u->right;
        while (t->left != nullptr)
        {
            t = t->left;
        }
        u->data = t->data;
        u = t;
    }

    Tree* t;                                                            // удаление элемента
    if (u->left == nullptr)
    {
        t = u->right;
    }
    else
    {
        t = u->left;
    }
    if (u->parent->left == u)
    {
        u->parent->left = t;
    }
    else
    {
        u->parent->right = t;
    }
    if (t != nullptr)
    {
        t->parent = u->parent;
    }
    delete u;
}

// очистка дерева
void ClearTree(Tree*& v)
{
    if (v == nullptr)                                                   // удаляем узлы
    {
        return;
    }
    ClearTree(v->left);
    ClearTree(v->right);
    delete v;
    v = nullptr;
}

// вывод дерева на экран
void Print(Tree* root)         
{
    if (root == nullptr)
    {
        std::cout << std::endl;
        return;
    }

    // выводим дерева на экран справа налево (в консоли оно будет лежать на левом боку)
    Print(root->right);

    for (int i = root->level; i > 0; i--)
    {
        std::cout << '\t';
    }
    std::cout << root->data << std::endl;

    Print(root->left);
}

void Menu(Tree* root)   //Реализация меню выбора
{
    int input;
    bool flag = false;
    while (!flag)
    {
        std::cout << "Выберите номер операции:" << std::endl;
        std::cout << "Добавить - 1, Удалить - 2, Найти - 3, Выход из программы - 4" << std::endl;
        std::cin >> input;
        switch (input)
        {
        case 1:
        {
            int value;
            std::cout << "Введите значение, которое надо добавить: ";
            std::cin >> value;
            AddElement(value, root);
            break;
        }
        case 2:
        {
            int value;
            std::cout << "Введите значение, которое надо удалить: ";
            std::cin >> value;
            DeleteElement(value, root);
            break;
        }
        case 3:
        {
            int value;
            std::cout << "Введите значение, которое надо найти: ";
            std::cin >> value;

            Tree* element = nullptr;
            element = SearchElement(value, root);
            std::cout << "Элемент " << (element == nullptr ? "Не найден!" : "найден.") << std::endl;
            break;
        }
        case 4:
            flag = true;
            break;
        default:
            break;
        }
    }
    Print(root);
}


int main()
{
    setlocale(LC_ALL, "rus");
    std::string str;
    std::cout << "Введите выражение в скобочном виде!" << std::endl;
    std::cin >> str;

    Tree* root = nullptr;

    int value = 0, i = 0;
    while ((str[i] >= '0') && (str[i] <= '9'))  //Если в строке число, пишем его в значение узла
    {
        value = value * 10 + str[i] - '0';
        i++;
    }
    AddElement(value, root);
    FillTree(str, i, root);
    Menu(root);
    ClearTree(root);

}

//8(3(1,6(4,7)),10(,14(13,)))