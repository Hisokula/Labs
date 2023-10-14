#pragma once
#include<functional>
#include<iostream>

class Differentiation //базовый класс
{
protected:
	double m_x0 = 0; // точка
	double m_dx = 0; // шаг
	double m_accuracy = 0; // точность

	virtual double DiffCalc(const std::function<double(double)>& f, double x0) // абстрактная функция для взятия производной
	{
		return 0;
	}

public:
	void Set_dx(double dx) // сеттер шага
	{
		dx = m_dx;
	}
	void Set_x0(double x0) // сеттер точки
	{
		x0 = m_x0;
	}
	double GetAccuracy() const // геттер точности
	{
		return m_accuracy;
	}
	double Get_dx() const // геттер шага
	{
		return m_dx;
	}
	Differentiation(double x0, double dx) // конструктор объекта базового класса (используется в классах-наследниках)
	{
		m_x0 = x0;
		m_dx = dx;
	}
};

class LeftDiff : public Differentiation // класс для нахождения левой производной
{
public:
	double DiffCalc(const std::function<double(double)>& f, double x0) override // функция для нахождения производной класса-наследника
	{
		return static_cast<double>(f(m_x0) - f(m_x0 - m_dx)) / m_dx;
	}
	LeftDiff(double x0, double dx) : Differentiation(x0, dx) // конструктор класса-наследника
	{
		m_x0 = x0;
		m_dx = dx;
		m_accuracy = m_dx; //расчёт точности
	}
};

class RightDiff : public Differentiation // класс для нахождения правой производной
{
public:
	double DiffCalc(const std::function<double(double)>& f, double x0) override // функция для нахождения производной класса-наследника
	{
		return static_cast<double>(f(m_x0 + m_dx) - f(m_x0)) / m_dx;
	}
	RightDiff(double x0, double dx) : Differentiation(x0, dx) // конструктор класса-наследника
	{
		m_x0 = x0;
		m_dx = dx;
		m_accuracy = m_dx; //расчёт точности
	}
};

class CentralDiff : public Differentiation // класс для нахождения средней производной
{
public:
	double DiffCalc(const std::function<double(double)>& f, double x0) override // функция для нахождения производной класса-наследника
	{
		return static_cast<double>(f(m_x0 + m_dx) - f(m_x0 - m_dx)) / (2 * m_dx);
	}
	CentralDiff(double x0, double dx) : Differentiation(x0, dx) // конструктор класса-наследника
	{
		m_x0 = x0;
		m_dx = dx;
		m_accuracy = m_dx * m_dx; //расчёт точности
	}
};
