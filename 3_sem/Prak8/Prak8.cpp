// Prak8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>

using namespace std;
int n, m;

int** input(int a) {
    int** arr;
    arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    return arr;
}

string** input(string s) {
    string** arr;
    arr = new string * [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new string[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    return arr;
}

void output(int** arr) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void output(string** arr) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int** sorti(int** arr) {
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

string** sorti(string** arr) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            for (int k = j; k < m; k++) {
                string s1 = arr[i][j];
                string s2 = arr[i][k];
                if (s1[0] < s2[0]) {
                    swap(arr[i][j], arr[i][k]);
                }
            }
        }
    }
    return arr;
}

int main()
{
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    string s;
    cout << "Введите кол-во строк и столбцов массива: ";
    cin >> n >> m;
    if (n <= 0 || n > 100 || m <= 0 || m > 50) {
        cout << "ERROR!";
        return 0;
    }
    while (true) {
        cout << "\nChoose variant: \n1) String;\n2) Int;" << endl;
        cin >> s;
        if (s == "1") {
            cout << "Введите массив: " << endl;
            string** arr;
            arr = input("s");
            arr = sorti(arr);
            cout << "Отсортированный массив: " << endl;
            output(arr);
            break;
        }
        else if (s == "2") {
            cout << "Введите массив: " << endl;
            int** arr;
            arr = input(1);
            arr = sorti(arr);
            cout << "Отсортированный массив: " << endl;
            output(arr);            
            break;
        }
        else {
            cout << "Такого варианта нет!\n";
        }
    }

    return 0;
}
