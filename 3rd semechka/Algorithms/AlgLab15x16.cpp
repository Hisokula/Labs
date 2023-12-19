#include <iostream>
#include <string>
#include <vector>
#include <stack>

// бинарное дерево
struct Tree
{
    int data;
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
void PASS(Tree* v)   
{
    if (v == nullptr)
    {
        return;
    }
    PASS(v->left);
    std::cout << v->data << std::endl;
    PASS(v->right);
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

// рекурсивная функция для обхода дерева в прямом порядке
void preorder(Tree* root) 
{
    if (root == nullptr)
    {
        return;
    }
    std::cout << root->data << std::endl;                               // данные текущего узла
    preorder(root->left);                                               // обход левого поддерева
    preorder(root->right);                                              // обход правого поддерева
}

// рекурсивная функция для центрального обхода дерева
void inorder(Tree* root) 
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);                                                // обход левого поддерева
    std::cout << root->data << std::endl;                               // данные текущего узла
    inorder(root->right);                                               // обход правого поддерева
}

// рекурсивная функция для обхода дерева в обратном порядке
void postorder(Tree* root) 
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->left);                                              // обход левого поддерева
    postorder(root->right);                                             // обход правого поддерева
    std::cout << root->data << std::endl;                               // данные текущего узла

}

// нерекурсивная функция для обхода дерева в обратном порядке
void iterativeOrder(Tree* root)  
{
    std::stack<Tree*> stack;                                            // в пустой стек помещаем корневой узел
    stack.push(root);

    while (!stack.empty())                                              // обход до тех пор, пока стек не опустеет
    {
        Tree* node = stack.top();
        stack.pop();
        std::cout << node->data << std::endl;

        if (node->left != nullptr)
        {
            stack.push(node->left);
        }
        if (node->right != nullptr)
        {
            stack.push(node->right);
        }
    }
}


int main()
{
    setlocale(LC_ALL, "rus");
    std::string str;
    std::cout << "Input:" << std::endl;
    std::cin >> str;

    Tree* root = nullptr;

    int value = 0;
    int i = 0;

    // если в строке число, записываем его в значение узла
    while ((str[i] >= '0') && (str[i] <= '9')) 
    {
        value = value * 10 + str[i] - '0';
        i++;
    }

    AddElement(value, root);
    FillTree(str, i, root);

    preorder(root);
    std::cout << "________________________" << std::endl;
    inorder(root);
    std::cout << "________________________" << std::endl;
    postorder(root);
    std::cout << "________________________" << std::endl;
    iterativeOrder(root);
    std::cout << "________________________" << std::endl;
    ClearTree(root);

}

//8(3(1,6(4,7)),10(,14(13,)))
