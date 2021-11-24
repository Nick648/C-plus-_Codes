// CourseWork.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Вариант 14

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <iomanip>
#include <vector>
#include <conio.h>

using namespace std;
string location = "C:\\Users\\Dima\\Desktop\\"; //Global Путь!


class Matrix {
    int n;
    int* matrix;

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
    
    void setN(int N);
    int sizeMat(int n);
    int index(int i, int j);
    int sizeDoubleMat(int n);
    int getSize();
};

int Matrix :: sizeMat(int n) { //Размер одномерного массива по размеру матрицы
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += i;
    }
    return s;
}

int Matrix :: sizeDoubleMat(int n) { //Размер двумерного массива по размеру матрицы
    for (int i = 1; i <= n; i++) {
        n -= i;
        if (n <= 0)
            return i;
    }
}

int Matrix :: index(int i, int j) { //Получение индекса одномерного массива по матрице
    int s = 0;
    int h = sizeDoubleMat(this->n);
    for (int k = 0; k < h; k++) {
        for (int f = k; f < h; f++) {
            if (k == i && f == j)
                return s;
            else
                s++;
        }
    }
}

int Matrix::getSize() { //Возврат значения размера массива
    return this->n;
}

Matrix :: Matrix(int n) //Создание верхней треугольной матрицы заданного размера с нулевыми значениями всех элементов (Конструктор)
{
    n = sizeMat(n);
    this->n = n;
    int* matrix = new int[n];
    for (int i = 0; i < n; i++) {
         matrix[i] = 0;
    }
    this->matrix = matrix;
}

void Matrix :: setEl(int i, int j) { //Установка значения элемента матрицы с индексами i, j; 
    int a, s;
    while (true) {
        cout << "Введите значение элемента матрицы: ";
        cin >> a;
        if (j < i and a != 0) {
            system("cls");
            cout << "Нижняя часть матрицы должа быть заполнена только нулями!\n" << endl;
        }
        else
            break;
    }
    if (i <= j) {
        s = index(i, j);
        this->matrix[s] = a;
    }
}

int Matrix::getEl(int i, int j) { //Получение значения элемента матрицы с индексами i, j; 
    if (i <= j) {
        int s;
        s = index(i, j);
        return this->matrix[s];
    }
    else
        return 0;
    
}

void Matrix :: inPut() //Построчный ввод матрицы; 
{
    int h = sizeDoubleMat(this->n);
    while (true) {
        cout << "Введите элементы матрицы построчно: " << endl;
        int a;
        bool flag = true;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < h; j++) {
                cin >> a;
                if (j < i && a != 0)
                    flag = false;
                else if (j >= i) {
                    int s = index(i, j);
                    this->matrix[s] = a;
                }
            }
        }
        if (flag)
            break;
        else {
            system("cls");
            cout << "Нижняя часть матрицы должа быть заполнена только нулями!\n" << endl;
            cout << "Введите значения матрицы снова(размер матрицы = " << h << ") : " << endl;
        }
    }
}

void Matrix :: outPut() //Построчный вывод на экран матрицы;
{
    int h = sizeDoubleMat(this->n);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < h; j++) {
            if (j >= i) {
                int s = index(i, j);
                cout << setw(4) << this->matrix[s] << " ";
            }
            else
                cout << setw(4) << 0 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

Matrix Matrix::difF(Matrix A, Matrix B) { //Разность двух треугольных матриц;
    if (A.n != B.n) {
        cout << "Разность двух матриц с различными размерами невозможна!\n" << endl;
        Matrix C(n);
        return C;
    }
    int h = sizeDoubleMat(A.n);
    Matrix C(h);
    for (int i = 0; i < A.n; i++) {
        C.matrix[i] = A.matrix[i] - B.matrix[i];
    }
    cout << "\nРазность двух матриц A и B: " << endl;
    C.outPut();
    return C;
}

void Matrix::simI(Matrix A, Matrix B) { //Проверка равенства двух матриц;
    if (A.n != B.n) {
        cout << "\nМатрицы разные по размерам!\n" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (A.matrix[i] != B.matrix[i]) {
            cout << "\nМатрицы разные!\n" << endl;
            return;
        }
    }
    cout << "\nМатрицы одинаковые\n" << endl;
    return;
}

void Matrix::writeFile(string filename) { //Запись матрицы в файл (первое число файла – размер матрицы);
    ofstream file;
    if (filename.length() > 4)
    {
        if (filename.substr(filename.length() - 4) == ".txt")
            filename = filename.erase(filename.length() - 4);
    }
    file.open(location + filename + ".txt");
    int h = sizeDoubleMat(this->n);
    file << h << "\n";
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < h; j++) {
            if (j >= i) {
                int s = index(i, j);
                file << setw(3) << this->matrix[s] << " ";
            }
            else
                file << setw(3) << 0 << " ";
        }
        file << "\n";
    }
    file.close();
    file.clear(); // Окончили запись файла
    cout << "Файл " << filename << " успешно записан\n" << endl;
}

bool openFile(string filename) { //Существование файла
    if (filename.length() > 4)
    {
        if (filename.substr(filename.length() - 4) == ".txt")
            filename = filename.erase(filename.length() - 4);
    }
    ifstream file;
    file.open(location + filename + ".txt");
    if (!file)
        return false;
    else
        return true;
}

void Matrix::readFile(string filename) { //Чтение матрицы из текстового файла (первое число файла – размер матрицы);
    string input;
    if (filename.length() > 4)
    {
        if (filename.substr(filename.length() - 4) == ".txt")
            filename = filename.erase(filename.length() - 4);
    }
    ifstream file;
    file.open(location + filename + ".txt");
    cout << "Все ОК! Файл открыт!\n\n";
    int i = 0;
    getline(file, input);
    int k = atoi(input.c_str());
    this -> setN(k);
    while (!file.eof())
    {
        getline(file, input);
        if (input != "") {
            for (int j = 0; j < k; j++) {
                int a = input.find(" ");
                string str = input.substr(0, a);
                if (j >= i) {
                    int s = index(i, j);
                    this -> matrix[s] = atoi(str.c_str());
                }
                input.erase(0, a + 1);
            }
            i++;
        }
    }
    file.close();
}

void Matrix::assignment(Matrix B) { //Присваивание одной матрицы другой.
    if (this->n != B.n) {
        cout << "\nМатрицы разные по размерам! Присваивание невозможно!\n" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        this -> matrix[i] = B.matrix[i];
    }
    cout << "\nПрисваивание B->A: " << endl;
    this->outPut();
}

void Matrix::setN(int N) { //Изменение параметров(размера) матрицы
    N = sizeMat(N);
    this -> n = N;
    int* matrix_1 = new int[n];
    for (int i = 0; i < n; i++) {
        matrix_1[i] = 0;
    }
    this -> matrix = matrix_1;
}

int vvodSizeMat() { //Проверка вводимого размера массива
    string str;
    while (true) {
        bool flag = true;
        cout << "\nВведите размер матрицы: ";
        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            if (!isdigit(str[i]))
                flag = false;
        }
        if (flag) {
            int n = atoi(str.c_str());
            if (n > 0)
                return n;
            else {
                system("cls");
                cout << "Надо ввести целое положительное(n > 0) число!" << endl;
            }
        }
        else {
            system("cls");
            cout << "Надо ввести целое положительное(n > 0) число!" << endl;
        }
    }
}

int getchOption(string s, int n) { //Выбор развития программы
    int num;
    while (true) {
        cout << s << endl;
        num = _getch();
        for (int i = 49; i < 49 + n; i++) { //char(49) == int(1)
            if (num == i)
                return num;
        }
        system("cls");
        cout << "Такого варианта нет, введите пожалуйста другой! (Предыдущий: " << char(num) << ")\n" << endl;;
    }
}

/*ГЛАВНАЯ ФУНКЦИЯ*/
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    vector < Matrix > matrixs;
    int num;

    while (true) { //Меню
        cout << "МЕНЮ. Выберите функцию:" << endl;
        cout << "1. Ввод матрицы" << endl;
        if (!matrixs.empty()) {
            cout << "2. Вывод матрицы" << endl;
            cout << "3. Установить значение элемента матрицы" << endl;
            cout << "4. Получить значение элемента матрицы" << endl;
            if (matrixs.size() > 1) {
                cout << "5. Разность(вычитание) двух матриц" << endl;
                cout << "6. Проверить равенство двух матриц" << endl;
                cout << "7. Присвоение одной матрицы к другой" << endl;
            }
        }
        cout << "Для выхода нажмите - Esc." << endl;
        num = _getch();

        if (char(num) == '1') { //Ввод
            system("cls");
            string option = "Ввод матрицы. Выберите функцию:\n1. Ввод матрицы с клавиатуры\n2. Ввод матрицы из файла";
            num = getchOption(option, 2);
            if (char(num) == '1') { //Клавиатура
                int n = vvodSizeMat();
                Matrix A(n);
                A.inPut();
                matrixs.push_back(A);
                cout << "\nМатрица создана и добавлена в список матриц!\n" << endl;
                system("pause");
                system("cls");
            }
            else if (char(num) == '2') { //Файл
                string filename;
                while (true) {
                    cout << endl << "Первое число в файле - это размер матрицы! ";
                    cout << "Введите имя файла: ";
                    cin >> filename;
                    //getline(cin, s); time!
                    if (openFile(filename)) {
                        Matrix A(1);
                        A.readFile(filename);
                        matrixs.push_back(A);
                        cout << "Матрица создана и добавлена в список матриц!\n" << endl;
                        break;
                    }
                    else {
                        system("cls");
                        cout << "Файл не создан! Надо создать заранее(сейчас)!\n" << endl;
                        break;
                    }
                }
                system("pause");
                system("cls");
            }
        }

        else if (char(num) == '2' and !matrixs.empty()) { //Вывод
            system("cls");
            string option = "Вывод матрицы. Выберите функцию:\n1. Вывод матрицы на консоль\n2. Вывод матрицы в файл";
            num = getchOption(option, 2);
            if (char(num) == '1') { //Консоль
                if (matrixs.size() > 1) {
                    while (true) {
                        int k;
                        cout << endl << "Матриц создано: 1-" << matrixs.size() << endl;
                        cout << "Выберите какую матрицу выводим(номер её): ";
                        cin >> k;
                        if (k > matrixs.size() or k < 1) {
                            string option = "Такой матрицы нет(  Желаете вывести их все?\n1. Да!\n2. Ноу\n3. Ввести другой номер";
                            num = getchOption(option, 3);
                            if (char(num) == '1') {
                                cout << endl;
                                for (int i = 0; i < matrixs.size(); i++) {
                                    cout << i+1 << ")" << endl;
                                    matrixs[i].outPut();
                                }
                                break;
                            }
                            else if (char(num) == '2')
                                break;
                            else if (char(num) == '3')
                                system("cls");
                        }
                        else {
                            cout << endl;
                            matrixs[k - 1].outPut();
                            break;
                        }
                    }
                }
                else {
                    cout << endl;
                    matrixs[0].outPut();
                }
                system("pause");
                system("cls");
            }
            else if (char(num) == '2') { //Файл
                string filename;
                cout << endl << "Введите название файла, в который будем записывать: ";
                cin >> filename;
                if (matrixs.size() > 1) {
                    while (true) {
                        int k;
                        cout << endl << "Матриц создано: 1-" << matrixs.size() << endl;
                        cout << "Выберите какую матрицу записываем(номер её): ";
                        cin >> k;
                        if (k > matrixs.size() or k < 1) {
                            string option = "Такой матрицы нет(  Желаете записать их все?\n1. Да!\n2. Ноу\n3. Ввести другой номер";
                            num = getchOption(option, 3);
                            if (char(num) == '1') {
                                matrixs[0].writeFile(filename);
                                for (int i = 1; i < matrixs.size(); i++) {
                                    cout << i + 1 << ") Введите название файла, в который будем записывать: ";
                                    cin >> filename;
                                    matrixs[i].writeFile(filename);
                                }
                                cout << "\nВсе матрицы записаны!\n" << endl;
                                break;
                            }
                            else if (char(num) == '2')
                                break;
                            else if (char(num) == '3')
                                system("cls");
                        }
                        else {
                            cout << endl;
                            matrixs[k - 1].writeFile(filename);
                            break;
                        }
                    }
                }
                else {
                    cout << endl;
                    matrixs[0].writeFile(filename);
                    cout << "Все ОК! В файл записано!\n" << endl;
                }
                system("pause");
                system("cls");
            }
        }

        else if (char(num) == '3' and !matrixs.empty()) { //Установка значения элемента
            int i, j, k = 1;
            if (matrixs.size() > 1) {
                while (true) {
                    cout << endl << "Матриц создано: 1-" << matrixs.size() << endl;
                    cout << "Выберите матрицу(номер её): ";
                    cin >> k;
                    if (k > matrixs.size() or k < 1) {
                        system("cls");
                        cout << "Такой матрицы нет(  Выберите из предложенного." << endl;
                    }
                    else
                        break;
                }
            }
            cout << "\nВыбранная матрица: " << endl;
            matrixs[k - 1].outPut();
            while (true) {
                int n = matrixs[k - 1].sizeDoubleMat(matrixs[k - 1].getSize());
                cout << "\nЗначения индексов матрицы [1;" << n << "]." << endl;
                cout << "Введите индексы элемента(строка и столбец): ";
                cin >> i >> j;
                if (i > n or j > n or i < 1 or j < 1) {
                    system("cls");
                    cout << "Индексы элемента должны быть меньше размера матрицы!\n" << endl;
                }
                else
                    break;
            }
            matrixs[k - 1].setEl(i-1, j-1);
            cout << "\nЗначение установлено!\n" << endl;
            system("pause");
            system("cls");
        }

        else if (char(num) == '4' and !matrixs.empty()) { //Получение значения элемента
            int i, j, k = 1;
            if (matrixs.size() > 1) {
                while (true) {
                    cout << endl << "Матриц создано: 1-" << matrixs.size() << endl;
                    cout << "Выберите матрицу(номер её): ";
                    cin >> k;
                    if (k > matrixs.size() or k < 1) {
                        system("cls");
                        cout << "Такой матрицы нет(  Выберите из предложенного." << endl;
                    }
                    else
                        break;
                }
            }
            while (true) {
                int n = matrixs[k - 1].sizeDoubleMat(matrixs[k - 1].getSize());
                cout << "\nЗначения индексов матрицы [1;" << n << "]." << endl;
                cout << "Введите индексы элемента(строка и столбец): ";
                cin >> i >> j;
                if (i > n or j > n or i < 1 or j < 1) {
                    system("cls");
                    cout << "Индексы элемента должны быть меньше размера матрицы!\n" << endl;
                }
                else
                    break;
            }
            int z = matrixs[k - 1].getEl(i - 1, j - 1);
            cout << "\nЗначение матрицы[" << i << ";" << j << "] = " << z << endl << endl;
            system("pause");
            system("cls");
        }

        else if (char(num) == '5' and matrixs.size() > 1) { //Вычитание двух матриц(разность)
            int k1, k2;
            while (true) {
                cout << endl << "Матриц создано: 1-" << matrixs.size() << endl;
                cout << "Выберите матрицу(уменьшаемое), которую уменьшаем(номер её): ";
                cin >> k1;
                if (k1 > matrixs.size() or k1 < 1) {
                    system("cls");
                    cout << "Такой матрицы нет(  Выберите из предложенного." << endl;
                }
                else
                    break;
            }
            while (true) {
                cout << endl << "Матриц создано: 1-" << matrixs.size() << endl;
                cout << "Выберите матрицу(вычитаемое), которой вычитаем(номер её): ";
                cin >> k2;
                if (k2 > matrixs.size() or k2 < 1) {
                    system("cls");
                    cout << "Такой матрицы нет(  Выберите из предложенного." << endl;
                }
                else
                    break;
            }
            int n1 = matrixs[k1 - 1].sizeDoubleMat(matrixs[k1 - 1].getSize());
            int n2 = matrixs[k2 - 1].sizeDoubleMat(matrixs[k2 - 1].getSize());
            if (n1 != n2) {
                Matrix C(n1);
                C = C.difF(matrixs[k1 - 1], matrixs[k2 - 1]);
            }
            else {
                Matrix C(n1);
                C = C.difF(matrixs[k1 - 1], matrixs[k2 - 1]);
                matrixs.push_back(C);
                cout << "Разность выполнена. Матрица записана в список всех матриц!\n" << endl;
            }
            system("pause");
            system("cls");
        }

        else if (char(num) == '6' and matrixs.size() > 1) { //Проверка равенства матриц
            int k1, k2;
            while (true) {
                cout << endl << "Матриц создано: 1-" << matrixs.size() << endl;
                cout << "Выберите 1-ю матрицу, для сравнения(номер её): ";
                cin >> k1;
                if (k1 > matrixs.size() or k1 < 1) {
                    system("cls");
                    cout << "Такой матрицы нет(  Выберите из предложенного." << endl;
                }
                else
                    break;
            }
            while (true) {
                cout << endl << "Матриц создано: 1-" << matrixs.size() << endl;
                cout << "Выберите 2-ю матрицу, для сравнения(номер её): ";
                cin >> k2;
                if (k2 > matrixs.size() or k2 < 1) {
                    system("cls");
                    cout << "Такой матрицы нет(  Выберите из предложенного." << endl;
                }
                else
                    break;
            }
            matrixs[k1 - 1].simI(matrixs[k1 - 1], matrixs[k2 - 1]);
            system("pause");
            system("cls");
        }

        else if (char(num) == '7' and matrixs.size() > 1) { //Присвоение матриц
            int k1, k2;
            while (true) {
                cout << endl << "Матриц создано: 1-" << matrixs.size() << endl;
                cout << "Выберите матрицу(A), в которую будем присваивать(номер её): ";
                cin >> k1;
                if (k1 > matrixs.size() or k1 < 1) {
                    system("cls");
                    cout << "Такой матрицы нет(  Выберите из предложенного." << endl;
                }
                else
                    break;
            }
            while (true) {
                cout << endl << "Матриц создано: 1-" << matrixs.size() << endl;
                cout << "Выберите матрицу(B), которую будем присваивать(номер её): ";
                cin >> k2;
                if (k2 > matrixs.size() or k2 < 1) {
                    system("cls");
                    cout << "Такой матрицы нет(  Выберите из предложенного." << endl;
                }
                else
                    break;
            }
            matrixs[k1 - 1].assignment(matrixs[k2 - 1]);
            system("pause");
            system("cls");
        }

        else if (num == 27) { //Если пользователь нажал - Esc
            system("cls");
            cout << "Спасибо за испольщование программы.\nХорошего дня!\n" << endl;
            system("pause");
            break;
        }

        else { //Ничего не выбрали из списка
            system("cls");
            cout << "Такого варианта нет, введите пожалуйста другой. (Предыдущий: " << char(num) << ")" << endl;;
        }
    }
}
