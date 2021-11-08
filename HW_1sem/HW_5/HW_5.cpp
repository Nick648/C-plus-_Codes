﻿// HW_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <Windows.h>
#include <vector>
#include <map>
using namespace std;
string location = "C:\\Users\\Dima\\Desktop\\"; //Global Путь!

string chis() //Число ли?
{
	string s;
	while (true)
	{
	a:
		cout << "Введите число" << endl;
		cin >> s;
		if (s != "")
		{
			if (s.find_first_of(".") == s.find_last_of(".") && s.find_first_of(",") > s.length())
			{
				for (int i = 0; i < s.length(); i++)
				{
					if ((int(s[i]) < 48 || int(s[i]) > 57) && int(s[i]) != 46 && int(s[0]) != 45)
					{
						cout << "Вы ввели не число(" << endl;
						goto a;
					}
				}
				break;
			}
			else
			{
				cout << "Вы ввели не число(\nЕсли Вы пытались ввести вещественное число, то сделайте это через точку." << endl;
				goto a;
			}
		}
		else
		{
			cout << "Вы ввели пустую строку(" << endl;
			goto a;
		}
	}
	return s;
}

bool intchis(string s) //Целостность числа
{
	if (s.find_first_of(".") > s.length())
		return true;
	else
	{
		cout << "Вы ввели вещественное число(" << endl;
		return false;
	}
}

bool polchis(string s) //Положительность числа
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

string provfile(string filename) //Существует ли файл?
{
	string input;
	if (filename.length() > 4)
	{
		if (filename.substr(filename.length() - 4) == ".txt")
			filename = filename.erase(filename.length() - 4);
	}
	ifstream file;
	file.open(location + filename + ".txt");
	if (!file)
	{
		cout << "Файл не открыт\nНадо создать.\nВведите содержимое файла, для окончания ввода введите: ENDTEXT.\n";
		ofstream file(location + filename + ".txt");
		getline(cin, input);
		while (input != "ENDTEXT")
		{
			file << input << "\n";
			getline(cin, input);
		}
		file.close();
		cout << "Файл создан на рабочес столе." << endl;
	}
	else
		cout << "Все ОК! Файл открыт!\n\n";
	return filename;
}

int z1_1(int a, int b)
{
	if (a < b)
		swap(a, b);
	while (a % b != 0) {
		a = a % b;
		swap(a, b);
	}
	return b;
}

int z1_2(int a, int b)
{
	int t;
	while (a != b) {
		if (a > b) {
			t = a;
			a = b;
			b = t;
		}
		b = b - a;
	}
	return a;
}

void z1()
{
	system("cls");
	cout << "Задача №1: «Алгоритм Евклида». " << endl;
	int a, b;
	string s;
	s = chis();
	while (!intchis(s))
		s = chis();
	a = atoi(s.c_str());
	s = chis();
	while (!intchis(s))
		s = chis();
	b = atoi(s.c_str());
	cout << "НОД чисел делением равен: " << z1_1(a, b) << endl;
	cout << "НОД чисел вычитанием равен: " << z1_2(a, b) << endl;
}

void z2()
{
	system("cls");
	cout << "Задача №2: «Решето Эратосфена»." << endl;
	int n, k, sum = 0;
	cout << "Введите число, до которого ищем простые числа. P.S. Оно должно быть больше 2-х. : " << endl;
	string s = chis();
	while (!intchis(s) || atoi(s.c_str()) < 2)
		s = chis();
	n = atoi(s.c_str());
	for (int i = 2; i < n + 1; i++)
	{
		k = 0;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
				k = 1;

		}
		if (k == 0)
		{
			cout << setw(5) << i;
			sum++;
			if (sum % 15 == 0)
				cout << endl << endl;
		}
	}
	cout << endl;
}

void z3_1()
{
	system("cls");
	cout << "Задача №3.1: Замена пробелов на другие(определенные) символы.\nВведите имя файла" << endl;
	string input, filename, ch;
	vector <string> lines;
	//getline(cin, filename);
	cin >> filename;
	filename = provfile(filename);
	cout << "Введите символ, на который будем заменять пробелы:" << endl;
	cin >> ch;
	if (ch.length() > 1)
		ch = ch.erase(ch.length() - (ch.length() - 1));
	ifstream infile(location + filename + ".txt");
	while (!infile.eof())
	{
		getline(infile, input);
		lines.push_back(input);
	}
	for (int i = 0; i < lines.size(); i++)
	{
		input = lines[i];
		for (int j = 0; j < input.length(); j++)
		{
			if (input[j] == ' ')
				input.replace(j, 1, ch);
		}
		lines[i] = input;
	}
	infile.close();
	ofstream outfile(location + filename + ".txt");
	for (auto line : lines)
		outfile << line << '\n';
	outfile.close();
	cout << "Готово!" << endl;
}

void z3_2()
{
	system("cls");
	cout << "Задача №3.27: Вычисление частоты повтора символа в текстовом файле.\nВведите имя файла" << endl;
	string input, filename, ch;
	double k = 0, x = 0;
	//getline(cin, filename);
	cin >> filename;
	filename = provfile(filename);
	cout << "Введите символ, частоту которого будем считать.:" << endl;
	cin >> ch;
	ifstream infile(location + filename + ".txt");
	while (!infile.eof())
	{
		getline(infile, input);
		for (int i = 0; i < input.length(); i++)
		{
			if (int(input[i]) == int(ch[0]))
				x++;
			k++;
		}
	}
	if (k == 0)
		cout << "Файл пуст, подсчитать частоту повтора символа в текстовом файле невозможно! " << endl;
	else
	{
		cout << "Всего символов в данном файле: " << k << endl << "Символов '" << ch[0] << "' в данном файле: " << x << endl;
		cout << "частоты повтора символа '" << ch[0] << "' в текстовом файле: " << x / k << endl;
	}
}

void z3()
{
	system("cls");
	cout << "Задача №3: «Обработка текстовых файлов»." << endl;
	int num;
	while (true)
	{
		cout << "Введите номер желаемой задачи:\n1) Задача №1\n2) Задача №27\nДля выхода нажмите - Esc."
			<< endl;
		num = _getch();
		if (char(num) == '1')
			z3_1();
		else if (char(num) == '2')
			z3_2();
		else if (num == 27)
			break;
		else
		{
			cout << "Такого варианта нет, введите пожалуйста другой." << endl;
			continue;
		}
		return;
	}
}

int factorial(int n)
{
	if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

long facty(int n)
{
	if (n == 0)
		return 1;
	else
	{
		double sinx = 0;
		for (int i = 2; i <= 2 * n; i++)
		{
			if (i % 2 == 0)
				sinx += sin(i);
		}
		return (factorial(n) / sinx) * facty(n - 1);
	}
}

void z4_1()
{
	system("cls");
	cout << "Задача №4.3: Вычисление: y = 1!/sin(2) *...* n!/(sin(2) +...+ sin(2n)) \nВведите положительно число n:" << endl;
	int n;
	string s;
	s = chis();
	while (!intchis(s) || !polchis(s))
		s = chis();
	n = atoi(s.c_str());
	cout << "Данный ряд равен: " << facty(n) << endl;
}

void z4_2()
{
	system("cls");
	cout << "Задача №4.45-47: Вводит по строкам с клавиатуры двумерный квадратный массив и вычисляет суммы." << endl
		<< "Введите положительно число n(количество строк и столбцов(матрица квадратная)):" << endl;
	int n;
	string s;
	s = chis();
	while (!intchis(s) || !polchis(s))
		s = chis();
	n = atoi(s.c_str());
	double sumdig = 0;
	double* sumrow = new double[n];
	double* sumcolumn = new double[n];
	double** A = new double* [n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new double[n];
		sumrow[i] = 0;
		sumcolumn[i] = 0;
	}
	cout << "Ввод данных: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << i + 1 << "-я строка ";
			cout << j + 1 << "-й столбец:  ";
			cin >> A[i][j];
			sumrow[i] += A[i][j];
			sumcolumn[j] += A[i][j];
			if (i == j)
				sumdig += A[i][j];
			else if ((i + j) == (n - 1))
				sumdig += A[i][j];
		}
		cout << endl;
	}
	cout << "\nТакая матрица получилась.\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(6) << A[i][j];
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Сумма элементов в " << i + 1 << " строке равна: " << sumrow[i] << "     ";
		cout << "Сумма элементов в " << i + 1 << " столбце равна: " << sumcolumn[i] << endl;
	}
	cout << "Сумма диагональных элементов матрицы равна: " << sumdig << endl;
}

void z4()
{
	system("cls");
	cout << "Задача №4: «Ряды»." << endl;
	int num;
	while (true)
	{
		cout << "Введите номер желаемой задачи:\n1) Задача №3\n2) Задача №45-47\nДля выхода нажмите - Esc."
			<< endl;
		num = _getch();
		if (char(num) == '1')
			z4_1();
		else if (char(num) == '2')
			z4_2();
		else if (num == 27)
			break;
		else
		{
			cout << "Такого варианта нет, введите пожалуйста другой." << endl;
			continue;
		}
		return;
	}
}

map <string, string> sort1(string filename)
{
	map <string, string> sl;
	string input, s1, s2;
	ifstream infile(location + filename + ".txt");
	while (!infile.eof())
	{
		getline(infile, input);
		if (input.empty())
			continue;
		s1 = input.substr(0, input.find_first_of(" "));
		s2 = input.substr(input.find_first_of(" "));
		sl[s1] = s2;
	}
	infile.close();
	return sl;
}

map <string, string> sort2(string filename)
{
	map <string, string> sl;
	string input, s1, s2;
	ifstream infile(location + filename + ".txt");
	while (!infile.eof())
	{
		getline(infile, input);
		if (input.empty())
			continue;
		s1 = input.substr(0, input.find_first_of(" "));
		s2 = input.substr(input.find_first_of(" "));
		sl[s2] = s1;
	}
	infile.close();
	return sl;
}

void vyvod(string filename)
{
	string input;
	ifstream infile(location + filename + ".txt");
	while (infile)
	{
		getline(infile, input);
		cout << input << endl;
	}
	infile.close();
}

void z5()
{
	system("cls");
	cout << "Задача №5.10: «Файлы»(Фамилии студентов и их шифры).\nВведите имя файла" << endl;
	string input, filename, s1, s2;
	map <string, string> sl;
	int k;
	//getline(cin, filename);
	cin >> filename;
	if (filename.length() > 4)
	{
		if (filename.substr(filename.length() - 4) == ".txt")
			filename = filename.erase(filename.length() - 4);
	}
	ofstream file(location + filename + ".txt");
	cout << "Вводите фамилии и шифр построчно. Для окончания ввода введите: 'ENDTEXT'." << endl;
	getline(cin, input);
	while (input != "ENDTEXT")
	{
		if (input.find_first_of(" ") != input.find_last_of(" ") || input[0] == ' ' || input[input.length()] == ' ' || input.find_first_of(" ") > input.length() || input.empty())
			cout << "Надо ввести только фамилию и шифр!" << endl;
		else
			file << input << "\n";
		getline(cin, input);
	}
	file.close();
	cout << "Файл создан на рабочес столе." << endl;
	int num;
	while (true)
	{
		cout << "Введите номер желаемой сортировки:\n1) По фамилиям\n2) По шифру"
			<< endl;
		num = _getch();
		if (char(num) == '1')
		{
			sl = sort1(filename);
			k = 1;
			break;
		}
		else if (char(num) == '2')
		{
			sl = sort2(filename);
			k = 2;
			break;
		}
		else
			cout << "Такого варианта нет, введите пожалуйста другой." << endl;
		system("pause");
		system("cls");
	}
	ofstream outfile(location + filename + ".txt");
	map <string, string> ::iterator it = sl.begin();
	outfile << "Фамилия  Шифр";
	for (int i = 0; it != sl.end(); it++)
	{  // выводим их
		if (k == 1)
			outfile << "\n" << it->first << " " << it->second;
		else
			outfile << "\n" << it->second << " " << it->first;
	}
	outfile.close();
	cout << "Отсортировано! \n" << endl;
	while (true)
	{
		cout << "Вывести отсортированный список?\n1) Да\n2) Нет"
			<< endl;
		num = _getch();
		if (char(num) == '1')
		{
			vyvod(filename);
			break;
		}
		else if (char(num) == '2')
			break;
		else
			cout << "Такого варианта нет, введите пожалуйста другой." << endl;
		system("pause");
		system("cls");
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