#include <iostream>
#include<vector>
/*
Изучите основные операции над вектором и продемонстрируйте их работу:

1.	push_back, erase, insert
2.	emplace_back
3.	resize, reserve, shrink_to_fit, capacity
4.	clear
5.	оператор присваивания и []

Узнайте размер вектора и будьте готовы объяснить, почему именно так.

*/

int main()
{
    setlocale(LC_ALL, "ru");

    // 1. push_back, erase, insert  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    std::vector<int> NumVector = {1, 42, 14243};


    std::cout << "Содержимое вектора:" << std::endl;
    for (int i = 0; i < NumVector.size(); i++)
    {
        std::cout << NumVector[i] << std::endl;
    }
    
    // push_back <<< <<< <<<
    // вставляет объект в конец с использованием конструктора копирования

    NumVector.push_back(19);
    NumVector.push_back(23412); // <- добавляет элемент в конец ветора

    std::cout << "Содержимое вектора после 2 операций push_back():" << std::endl;

    for (int i = 0; i < NumVector.size(); i++)
    {
        std::cout << NumVector[i] << std::endl;
    }

    // erase <<< <<< <<<

    std::vector<int>::iterator it = NumVector.begin();
    NumVector.erase(it);
    std::cout << "Содержимое вектора после erase 1 элемента:" << std::endl;

    for (int i = 0; i < NumVector.size(); i++)
    {
        std::cout << NumVector[i] << std::endl;
    }

    // insert <<< <<< <<<

    std::vector<int>::iterator it2 = NumVector.begin();
    NumVector.insert(it2, 5);
    std::cout << "Содержимое вектора после insert 1 элемента:" << std::endl;

    for (int i = 0; i < NumVector.size(); i++)
    {
        std::cout << NumVector[i] << std::endl;
    }



    // 2. emplace_back <<< <<< <<<
    // вставляет объект в конец без использования конструктора копирования

    NumVector.emplace_back(2);

    std::cout << "Содержимое вектора после emplace_back:" << std::endl;

    for (int i = 0; i < NumVector.size(); i++)
    {
        std::cout << NumVector[i] << std::endl;
    }



    // 3.	resize, reserve, shrink_to_fit, capacity <<<<<<<<<<<<<<<<<<<<<<<<<

    // resize <<< <<< <<<

    std::cout << "Количество элементов в векторе:" << std::endl;
    std::cout << NumVector.size() << std::endl;

    NumVector.resize(2); // <- заполняет элементы 0(если указать большее значение), иначе удаляет все элементы после указанного индекса

    std::cout << "Количество элементов в векторе после resize:" << std::endl;
    std::cout << NumVector.size() << std::endl;


    // capacity #1 <<< <<< <<<
    
    std::cout << "Capacity вектора до reserve(поcле resize):" << std::endl;
    std::cout << NumVector.capacity() << std::endl;

    // reserve <<< <<< <<<

    NumVector.reserve(100); // <- резервируется 100 ячеек памяти для дальнейшего использования

    //capacity #2 <<< <<< <<<

    std::cout << "Capacity вектора после reserve:" << std::endl;
    std::cout << NumVector.capacity() << std::endl; // <- capacity показывает количество зарезервированных ячеек памяти

    // shrink_to_fit <<< <<< <<<

    NumVector.shrink_to_fit(); // <- освобождение неиспользуемой вектором памяти
    std::cout << "Capacity вектора после shrink_to_fit:" << std::endl;
    std::cout << NumVector.capacity() << std::endl;



    // 4. clear <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    std::cout << "Количество элементов вектора до clear():" << std::endl;
    std::cout << NumVector.size() << std::endl;

    NumVector.clear();

    std::cout << "Количество элементов вектора после clear():" << std::endl;
    std::cout << NumVector.size() << std::endl;


    // 5.	оператор присваивания и [] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    NumVector = {1, 2, 3, 4, 5, 6, 7, 8};

    std::vector<int> OtherVector;
    OtherVector = NumVector;

    std::cout << "Содержимое первого вектора:" << std::endl;

    for (int i = 0; i < NumVector.size(); i++)
    {
        std::cout << NumVector[i] << std::endl;
    }

    std::cout << "Содержимое второго вектора(которому было присвоено значение первого):" << std::endl;

    for (int i = 0; i < OtherVector.size(); i++)
    {
        std::cout << OtherVector[i] << std::endl;
    }

    NumVector[3] = 234;
    OtherVector[5] = NumVector[3];

    std::cout << "Содержимое первого вектора(с изменённым 4 элементом):" << std::endl;
    for (int i = 0; i < NumVector.size(); i++)
    {
        std::cout << NumVector[i] << std::endl;
    }

    std::cout << "Содержимое второго вектора(6 элемент которого теперь равен 3 элементу первого вектора):" << std::endl;

    for (int i = 0; i < OtherVector.size(); i++)
    {
        std::cout << OtherVector[i] << std::endl;
    }


}