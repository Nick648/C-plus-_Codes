// Prak2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
// 5 вариант

/*ГЛАВНАЯ ФУНКЦИЯ*/
int main() {
	setlocale(LC_ALL, "Russian");
	int a[100], n, i, j, d, k = 0;
	cout << "Количество элементов: ";
	cin >> n;
	cout << "a: " << endl;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (a[0] % 2 == 0) { k++; }
	for (i = 0; i < n; i++) {
		if (a[i] % 2 == 0 && i != 0) {
			k++;
			d = a[i];
			for (j = i; j >= k; j--) {
				a[j] = a[j - 1];
			}
			a[k - 1] = d;
		}
		/*cout « endl « i+1 « "Проход" « endl;
		for(int s = 0; s < n; s++) {
		cout « a[s] « " ";
		}*/
	}
	cout << "Полученный массив: ";
	for (i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
