// Prak10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int min(int* arr, int n, int b) {
    if (arr[n] < b)
        b = arr[n];
    if (n == 0)
        return b;
    return min(arr, n - 1, b);
}


int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите кол-во элементов: ";
    int n;
    cin >> n;
    if (n <= 0) { cout << "Error"; return 0; }
    int* arr = new int[n];
    cout << "Введите массив: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int b = arr[n - 1];
    b = min(arr, n - 1, b);
    cout << "Минимальное значение = " << b << endl;
    return 0;
}