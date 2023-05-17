/*
Используя наследование и полиморфизм, напишите программу, которая работает с геометрическими фигурами:
1.	Треугольник
2.	Прямоугольник
3.	Круг
Программа должна хранить координаты и размеры фигуры, цвет, уметь вычислять площадь фигуры.
Продемонстрируйте, как ваша программа будет выводить на экран площади всех фигур.
*/

#include <iostream>


enum class Color
{
	BLUE,
	GREEN,
	YELLOW
};

class Figure
{
private:

	Color m_color;
	size_t m_area;
	unsigned int m_angles;
	int* m_coord = new int[0];

public:

	Figure(Color color, size_t area, unsigned int angles, int* coord) : m_color(color), m_area(area), m_angles(angles), m_coord(coord) { }

	size_t Area()
	{

		return m_area;
	}


};

class Triangle : Figure
{
public:

	Triangle(Color color, size_t area, int* coord) : Figure(color, area, 3, coord) {}
};

class Rectangle : Figure
{
public:

	Rectangle(Color color, size_t area, int* coord) : Figure(color, area, 4, coord) {}
};

class Circle : Figure
{
public:

	Circle(Color color, size_t area, int* coord) : Figure(color, area, 0, coord) {}
};

int main()
{

}
