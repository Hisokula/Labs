// быстрая сортировка
#include <iostream>
#include <vector>

void Outp(std::vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int Split(std::vector<int> &v, int start, int end)
{
    // Выбираем крайний правый элемент в качестве опорного элемента массива
    int reference = v[end];

    // элементы, меньшие точки поворота, будут перемещены влево от `ref_ind`
    // элементы больше, чем точка поворота, будут сдвинуты вправо от `ref_ind`
    // равные элементы могут идти в любом направлении
    int ref_ind = start;

    // каждый раз, когда мы находим элемент, меньший или равный опорному, `ref_ind`
    // увеличивается, и этот элемент будет помещен перед опорной точкой.
    for (int i = start; i < end; i++)
    {
        if (v[i] <= reference)
        {
            std::swap(v[i], v[ref_ind]);
            ref_ind++;
        }
    }

    std::swap(v[ref_ind], v[end]);


    std::cout << "Referenced: " << std::endl;
    std::cout << v[ref_ind] << std::endl;

    return ref_ind;
}

void Sort(std::vector<int>& v, int start, int end)
{
    if (start >= end) { return; }


    std::cout << "Sorting: " << std::endl;
    Outp(v);

    // переставить элементы по оси
    int reference = Split(v, start, end);

    // повторяем подмассив, содержащий элементы, меньшие опорной точки
    Sort(v, start, reference - 1);

    // повторяем подмассив, содержащий элементы, превышающие точку опоры
    Sort(v, reference + 1, end);

}

int main()
{
    int size = 0;

    std::vector<int> v;

    std::cout << "Input size:" << std::endl;
    std::cin >> size;
    std::cout << "Input elements:" << std::endl;

    for (int i = 0; i < size; i++)
    {
        int el = 0;
        std::cin >> el;
        v.push_back(el);
    }

    Sort(v, 0, size - 1);

    std::cout << "Sorted: " << std::endl;
    Outp(v);

}
/*
10

12412
23
23623461
32
1
5
632
4
25
434
*/