#pragma once
#include<functional>
#include<iostream>

class Differentiation
{
protected:
	double m_x0 = 0;
	double m_dx = 0;
	double m_accuracy = 0;

	virtual double DiffCalc(const std::function<double(double)>& f, double x0)
	{
		return 0;
	}

public:
	void Set_dx(double dx)
	{
		dx = m_dx;
	}
	void Set_x0(double x0)
	{
		x0 = m_x0;
	}
	double GetAccuracy()
	{
		return m_accuracy;
	}
	double Get_dx()
	{
		return m_dx;
	}
	Differentiation(double x0, double dx)
	{
		m_x0 = x0;
		m_dx = dx;
	}
};

class LeftDiff : public Differentiation
{
public:
	double DiffCalc(const std::function<double(double)>& f, double x0) override
	{
		return static_cast<double>(f(m_x0) - f(m_x0 - m_dx)) / m_dx;
	}
	LeftDiff(double x0, double dx) : Differentiation(x0, dx)
	{
		m_x0 = x0;
		m_dx = dx;
		m_accuracy = m_dx;
	}
};

class RightDiff : public Differentiation
{
public:
	double DiffCalc(const std::function<double(double)>& f, double x0) override
	{
		return static_cast<double>(f(m_x0 + m_dx) - f(m_x0)) / m_dx;
	}
	RightDiff(double x0, double dx) : Differentiation(x0, dx)
	{
		m_x0 = x0;
		m_dx = dx;
		m_accuracy = m_dx;
	}
};

class CentralDiff : public Differentiation
{
public:
	double DiffCalc(const std::function<double(double)>& f, double x0) override
	{
		return static_cast<double>(f(m_x0 + m_dx) - f(m_x0 - m_dx)) / (2 * m_dx);
	}
	CentralDiff(double x0, double dx) : Differentiation(x0, dx)
	{
		m_x0 = x0;
		m_dx = dx;
		m_accuracy = m_dx * m_dx;
	}
};