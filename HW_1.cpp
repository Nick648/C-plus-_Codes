﻿// HW_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <conio.h>
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

bool chis(string s) //Число ли?
{
	if (s != "")
	{
		if (s.find_first_of(".") == s.find_last_of(".") && s.find_first_of(",") > s.length())
		{
			for (int i = 0; i < s.length(); i++)
			{
				if ((int(s[i]) < 48 || int(s[i]) > 57) && int(s[i]) != 46 && int(s[0]) != 45)
				{
					cout << "Вы ввели не число( " << endl;
					return false;
				}
			}
			return true;
		}
		else
		{
			cout << "Вы ввели не число(\nЕсли Вы пытались ввести вещественное число, то сделайте это через точку." << endl;
			return false;
		}
	}
	else
	{
		cout << "Вы ввели пустую строку( " << endl;
		return false;
	}
}

bool polchis(string s) //Положительность числа
{
	if (chis(s))
	{
		double n = atof(s.c_str());
		if (n > 0)
			return true;
		else
		{
			cout << "Вы ввели отрицательное число( " << endl;
			return false;
		}
	}
	else
		return false;
}

double vvod(string s) //Ввод значения и возврат
{
	string str;
	while (true)
	{
		cout << "Введите значение " << s << ": " << endl;
		cin >> str;
		if (chis(str))
			break;
	}
	return atof(str.c_str());
}

void z1()
{
	system("cls");
	string name;
	cout << "Задача №1: «Имя». \nВведите Ваше имя:" << endl;
	cin >> name;
	cout << "Добрый день, " << name << "!" << endl;
}

void z2()
{
	system("cls");
	cout << "Задача №2: «Арифметика»." << endl;
	double a = vvod("a");
	double b = vvod("b");
	cout << "Сумма: a + b = " << a + b << endl;
	cout << "Разность: a - b = " << a - b << endl;
	cout << "Разность: b - a = " << b - a << endl;
	cout << "Произведение: a * b = " << a * b << endl;
	if (b == 0)
	{
		cout << "Частное: a / b = Не существует" << endl;
		if (a != 0)
			cout << "Частное: b / a = " << b / a << endl;
		else 
			cout << "Частное: b / a = Не существует" << endl;
	}
	else if (a == 0)
	{
		if (b != 0)
			cout << "Частное: a / b = " << a / b << endl;
		else
			cout << "Частное: b / a = Не существует" << endl;
		cout << "Частное: b / a = Не существует" << endl;
	}
	else
	{
		cout << "Частное: a / b = " << a / b << endl;
		cout << "Частное: b / a = " << b / a << endl;
	}
}

void z3()
{
	system("cls");
	cout << "Задача №3: «Уравнение».\nbx + c = 0" << endl;
	double b = vvod("b");
	double c = vvod("c");
	if (b == 0 && c == 0)
		cout << "0 = 0\n" << "Ответ: х = (-oo; +oo)" << endl;
	else if (b == 0 && c != 0)
		cout << c << " = 0\n" << "Ответ: Решений нет" << endl;
	else
		cout << b << "x = " << c * -1 << endl << "Ответ: x = " << -c / b << endl;
}

void kVadr(double a, double b, double c)
{
	double D = (b * b) - (4 * a * c);
	if (a > 0)
		cout << "Парабола с ветвями вверх" << endl;
	else
		cout << "Парабола с ветвями вниз" << endl;
	double xv = -b / (2 * a);
	double yv = a * (xv * xv) + b * xv + c;
	cout << "С вершиной в точке: ( " << xv << "; " << yv << ")" << endl;
	cout << "Дискриминант: D = " << D << endl;
	if (D == 0)
	{
		cout << "Ответ: x = " << -b / (2 * a) << endl;
		return;
	}
	else if (D < 0)
	{
		cout << "Парабола не пересекает ось OX.\nОтвет: Решений нет" << endl;
		return;
	}
	cout << "Дискриминант под корнем: sqrt(D) = " << sqrt(D) << endl;
	double x1 = (-b + sqrt(D)) / (2 * a);
	double x2 = (-b - sqrt(D)) / (2 * a);
	cout << "Ответ: x1 = " << x1 << ";  x2 = " << x2 << endl;
}

void z4()
{
	system("cls");
	cout << "Задача №4: «Еще уравнение».\nax^2 + bx + c = 0" << endl;
	double a = vvod("a");
	double b = vvod("b");
	double c = vvod("c");
	if (a == 0 && b == 0 && c == 0)
		cout << "0 = 0\n" << "Ответ: х = (-oo; +oo)" << endl;
	else if (a == 0 && b == 0 && c != 0)
		cout << c << " = 0\n" << "Ответ: Решений нет" << endl;
	else if (a == 0 && b != 0 && c == 0)
		cout << "Ответ: x = 0" << endl;
	else if (a == 0 && b != 0 && c != 0)
		cout << b << "x = " << c * -1 << endl << "Ответ: x = " << -c / b << endl;
	else if (a != 0 && b == 0 && c == 0)
	{
		cout << a << "x^2 = 0" << endl;
		kVadr(a, b, c);
	}
	else if (a != 0 && b == 0 && c != 0)
	{
		cout << a << "x^2 = " << c * -1 << endl;
		kVadr(a, b, c);
	}
	else if (a != 0 && b > 0 && c == 0)
	{
		cout << a << "x^2 + " << b << "x = 0" << endl;
		cout << "Ответ: x1 = 0;  x2 = " << (b * -1) / a << endl;
	}
	else if (a != 0 && b > 0 && c > 0)
	{
		cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
		kVadr(a, b, c);
	}
	else if (a != 0 && b > 0 && c < 0)
	{
		cout << a << "x^2 + " << b << "x - " << -c << " = 0" << endl;
		kVadr(a, b, c);
	}
	else if (a != 0 && b < 0 && c == 0)
	{
		cout << a << "x^2 - " << -b << "x = 0 " << endl;
		kVadr(a, b, c);
	}
	else if (a != 0 && b < 0 && c > 0)
	{
		cout << a << "x^2 - " << -b << "x + " << c << " = 0" << endl;
		kVadr(a, b, c);
	}
	else if (a != 0 && b < 0 && c < 0)
	{
		cout << a << "x^2 - " << -b << "x - " << -c << " = 0" << endl;
		kVadr(a, b, c);
	}
}

void z5()
{
	system("cls");
	cout << "Задача №5: «Лампа со шторой»." << endl;
	int season, timeday, blind, lamp;
	while (true)
	{
		cout << "Введите время года:\n1) Лето\n2) Осень\n3) Зима\n4) Весна" << endl;
		season = _getch();
		if (char(season) != '1' && char(season) != '2' && char(season) != '3' && char(season) != '4')
			cout << "Всего 4 сезона!\nВыберите из предложенного." << endl;
		else
			break;
	}
	while (true)
	{
		cout << "Введите время суток:\n1) Утро\n2) День\n3) Вечер\n4) Ночь" << endl;
		timeday = _getch();
		if (char(timeday) != '1' && char(timeday) != '2' && char(timeday) != '3' && char(timeday) != '4')
			cout << "Всего 4 времнни суток!\nВыберите из предложенного." << endl;
		else
			break;
	}
	while (true)
	{
		cout << "Введите в каком состоянии находятся шторы:\n1) Раздвинуты\n2) Закрыты" << endl;
		blind = _getch();
		if (char(blind) != '1' && char(blind) != '2')
			cout << "Всего 2 состояния штор!\nВыберите из предложенного." << endl;
		else
			break;
	}
	while (true)
	{
		cout << "Введите в каком состоянии находится лампа:\n1) Включена\n2) Выключена" << endl;
		lamp = _getch();
		if (char(lamp) != '1' && char(lamp) != '2')
			cout << "Всего 2 состояния лампы!\nВыберите из предложенного.\nP.S. Если лампы нет, то она выключена." << endl;
		else
			break;
	}
	if (char(lamp) == '1')
		cout << "В комнате светло" << endl;
	else
	{
		if (char(season) == '1')
		{
			if ((char(timeday) == '1' || char(timeday) == '2' || char(timeday) == '3') && (char(blind) == '1'))
				cout << "В комнате светло" << endl;
			else 
				cout << "В комнате темно" << endl;
		}
		else
		{
			if (char(timeday) == '2' && char(blind) == '1')
				cout << "В комнате светло" << endl;
			else
				cout << "В комнате темно" << endl;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int num;
	while (true)
	{
		cout << "Введите номер желаемой задачи:\n1) Задача №1\n2) Задача №2\n3) Задача №3\n4) Задача №4\n5) Задача №5\nДля выхода нажмите - Esc."
			<< endl;
		num = _getch();
		if (char(num) == '1')
			z1();
		else if (char(num) == '2')
			z2();
		else if (char(num) == '3')
			z3();
		else if (char(num) == '4')
			z4();
		else if (char(num) == '5')
			z5();
		else if (num == 27)
			break;
		else
			cout << "Такого варианта нет, введите пожалуйста другой." << endl;
		system("pause");
		system("cls");
	}
	cout << "До свидания!" << endl;
	system("pause");
	return (0);
}