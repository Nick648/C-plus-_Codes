﻿// HW_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
#define _USE_MATH_DEFINES
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <math.h>
#include <iomanip>
using namespace std;
string location = "C:\\Users\\Dima\\Desktop\\"; //Global Путь!

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
					cout << "Вы ввели не число(" << endl;
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
		cout << "Вы ввели пустую строку(" << endl;
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
			cout << "Вы ввели отрицательное число(" << endl;
			return false;
		}
	}
	else
		return false;
}

bool intchis(string s) //Целостность числа
{
	if (chis(s))
	{
		if (s.find_first_of(".") > s.length())
			return true;
		else
		{
			cout << "Вы ввели вещественное число(" << endl;
			return false;
		}
	}
	else
		return false;
}

void z1()
{
	system("cls");
	string filename, str;
	double mass[10], sum = 0;
	cout << "Задача №1: «Файл». \nВведите имя файла" << endl;
	getline(cin, filename);
	cout << "Введите ваши 10 чисел" << endl;
	for (int i = 0; i < 10; i++)
	{
	a:
		cout << "Введите число" << endl;
		cin >> str;
		if (!chis(str))
			goto a;
		mass[i] = atof(str.c_str());
	}
	ofstream file;
	file.open(location + filename + ".txt");
	for (int i = 0; i < 10; i++) // записываем в файл цифры
	{
		file << mass[i] << " ";
	}
	file.close();
	file.clear(); // окончили запись файла
	cout << "Файл успешно записан" << endl;
	ifstream file2(location + filename + ".txt");
	for (int i = 0; i < 10; i++) // читаем из файла массив и считаем их сумму
	{
		file2 >> mass[i];
		sum = sum + mass[i];
	}
	file2.close();
	cout << "Сумма Ваших чисел равна: " << sum << endl;
}

void z2_2(double n)
{
	if (n > 0)
		cout << "sign x = 1" << endl;
	else if (n == 0)
		cout << "sign x = 0" << endl;
	else
		cout << "sign x = -1" << endl;
}

void z2()
{
	system("cls");
	string str;
	cout << "Задача №2: «Знак числа». " << endl;
a:
	cout << "Введите число" << endl;
	cin >> str;
	if (!chis(str))
		goto a;
	double n = atof(str.c_str());
	z2_2(n);
}

double z3_1(double a, double h)
{
	return (a * h / 2);
}

double z3_2(double r)
{
	return (M_PI * pow(r, 2));
}

double z3_3(double a, double b)
{
	return (a * b);
}

void z3()
{
	system("cls");
	double a, h, r;
	int p = 0;
	string str;
	cout << "Задача №3: «Геометрические фигуры». " << endl;
	cout << "Выберете фигуру, площадь которой желаете найти:\n1) Треугольник\n2) Круг\n3) Прямоугольник" << endl;
	int num = _getch();
	if (char(num) == '1')
	{
	a:
		cout << "Введите основание треугольника a" << endl;
		cin >> str;
		if (!polchis(str))
			goto a;
		a = atof(str.c_str());

	b:
		cout << "Введите высоту h треугольника, проведённую к стороне a" << endl;
		cin >> str;
		if (!polchis(str))
			goto b;
		h = atof(str.c_str());
		cout << "Площадь треугольника вычисляется по формуле: S = a*h/2 и равна: " << z3_1(a, h) << endl;
	}
	else if (char(num) == '2')
	{
	c:
		cout << "Введите радиус окружности" << endl;
		cin >> str;
		if (!polchis(str))
			goto c;
		r = atof(str.c_str());
		cout << "Площадь круга вычисляется формуле: S = pi*r^2 и равна: " << z3_2(r) << endl;
	}
	else if (char(num) == '3')
	{
	d:
		cout << "Введите cторону a вашего прямоугольника" << endl;
		cin >> str;
		if (!polchis(str))
			goto d;
		a = atof(str.c_str());
	e:
		cout << "Введите cторону b вашего прямоугольника" << endl;
		cin >> str;
		if (!polchis(str))
			goto e;
		h = atof(str.c_str());
		cout << "Площадь прямоугольника вычисляется по формуле: S = a*b и равна: " << z3_3(a, h) << endl;
	}
}

void z4()
{
	system("cls");
	cout << "Задача №4: «Былая слава». " << endl;
	cout << endl;
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if ((i < 6) && (j < 8))
				cout << "* ";
			else
				cout << "--";
			Sleep(10);
		}
		cout << endl;
	}
}

void z5()
{
	system("cls");
	cout << "Задача №5: «Синусоида». " << endl;
	HWND myconsole = GetConsoleWindow();
	HDC dc = GetDC(myconsole);
	//SelectObject(dc, GetStockObject(DC_BRUSH));
	//SetDCBrushColor(dc, RGB(0, 255, 0));
	HDC linex = GetDC(myconsole);
	HDC liney = GetDC(myconsole);
	HDC singraph = GetDC(myconsole);
	COLORREF greenCOLOR = RGB(0, 255, 0);
	COLORREF redCOLOR = RGB(255, 0, 0);
	int pxl = 0;
	for (int i = 200; i <= 630; i++)
		SetPixel(linex, i, 250, greenCOLOR);
	for (int i = 100; i <= 400; i++)
		SetPixel(liney, 200, i, greenCOLOR);
	for (double i = 0; i < 16; i += 0.04)
	{
		SetPixel(singraph, 200 + pxl, 250 + 60 * sin(i), redCOLOR);
		pxl++;
	}
}

void z6()
{
	system("cls");
	string str;
	int sum = 0;
	cout << "Задача №6: «Автоматный распознаватель»." << endl;
	cout << "I = 1; V = 5; X = 10; L = 50; C = 100; D = 500; M = 1000" << endl;
a:
	cout << "Введите ваше число в римской СС" << endl;
	//getline(cin, str);
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != 'I' && str[i] != 'V' && str[i] != 'X' && str[i] != 'L' && str[i] != 'C' && str[i] != 'D' && str[i] != 'M')
		{
			cout << "Таких символов нет в римской СС " << endl;
			cin.clear();
			goto a;
		}
	}
	if (str.length() > 1)
	{
		for (int i = 0; i < str.length() - 1; i++)
			if (int(str[i]) == int(str[i + 1]) && (int(str[i]) == 68 || int(str[i]) == 76 || int(str[i]) == 86))
			{
				cout << "Такого числа нет в римской СС" << endl;
				cin.clear();
				goto a;
			}
	}
	if (str.length() >= 4)
	{
		for (int i = 0; i < str.length() - 3; i++)
			if (int(str[i]) == int(str[i + 1]) && int(str[i]) == int(str[i + 2]) && int(str[i]) == int(str[i + 3]) && (int(str[i]) == 67 || int(str[i]) == 73 || int(str[i]) == 77 || int(str[i]) == 88))
			{
				cout << "Такого числа нет в римской СС" << endl;
				goto a;
			}
	}
	int* dstr = new int[str.length()];
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'M')
			dstr[i] = 1000;
		else if (str[i] == 'D')
			dstr[i] = 500;
		else if (str[i] == 'C')
			dstr[i] = 100;
		else if (str[i] == 'L')
			dstr[i] = 50;
		else if (str[i] == 'X')
			dstr[i] = 10;
		else if (str[i] == 'V')
			dstr[i] = 5;
		else if (str[i] == 'I')
			dstr[i] = 1;
	}
	if (str.length() == 1)
		cout << "Ваше число в арабской СС " << dstr[0] << endl;
	else if (str.length() == 2)
	{
		if ((dstr[1] > dstr[0]) && (dstr[0] == 1 || dstr[0] == 10 || dstr[0] == 100))
			sum = dstr[1] - dstr[0];
		else
			sum = dstr[1] + dstr[0];
		cout << "Ваше число в арабской СС " << sum << endl;
	}
	else
	{
		for (int i = 1; i < str.length() - 1; i++)
		{
			if ((dstr[i] < dstr[i + 1]) && (dstr[i] == 1 || dstr[i] == 10 || dstr[i] == 100))
				sum += (dstr[i + 1] - dstr[i]);
			else
				sum += (dstr[i] + dstr[i + 1]);
		}
		cout << "Ваше число в арабской СС " << sum + dstr[0] << endl;
	}
}

/*int z7_1(int i)
{
	if (i == 0)
		return 0;
	return (37 * z7_1(i - 1) + i - 1) % 64;
}*/

void z7()
{
	system("cls");
	cout << "Задача №7: «Генератор псевдослучайных чисел»." << endl;
	cout << "I вариант " << endl;
	//cout << "Полученное число: " << z7_1(4) << endl;
	int s = 0;
	for (int i = 0; i < 4; i++)
	{
		s = (37 * s + i) % 64;
		cout << s << " ";
	}
	cout << endl;
}

void z8()
{
	system("cls");
	cout << "Задача №8: «Умножение матриц». " << endl;
	int n, m, p;
	string str;
	double cmax = 0, cmin = 10000000, imax = 0, imin = 0, maxk = 0, mink = 10000000, imaxk = 0, imink = 0, sumt = 0, sumk = 0, h;
	cout << "Введите количество продавцов товара" << endl;
	cin >> n;
	cout << "Введите количество наименований товара" << endl;
	cin >> m;
	int** A = new int* [n];
	for (int i = 0; i < n; i++)
		A[i] = new int[m];
	double** B = new double* [m];
	for (int i = 0; i < m; i++)
		B[i] = new double[2];
	double** C = new double* [n];
	for (int i = 0; i < n; i++)
		C[i] = new double[2];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "Введите количество товара, проданного продовцом №" << i + 1 << " наименованием товара №" << j + 1 << endl;
			cin >> p;
			A[i][j] = p;
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j == 0)
			{
				cout << "Введите цену товара №" << i + 1 << endl;
				cin >> h;
				B[i][0] = h;
			}
			else if (j == 1)
			{
				cout << "Введите комиссионные товара №" << i + 1 << endl;
				cin >> h;
				B[i][1] = h;
			}
		}
	}
	cout << endl << "Таблица A" << endl;
	cout << "Товар    №  ";
	for (int j = 0; j < m; j++)
		cout << "   " << j + 1 << " ";
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j == 0)
				cout << "Продавец №" << i + 1 << " ";
			cout << setw(5) << A[i][j];
		}
		cout << endl;
	}
	cout << endl << "Таблица B" << endl;
	cout << "Товар №" << " Цена " << " Комиссионные" << endl;;
	for (int i = 0; i < m; i++)
	{
		cout << "   " << i + 1 << setw(7) << B[i][0] << setw(7) << B[i][1];
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < m; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
	}
	cout << endl << "Таблица C" << endl;
	cout << "            " << "Заработал " << " Комиссионные" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j == 0)
				cout << "Продавец №" << i + 1 << " ";
			cout << setw(9) << C[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		if (C[i][0] > cmax)
		{
			cmax = C[i][0];
			imax = i;
		}
		if (C[i][0] < cmin)
		{
			cmin = C[i][0];
			imin = i;
		}
		if (C[i][1] > maxk)
		{
			maxk = C[i][1];
			imaxk = i;
		}
		if (C[i][1] < mink)
		{
			mink = C[i][1];
			imink = i;
		}
		sumt += C[i][0];
		sumk += C[i][1];
	}
	cout << endl << "Больше всего денег выручил продавец №" << imax + 1 << " ,он получил: " << cmax << endl;
	cout << "Меньше всего денег выручил продавец №" << imin + 1 << " ,он получил: " << cmin << endl;
	cout << "Больше всего комиссионных получил продавец №" << imaxk + 1 << " ,он получил: " << maxk << endl;
	cout << "Меньше всего комиссионных получил продавец №" << imink + 1 << " ,он получил: " << mink << endl;
	cout << "Всего с продажи продавцы получили: " << sumt << " чистой прибыли: " << endl;
	cout << "Всего с продажи продавцы получили: " << sumk << " комиссионных" << endl;
	cout << "Общая сумма, прошедшая через руки продавцов равна: " << sumt + sumk << endl;
	cout << "Общий доход продавцов составил: " << sumt - sumk << endl;
}

string digits(int num)
{
	switch (num) {
	case 0: return "0";
	case 1: return "1";
	case 2: return "2";
	case 3: return "3";
	case 4: return "4";
	case 5: return "5";
	case 6: return "6";
	case 7: return "7";
	case 8: return "8";
	case 9: return "9";
	case 10: return "A";
	case 11: return "B";
	case 12: return "C";
	case 13: return "D";
	case 14: return "E";
	case 15: return "F";
	}
}

string z9_1(int a, int cc2)
{
	int num = a;
	string s = "";
	while (num)
	{
		int rema = num % cc2;
		s = digits(rema) + s;
		num /= cc2;
	}
	return s;
}

void z9()
{
	system("cls");
	cout << "Задача №9: «Системы счисления»." << endl;
	string str, nstr;
	int p;
	int chislo = 0;
a:
	cout << "Введите число, которое хотите перевести" << endl;
	//getline(cin, str);
	cin >> str;
	int* dstr = new int[str.length()];
	p = str.length();
	for (int i = 0; i < p; i++)
	{
		if (str[i] == 'F')
			dstr[i] = 15;
		else if (str[i] == 'E')
			dstr[i] = 14;
		else if (str[i] == 'D')
			dstr[i] = 13;
		else if (str[i] == 'C')
			dstr[i] = 12;
		else if (str[i] == 'B')
			dstr[i] = 11;
		else if (str[i] == 'A')
			dstr[i] = 10;
		else if (str[i] == '9')
			dstr[i] = 9;
		else if (str[i] == '8')
			dstr[i] = 8;
		else if (str[i] == '7')
			dstr[i] = 7;
		else if (str[i] == '6')
			dstr[i] = 6;
		else if (str[i] == '5')
			dstr[i] = 5;
		else if (str[i] == '4')
			dstr[i] = 4;
		else if (str[i] == '3')
			dstr[i] = 3;
		else if (str[i] == '2')
			dstr[i] = 2;
		else if (str[i] == '1')
			dstr[i] = 1;
		else if (str[i] == '0')
			dstr[i] = 0;
		else
		{
			cout << "Неподходящее число(";
			delete[] dstr;
			goto a;
		}
	}
b:
	cout << "Введите CC вашего числа" << endl;
	cin >> nstr;
	if (!polchis(nstr) || !intchis(nstr))
		goto b;
	int cc = atoi(nstr.c_str());
	for (int i = 0; i < p; i++)
	{
		if (dstr[i] >= cc)
		{
			cout << "СС меньше, чем может быть для введенного числа! ";
			goto b;
		}
	}
	int j = p - 1;
	if (cc != 10)
	{
		for (int i = 0; i < p; i++)
		{
			chislo += dstr[i] * pow(cc, j);
			j--;
		}
	}
	else
		chislo = atoi(str.c_str());
с:
	cout << "Введите новую CC" << endl;
	cin >> nstr;
	if (!polchis(nstr) || !intchis(nstr))
		goto с;
	int cc2 = atoi(nstr.c_str());
	//char s[80] = {0};
	string s = z9_1(chislo, cc2);
	cout << s << endl;
}

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 900, 500, TRUE);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//setlocale(LC_ALL, "Russian");
	int num;
	while (true)
	{
		cout << "Введите номер желаемой задачи:\n1) Задача №1\n2) Задача №2\n3) Задача №3\n4) Задача №4\n5) Задача №5\n6) Задача №6\n7) Задача №7\n8) Задача №8\n9) Задача №9\nДля выхода нажмите - Esc."
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
		else if (char(num) == '6')
			z6();
		else if (char(num) == '7')
			z7();
		else if (char(num) == '8')
			z8();
		else if (char(num) == '9')
			z9();
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