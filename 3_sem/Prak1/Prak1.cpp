// Prak1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
// 5 вариант
using namespace std;

/*ГЛАВНАЯ ФУНКЦИЯ*/
int main()
{
	setlocale(LC_ALL, "Russian");
	double x, y, r, a;
	cout << "Радиус окружности и сторона квадрата: ";
	cin >> r >> a;
	cout << "Координаты x, y: ";
	cin >> x >> y;
	if (a * sqrt(2) <= 2 * r) {
		if (y <= sqrt(r * r - x * x) && abs(x) >= a / 2 && abs(y) >= a / 2)
			cout << "YES";
		else
			cout << "NO";
	}
	else
		cout << "Неверный рисунок";
	return 0;
}
