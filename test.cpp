#include "pch.h"
#include "../../ComplexNumber.h"
//Автор Danilova Galina

// Сложение
// Реальная часть
TEST(TestComplexNumber, Plus_real) {
	{
		ComplexNumber a(10, 3), b(3, 2), c = a + b;
		EXPECT_EQ(c.get_r(), 13);
	}

	{
		ComplexNumber a(2, 3), b(3, 2), c = a + b;
		EXPECT_EQ(c.get_r(), 5);
	}

	{
		ComplexNumber a(-10, 3), b(5.5, 2), c = a + b;
		EXPECT_EQ(c.get_r(), -4.5);
	}

}

// Мнимая
TEST(TestComplexNumber, Plus_imag) {
	{
		ComplexNumber a(10, 20), b(3, 30.5), c = a + b;
		EXPECT_EQ(c.get_i(), 50.5);
	}

	{
		ComplexNumber a(2, -0.7), b(3, -0.3), c = a + b;
		EXPECT_EQ(c.get_i(), -1);
	}

	{
		ComplexNumber a(-10, 900), b(5, 900), c = a + b;
		EXPECT_EQ(c.get_i(), 1800);
	}

}

// Вычитание
// Реальная часть
TEST(TestComplexNumber, Minus_real) {
	{
		ComplexNumber a(10, 3), b(3, 2), c = a - b;
		EXPECT_EQ(c.get_r(), 7);
	}

	{
		ComplexNumber a(2, 3), b(3, 2), c = a - b;
		EXPECT_EQ(c.get_r(), -1);
	}

	{
		ComplexNumber a(-10, 3), b(5.5, 2), c = a - b;
		EXPECT_EQ(c.get_r(), -15.5);
	}

}

// Мнимая
TEST(TestComplexNumber, Minus_imag) {
	{
		ComplexNumber a(10, 20), b(3, 10.5), c = a - b;
		EXPECT_EQ(c.get_i(), 9.5);
	}

	{
		ComplexNumber a(2, 1.7), b(3, 1), c = a - b;
		EXPECT_EQ(c.get_i(), 0.7);
	}

	{
		ComplexNumber a(-10, 900), b(5, 500), c = a - b;
		EXPECT_EQ(c.get_i(), 400);
	}

}

// Умножение
// Реальная часть
TEST(TestComplexNumber, Multi_real) {
	{
		ComplexNumber a(10, 3), b(3, 2), c = a * b;
		EXPECT_EQ(c.get_r(), 24);
	}

	{
		ComplexNumber a(-2, 6), b(8, 4), c = a * b;
		EXPECT_EQ(c.get_r(), -40);
	}

	{
		ComplexNumber a(-10.4, 3), b(5.5, 2), c = a * b;
		EXPECT_EQ(c.get_r(), -63.2);
	}

}

// Мнимая часть
TEST(TestComplexNumber, Multi_imag) {
	{
		ComplexNumber a(10, 3), b(3, 2), c = a * b;
		EXPECT_EQ(c.get_i(), 29);
	}

	{
		ComplexNumber a(-2, 6), b(8, 4), c = a * b;
		EXPECT_EQ(c.get_i(), 40);
	}

	{
		ComplexNumber a(10.4, 3), b(5.5, 2), c = a * b;
		EXPECT_EQ(c.get_i(), 37.3);
	}

}

// Деление
TEST(TestComplexNumber, Division) {
	{
		ComplexNumber a(10, 3), b(3, 2), c = a / b;
		EXPECT_EQ(c.get_tostring(), "2.76923+0.846154i");
	}

	{
		ComplexNumber a(-2, 6), b(8, 4), c = a / b;
		EXPECT_EQ(c.get_tostring(), "0.1-0.7i");
	}

	{
		ComplexNumber a(10.4, 3), b(5.5, 2), c = a / b;
		EXPECT_EQ(c.get_tostring(), "1.84526+0.125547i");
	}

	{
		ComplexNumber a(10.4, 3), b(0, 0);
		EXPECT_THROW(a / b, std::logic_error);
		//ASSERT_ANY_THROW(a / b, std::logic_error);
		//ASSERT_NO_THROW(a / b);
	}

}

// Модуль
TEST(TestComplexNumber, Modul) {

	{
		ComplexNumber a(8, 6);
		EXPECT_EQ(a.get_modul(), 10);
	}

	{
		ComplexNumber a(0, 0);
		EXPECT_EQ(a.get_modul(), 0);
	}

	{
		ComplexNumber a(3, 4);
		EXPECT_EQ(a.get_modul(), 5);
	}
}