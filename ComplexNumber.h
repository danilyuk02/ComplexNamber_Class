//Автор Danilova Galina
#pragma once

#include <iostream>
#include <string>

// Комплексное число
class ComplexNumber
{
private:
	// Мнимая и реальная части
	double imagpart, realpart;

public:


	// Задание начального значения = 0
	ComplexNumber();
	// Задание начального значения конкретными значениями
	ComplexNumber(const double& rpart, const double& ipart);
	// Задание реальной и мнимой частей
	void set_num(const double& rpart, const double& ipart);
	// Задание мнимой части
	void set_i(const double &ipart);
	// Задание реальной части
	void set_r(const double &rpart);
	// Возвращение мнимой части
	double get_i() const;
	// Возвращение реальной части
	double get_r() const;
	// Сумма
	ComplexNumber get_sum(const ComplexNumber& n);
	// Оператор суммы 2-х комлексных чисел
	ComplexNumber operator + (const ComplexNumber& n2) const;
	// Оператор разности 2-х комлексных чисел
	ComplexNumber operator - (const ComplexNumber& n2) const;
	// Оператор умножения 2-х комлексных чисел
	ComplexNumber operator * (const ComplexNumber& n2) const;
	// Оператор деления 2-х комлексных чисел
	ComplexNumber operator / (const ComplexNumber& n2) const;
	// Модуль комплексного числа
	double get_modul() const;
	// Аргумент комплексного числа
	double get_arg() const;
	// Преобразование в строку!
	std::string get_tostring() const;
};