// CourseWork.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <iomanip>

using namespace std;
string location = "C:\\Users\\Dima\\Desktop\\"; //Global Путь!


class Matrix {
    int n;
    int** matrix;

public:
    Matrix(int n);
    void setEl(int i, int j);
    int getEl(int i, int j);
    void inPut();
    void outPut();
    Matrix difF(Matrix A, Matrix B);
    void simI(Matrix A, Matrix B);
    void writeFile(string s);
    void readFile(string filename);
    void assignment(Matrix B);
};

Matrix :: Matrix(int n)
{
    this->n = n;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
    this->matrix = matrix;
}

void Matrix :: setEl(int i, int j) {
    cout << "Введите значение элемента матрицы: ";
    int a;
    cin >> a;
    if (j < i) {
        while (a != 0) {
            cout << "Нижняя часть матрицы должа быть заполнена только нулями!\nВведите значение: ";
            cin >> a;
        }
    }
    this->matrix[i][j] = a;
}

int Matrix::getEl(int i, int j) {
    return matrix[i][j];
}

void Matrix :: inPut()
{
    while (true) {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
                if (j < i && matrix[i][j] != 0)
                    flag = false;
            }
        }
        if (flag)
            break;
        else
            cout << "Нижняя часть матрицы должа быть заполнена только нулями!\nВведите значения матрицы снова: " << endl;
    }
    
}

void Matrix :: outPut()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix Matrix::difF(Matrix A, Matrix B) {
    if (A.n != B.n) {
        cout << "Разность двух матриц с различными размерами невозможна!" << endl;
        Matrix C(n);
        return C;
    }
    int n = A.n;
    Matrix C(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
        }
    }
    cout << "Разность двух матриц A и B: " << endl;
    C.outPut();
    return C;
}

void Matrix::simI(Matrix A, Matrix B) {
    if (A.n != B.n) {
        cout << "Матрицы A и B разные по размерам!" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A.matrix[i][j] != B.matrix[i][j]) {
                cout << "Матрицы A и B разные!" << endl;
                return;
            }
        }
    }
    cout << "Матрицы A и B одинаковые" << endl;
    return;
}

void Matrix::writeFile(string s) {
    ofstream file;
    file.open(location + s + ".txt");
    file << s << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file << this->matrix[i][j] <<  "  ";
        }
        file << "\n";
    }
    file.close();
    file.clear(); // окончили запись файла
    cout << "Файл успешно записан" << endl;
}

void Matrix::readFile(string filename) {
    string input;
    if (filename.length() > 4)
    {
        if (filename.substr(filename.length() - 4) == ".txt")
            filename = filename.erase(filename.length() - 4);
    }
    ifstream file;
    file.open(location + filename + ".txt");
    if (!file)
        cout << "Файл не открыт\nНадо создать.\n";
    else
    {
        cout << "Все ОК! Файл открыт!\n\n";
        int i = 0;
        while (!file.eof())
        {
            getline(file, input);
            if (input != "") {
                for (int j = 0; j < this->n; j++) {
                    int a = input.find(" ");
                    string str = input.substr(0, a);
                    this->matrix[i][j] = atoi(str.c_str());
                    input.erase(0, a + 1);
                }
                i++;
            }

        }
        file.close();
    }
}

void Matrix::assignment(Matrix B) {
    if (this->n != B.n) {
        cout << "Матрицы A и B разные по размерам! Присваивание невозможно!" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            this->matrix[i][j] = B.matrix[i][j];
        }
    }
}

/*ГЛАВНАЯ ФУНКЦИЯ*/
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    int n, i, j;
    cout << "Введите размер матрицы A: ";
    cin >> n;
    Matrix A(n);
    A.readFile("matrixi");
    A.outPut();
    A.writeFile("matrixA");
    cout << "Введите размер матрицы B: ";
    cin >> n;
    Matrix B(n);
    cout << "Введите элементы матрицы B построчно: " << endl;
    B.inPut();
    Matrix C(n);
    C = A.difF(A, B);
    C.writeFile("DifAB");
    cout << "Присваивание C->A:" << endl;
    A.assignment(C);
    A.outPut();
    /*
    cout << "Введите размер матрицы A: ";
    cin >> n;
    Matrix A(n);
    A.outPut();
    cout << "Задайте координаты элемента: ";
    cin >> i >> j;
    A.setEl(i, j);
    cout << A.getEl(i, j);
    A.outPut();
    cout << "Введите элементы матрицы A построчно: " << endl;
    A.inPut();
    cout << "Введите размер матрицы B: ";
    cin >> n;
    Matrix B(n);
    cout << "Введите элементы матрицы B построчно: " << endl;
    B.inPut();
    Matrix C(n);
    C = A.difF(A, B);
    
    cout << "Матрица A: " << endl;
    A.outPut();
    cout << "Матрица B: " << endl;
    B.outPut();*/
}
