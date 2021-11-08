// Prak9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>

using namespace std;
int n, m;

template <class Type>
Type** input(Type** arr) {
    for (int i = 0; i < n; i++) {
        arr[i] = new Type[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << endl;
    return arr;
}


template <class Type1>
void output(Type1** arr) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(4) << arr[i][j] << " ";
        }
        cout << endl;
    }
}


template <class Type2>
Type2** sorti(Type2** arr) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            for (int k = j + 1; k < m; k++) {
                if (arr[i][j] < arr[i][k]) {
                    swap(arr[i][j], arr[i][k]);
                }
            }
        }
    }
    return arr;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    string s;
    cout << "Введите кол-во строк и столбцов массива: ";
    cin >> n >> m;
    if (n <= 0 || n > 100 || m > 50 || m <= 0) {
        cout << "Error";
        return 0;
    }
    while (true)
    {
        cout << "Choose the type\n1) Integer\n2) Float\n3) Char" << endl;
        cin >> s;
        if (s == "1") {
            int** arr = new int* [n];
            cout << "Введите массив: " << endl;
            arr = input(arr);
            arr = sorti(arr);
            cout << "Отсортированный массив: " << endl;
            output(arr);
            break;
        }
        else if (s == "2") {
            float** arr = new float* [n];
            cout << "Введите массив: " << endl;
            arr = input(arr);
            arr = sorti(arr);
            cout << "Отсортированный массив: " << endl;
            output(arr);
            break;
        }
        else if (s == "3") {
            char** arr = new char* [n];
            cout << "Введите массив: " << endl;
            arr = input(arr);
            arr = sorti(arr);
            cout << "Отсортированный массив: " << endl;
            output(arr);
            break;
        }
        else
            cout << "Такого варианта нет!\n";
    }
    return (0);
}