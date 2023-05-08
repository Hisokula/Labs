/*
Используя наследование и полиморфизм, напишите программу, которая работает с геометрическими фигурами:
1.	Треугольник
2.	Прямоугольник
3.	Круг

Программа должна хранить координаты и размеры фигуры, цвет, уметь вычислять площадь фигуры.

Продемонстрируйте, как ваша программа будет выводить на экран площади всех фигур.

*/

#include <iostream>

enum class Shape
{
	TRIANGLE,
	RECTANGLE,
	CIRCLE
};

enum class Color
{
	BLUE,
	GREEN,
	YELLOW
};

class Figure
{
private:

	//Shape m_shape;
	Color m_color;
	size_t m_area;
	//size_t m_angles;
	int* m_coord = new int[0];

public:

	Figure(/*Shape shape,*/ Color color, size_t area, /*size_t angles,*/ int* coord) : /*m_shape(shape),*/ m_color(color), m_area(area), /*m_angles(angles),*/ m_coord(coord) { }
	
	size_t Area()
	{
		return m_area;
	}


};

class Triangle : Figure
{
public:

	Triangle(/*Shape shape,*/ Color color, size_t area, /*size_t angles,*/ int* coord) : Figure(color, area, /*angles,*/ coord) {}
};

int main()
{

}
