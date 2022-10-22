//Автор Danilova Galina
#include <math.h>
#include <string>
#include <sstream>
#include <stdexcept>

#include "ComplexNumber.h"


// Задание начального значения = 0
ComplexNumber::ComplexNumber() {
	imagpart = 0;
	realpart = 0;
}

// Задание начального значения конкретными значениями
ComplexNumber::ComplexNumber(const double& rpart, const double& ipart){
	realpart = rpart;
	imagpart = ipart;
}

// Задание реальной и мнимой частей
void ComplexNumber::set_num(const double &rpart, const double &ipart) {
	realpart = rpart;
	imagpart = ipart;
	//return;
}

// Задание мнимой части
void ComplexNumber::set_i(const double& ipart){
	imagpart = ipart;
	//return;
}

// Задание реальной части
void ComplexNumber::set_r(const double& rpart){
	realpart = rpart;
	//return;
}

// Возвращение мнимой части
double ComplexNumber::get_i() const {
	return imagpart;
}

// Возвращение реальной части
double ComplexNumber::get_r() const {
	return realpart;
}

// Сумма комплексных чисел
ComplexNumber ComplexNumber::get_sum(const ComplexNumber& n) {
	ComplexNumber res;
	res.realpart = this->realpart + n.realpart;
	res.imagpart = this->imagpart + n.imagpart;
	return res;
}

// Оператор суммы 2-х комлексных чисел
ComplexNumber ComplexNumber::operator + (const ComplexNumber& n2) const{
	/*ComplexNumber res;
	res.realpart = this->realpart + n2.realpart;
	res.imagpart = this->imagpart + n2.imagpart;*/
	return ComplexNumber(this->realpart + n2.realpart, this->imagpart + n2.imagpart);
}

// Оператор разности 2-х комлексных чисел
ComplexNumber ComplexNumber::operator - (const ComplexNumber& n2) const{
	ComplexNumber res;
	res.realpart = this->realpart - n2.realpart;
	res.imagpart = this->imagpart - n2.imagpart;
	return res;
}

// Оператор умножения 2-х комлексных чисел
ComplexNumber ComplexNumber::operator * (const ComplexNumber& n2) const{
	ComplexNumber res;
	res.realpart = this->realpart * n2.realpart - this->imagpart * n2.imagpart;
	res.imagpart = this->realpart * n2.imagpart + n2.realpart * this->imagpart;
	return res;
}

// Оператор деления 2-х комлексных чисел
ComplexNumber ComplexNumber::operator / (const ComplexNumber& n2) const{	
	if (abs(n2.imagpart)> 10e-6 || abs(n2.realpart) > 10e-6) {	
		ComplexNumber res;
		res.realpart = (this->realpart * n2.realpart + this->imagpart * n2.imagpart) / (pow(n2.realpart, 2) + pow(n2.imagpart, 2));
		res.imagpart = (this->realpart * n2.imagpart - this->imagpart * n2.realpart) / (pow(n2.realpart, 2) + pow(n2.imagpart, 2));
		return res;
	}
	else
		throw std::logic_error("Деление на ноль!");
}

// Модуль комплексного числа
double ComplexNumber::get_modul() const {
	return sqrt(realpart * realpart + imagpart * imagpart);
}

// Аргумент комплексного числа
double ComplexNumber::get_arg() const {
	if (abs(imagpart) > 10e-6 || abs(realpart) > 10e-6) 
		return asin(imagpart / (sqrt(realpart * realpart + imagpart * imagpart)));
	
	else
		throw std::logic_error("Деление на ноль!");
}

// Преобразование в строку 
std::string ComplexNumber::get_tostring() const {
	std::ostringstream strr, stri;
	strr << this->realpart;
	stri << this->imagpart;
	// если число положительное, то нужно добавить знак плюс
	if (this->imagpart >= 0) 
		return strr.str() +"+" + stri.str() + "i";
	else
		// иначе ничего добалять не надо, так как знак минуса уже есть в самом числе
		return strr.str() + stri.str() + "i";
}