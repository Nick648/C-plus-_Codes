// Prak6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;
int n = 0;

int* input() //Ввод массива
{
	cout << "Количество элементов массива: ";
	cin >> n;
	while (n <= 0 or n > 100) {
		cout << "Неверный ввод значения n!" << endl << "n должен быть [1; 100]" << endl;
		cout << "Количество элементов массива: ";
		cin >> n;
	}
	int* a = new int[n];
	cout << "Значения элементов массива: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << endl;
	return a;
}

void output(int* a) { //Вывод массива
	cout << endl << "Массив a[]: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl << endl;
}

void f1(int* a) { //Кол-во чисел в диапазоне
	int x, y, k;
	do {
		cout << "Введите два числа диапазона [x,y]: ";
		cin >> x >> y;
		if (y >= x)
			break;
		else
			cout << "Значение y должно быть больше значения x!" << endl;
	} while (true);
	for (int i = x; i <= y; i++) {
		k = 0;
		for (int j = 0; j < n; j++) {
			if (a[j] == i)
				k++;
		}
		cout << "Кол-во числа " << i << " в массиве = " << k << endl;
	}
	cout << endl;
}

void f2(int* a) { //Добавление числа после максимального
	int x, s, max = -1000000;
	cout << "Введите число X, которое добавляем: ";
	cin >> x;
	for (int i = 0; i < n; i++) {
		if (a[i] >= max) {
			max = a[i];
			s = i + 1;
		}
	}
	n++;
	for (int j = n; j > s; j--) {
		a[j] = a[j - 1];
	}
	a[s] = x;
	output(a);
}

/*ГЛАВНАЯ ФУНКЦИЯ*/
int main()
{
	setlocale(LC_ALL, "Russian");
	int* a = new int[100];
	string p;
	while (true) {
		cout << "Выберите функцию:" << endl;
		cout << "1. Ввод массива" << endl;
		cout << "2. Вывод массива" << endl;
		cout << "3. Кол-во чисел диапазона" << endl;
		cout << "4. Добавление после MAX числа х" << endl;
		cout << "5. Завершение работы" << endl;
		cin >> p;
		if (p == "1")
			a = input();
		else if (p == "2")
			output(a);
		else if (p == "3")
			f1(a);
		else if (p == "4")
			f2(a);
		else if (p == "5") {
			cout << "Спасибо за испольщование программы.\nХорошего дня!" << endl;
			break;
		}
		else
			cout << "Такого варианта нет, введите пожалуйста другой." << endl;
	}
	return 0;
}