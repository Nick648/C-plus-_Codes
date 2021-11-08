// Prak7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double method(double x, float t) {
    return x * x * exp((-1) * t * x);
}


double func(double a, double b, int n, float t, double h) {
    double f = 0;
    string s = "__________________________________";
    cout << s << endl << "|" << setw(10) << left << "i" << "|" << setw(10) << left << "x[i]" << "|" << setw(10) << left << "f(x)" << "|" << endl << s << endl;
    for (int i = 0; i < n; i++) {
        double k = method(a + i * h, t);
        cout << "|" << setw(10) << i << "|" << setw(10) << (a + i * h) << "|" << setw(10) << setprecision(4) << k << "|" << endl;
        cout << s << endl;
        f += k;
    }
    cout << endl;
    return f * h;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Функция x^2*e^(-tx)\nПределы интегрирования: a = -1; b = 1;" << endl;
    cout << "Парметр функции: t = 0.5, 1.0, 1.5, 2.0" << endl;
    cout << "Введите кол-во элементарных отрезков, на которые разделяем [a,b]. n: ";
    int n;
    double a = -1, b = 1;
    cin >> n;
    if (n < 1) {
        cout << "ERROR!" << endl;
        return 0;
    }
    double h = (b - a) / n;
    cout << "Шаг равен h = " << h << endl;
    for (float t = 0.5; t <= 2.0; t += 0.5) {
        cout << endl << "t = " << t << ": " << endl;
        double f = func(a, b, n, t, h);
        cout << setprecision(6) <<  "Интеграл f = " << f << endl;
    }
    return (0);
}