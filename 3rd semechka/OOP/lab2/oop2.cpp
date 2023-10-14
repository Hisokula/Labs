#include<iostream>
#include<vector>


// шаблонный класс сразу принимает размерность массива (x, y, z)
template<class T, int x, int y, int z>
class Array3d
{
private:

    std::vector<T> m_v;
    int m_size = x * y * z;

public:

    // объект класса конструируется с помощью вектора
    Array3d(std::vector<T> vec)
    {
        if ((x <= 0) or (y <= 0) or (z <= 0))
        {
            std::cout << "Incorrect size." << std::endl;
            exit(5);
        }
        while (m_size != 0)
        {
            m_v.push_back(0);
            m_size--;
        }
    }

    // получение элемента массива по 3 индексам
    T Getter(int i, int j, int k)
    {
        return m_v[i * y * z + j * z + k];
    }

    // задание элемента массива по 3 индексам
    void Setter(int i, int j, int k, T el)
    {
        m_v[i * y * z + j * z + k] = el;
    }

    // оператор вывода массива (для удобства, выводятся подмассивы по x)
    friend std::ostream& operator << (std::ostream& outp, const Array3d& arr)
    {
        for (int i = 0; i < x; i++)
        {
            outp << "Subarray " << i << ":" << std::endl;
            for (int j = 0; j < y; j++)
            {
                for (int k = 0; k < z; k++)
                {
                    outp << arr.m_v[i * y * z + j * z + k] << " ";
                }
                outp << std::endl;
            }
        }
        return outp;
    }

    // геттер вектора векторов из элементов (по x)
    std::vector<std::vector<T>> GetValues0(int i)
    {
        std::vector<std::vector<T>> result(y, std::vector<T>(z));
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                result[j][k] = m_v[i * y * z + j * z + k];
            }
        }
        return result;
    }

    // геттер вектора векторов из элементов (по y)
    std::vector<std::vector<T>> GetValues1(int j)
    {
        std::vector<std::vector<T>> result(x, std::vector<T>(z));
        for (int i = 0; i < x; i++)
        {
            for (int k = 0; k < z; k++)
            {
                result[i][k] = m_v[i * y * z + j * z + k];
            }
        }
        return result;
    }

    // геттер вектора векторов из элементов (по z)
    std::vector<std::vector<T>> GetValues2(int k)
    {
        std::vector<std::vector<T>> result(x, std::vector<T>(y));
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                result[i][j] = m_v[i * y * z + j * z + k];
            }
        }
        return result;
    }

    // геттер вектора из элементов (по x, y)
    std::vector<T> GetValues01(int i, int j)
    {
        std::vector<T> result(z);
        for (int k = 0; k < z; k++)
        {
            result[k] = m_v[i * y * z + j * z + k];
        }
        return result;
    }

    // геттер вектора из элементов (по x, z)
    std::vector<T> GetValues02(int i, int k)
    {
        std::vector<T> result(y);
        for (int j = 0; j < y; j++)
        {
            result[j] = m_v[i * y * z + j * z + k];
        }
        return result;
    }

    // геттер вектора из элементов (по y, z)
    std::vector<T> GetValues12(int j, int k)
    {
        std::vector<T> result(x);
        for (int i = 0; i < x; i++)
        {
            result[i] = m_v[i * y * z + j * z + k];
        }
        return result;
    }
};

int main()
{
    std::vector<int> vec(27, 0);
    Array3d<int, 3, 3, 3> arr(vec);

    // заполнение массива значениями от 1 до 27
    int count = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                arr.Setter(i, j, k, count);
                count++;
            }
        }
    }

    // вывод массива в консоль
    std::cout << arr << std::endl;

    // значения элементов массива по заданным индексам
    std::cout << "arr.Getter(0,0,0) = " << arr.Getter(0, 0, 0) << std::endl;
    std::cout << "arr.Getter(1,1,1) = " << arr.Getter(1, 1, 1) << std::endl;
    std::cout << "arr.Getter(2,2,2) = " << arr.Getter(2, 2, 2) << std::endl;

    // значения элементов массива по заданным индексам (в виде векторов)
    std::vector<int> values01 = arr.GetValues01(0, 1);
    std::vector<int> values02 = arr.GetValues02(0, 2);
    std::vector<int> values12 = arr.GetValues12(1, 2);

    // вывод этих векторов
    std::cout << "arr.GetValues01(0,1) = ";
    for (int i = 0; i < values01.size(); i++)
    {
        std::cout << values01[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "arr.GetValues02(0,2) = ";
    for (int i = 0; i < values02.size(); i++)
    {
        std::cout << values02[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "arr.GetValues12(1,2) = ";
    for (int i = 0; i < values12.size(); i++)
    {
        std::cout << values12[i] << " ";
    }
    std::cout << std::endl;

    // значения элементов массива по заданным индексам (в виде векторов векторов)
    std::vector<std::vector<int>> value0 = arr.GetValues0(0);
    std::vector<std::vector<int>> value1 = arr.GetValues1(1);
    std::vector<std::vector<int>> value2 = arr.GetValues2(2);

    // вывод векторов векторов
    std::cout << "arr.GetValue0(0) = " << std::endl;
    for (int i = 0; i < value0.size(); i++)
    {
        for (int j = 0; j < value0[i].size(); j++)
        {
            std::cout << value0[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "arr.GetValues1(1) = " << std::endl;
    for (int i = 0; i < value1.size(); i++)
    {
        for (int j = 0; j < value1[i].size(); j++)
        {
            std::cout << value1[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "arr.GetValues2(2) = " << std::endl;
    for (int i = 0; i < value2.size(); i++)
    {
        for (int j = 0; j < value2[i].size(); j++)
        {
            std::cout << value2[i][j] << " ";
        }
        std::cout << std::endl;
    }

}