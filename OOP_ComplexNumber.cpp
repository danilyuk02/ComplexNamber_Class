// OOP_ComplexNumber.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Автор Danilova Galina
#include <iostream>
#include <locale>
#include <string>

#include "ComplexNumber.h"
#include "ModulCN.h"

using namespace std;



int main()
{
    setlocale(LC_ALL, "rus");
    double rel = 36, imag = 9;
    const int n = 10;
    // массив из комплексных чисел
    ComplexNumber* arr = new ComplexNumber[n];
    arr[0].set_num(rel, imag);
    arr[1].set_num(0, 0);
    cout << "Комплексное число №1: " << arr[0].get_tostring() << endl;
    cout << "Реальная часть = " << arr[0].get_r() << ". Мниная часть = " << arr[0].get_i() << endl;
    cout << "Модуль = " << arr[0].get_modul() << endl;
    try {
        cout << ". Аргумент = " << arr[1].get_arg() << endl;
    }
    catch (logic_error err) {
        cout << "Ошибка при нахождении аргумента! " << err.what() << endl;
    }
    cout << "Комплексное число №2: " << arr[1].get_tostring() << endl;
    cout << "Сумма этих чисел = " << (arr[0] + arr[1]).get_tostring() << endl;
    cout << "Разность этих чисел = " << (arr[0] - arr[1]).get_tostring() << endl;
    cout << "Произведение этих чисел = " << (arr[0] * arr[1]).get_tostring() << endl;
    try {
        cout << "Частное этих чисел = " << (arr[0] / arr[1]).get_tostring() << endl;
    }
    catch (logic_error err) {
        cout << "Ошибка при делении! " << err.what() << endl;
    }
    // массив из указателей
    ComplexNumber** ptr_arr = new ComplexNumber* [n];

    // Определение указателей
    for (int i = 0; i < n; i++)
        ptr_arr[i] = &arr[i];
    cout << "Указатель на первое число: "  << ptr_arr[0]->get_tostring() << endl;

    to_file("OOP_Class.txt", arr[0]);
    from_file("OOP_Class.txt", arr[n - 1]);
    cout << "Число из файла: " << arr[n-1].get_tostring() << endl;

    delete[]arr;
    delete[]ptr_arr;
    cout << endl;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
