//����� Danilova Galina
#pragma once

#include <iostream>
#include <string>

// ����������� �����
class ComplexNumber
{
private:
	// ������ � �������� �����
	double imagpart, realpart;

public:


	// ������� ���������� �������� = 0
	ComplexNumber();
	// ������� ���������� �������� ����������� ����������
	ComplexNumber(const double& rpart, const double& ipart);
	// ������� �������� � ������ ������
	void set_num(const double& rpart, const double& ipart);
	// ������� ������ �����
	void set_i(const double &ipart);
	// ������� �������� �����
	void set_r(const double &rpart);
	// ����������� ������ �����
	double get_i() const;
	// ����������� �������� �����
	double get_r() const;
	// �����
	ComplexNumber get_sum(const ComplexNumber& n);
	// �������� ����� 2-� ���������� �����
	ComplexNumber operator + (const ComplexNumber& n2) const;
	// �������� �������� 2-� ���������� �����
	ComplexNumber operator - (const ComplexNumber& n2) const;
	// �������� ��������� 2-� ���������� �����
	ComplexNumber operator * (const ComplexNumber& n2) const;
	// �������� ������� 2-� ���������� �����
	ComplexNumber operator / (const ComplexNumber& n2) const;
	// ������ ������������ �����
	double get_modul() const;
	// �������� ������������ �����
	double get_arg() const;
	// �������������� � ������!
	std::string get_tostring() const;
};