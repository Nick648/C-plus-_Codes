// Prak3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m, k, ** arr;
	cout << "Ввод кол-ва строк и столбцов: ";
	cin >> n >> m;
	arr = new int* [n];
	int* b = new int[m];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
		cout << "Ввод " << i << "-ой строки массива: ";
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	cout << "Ввод массива b[m]: ";
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		k = 1;
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 0) {
				k = 0;
			}
		}
		if (k == 1) {
			for (int s = n; s > i; s--) {
				arr[s] = arr[s - 1];
			}
			arr[i + 1] = b;
			n++;
		}
	}
	cout << "Полученный массив:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}