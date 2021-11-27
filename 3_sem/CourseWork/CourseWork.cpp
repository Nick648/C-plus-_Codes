// CourseWork.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Вариант 14

#include "CourseWork.h"

using namespace std;

string location = string(getenv("USERPROFILE")) + "\\Desktop\\"; //Global Путь!
//string location = "C:\\Users\\Dima\\Desktop\\"; //Global Путь!
vector < Matrix > matrixs; //Global переменная

void SetColor(int text, int background) //Установка цвета
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

int Matrix::sizeMat(int n) { //Размер одномерного массива по размеру матрицы
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += i;
    }
    return s;
}

int Matrix::sizeDoubleMat(int n) { //Размер матрицы по размеру одномерного массива
    for (int i = 1; i <= n; i++) {
        n -= i;
        if (n <= 0)
            return i;
    }
}

int Matrix::index(int i, int j) { //Получение индекса одномерного массива по матрице
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

Matrix::Matrix(int n) //Создание верхней треугольной матрицы заданного размера с нулевыми значениями всех элементов (Конструктор)
{
    n = sizeMat(n);
    this->n = n;
    int* matrix = new int[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = 0;
    }
    this->matrix = matrix;
}

void Matrix::setEl(int i, int j) { //Установка значения элемента матрицы с индексами i, j; 
    int a, s;
    while (true) {
        cout << "Введите значение элемента матрицы: ";
        cin >> a;
        if (j < i and a != 0) {
            system("cls");
            SetColor(6, 0);
            cout << "Нижняя часть матрицы должа быть заполнена только нулями!\n" << endl;
            SetColor(15, 0);
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

void Matrix::inPut() //Построчный ввод матрицы; 
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
            SetColor(6, 0);
            cout << "Нижняя часть матрицы должа быть заполнена только нулями!\n" << endl;
            cout << "Введите значения матрицы снова(размер матрицы = " << h << "):\n " << endl;
            SetColor(15, 0);
        }
    }
}

void Matrix::outPut() //Построчный вывод на экран матрицы;
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
        SetColor(6, 0);
        cout << "Разность двух матриц с различными размерами невозможна!\n" << endl;
        SetColor(15, 0);
        Matrix C(n);
        return C;
    }
    int h = sizeDoubleMat(A.n);
    Matrix C(h);
    for (int i = 0; i < A.n; i++) {
        C.matrix[i] = A.matrix[i] - B.matrix[i];
    }
    SetColor(10, 0);
    cout << "\nРазность двух матриц A и B: " << endl;
    SetColor(15, 0);
    C.outPut();
    return C;
}

void Matrix::simI(Matrix A, Matrix B) { //Проверка равенства двух матриц;
    if (A.n != B.n) {
        SetColor(6, 0);
        cout << "\nМатрицы разные по размерам!\n" << endl;
        SetColor(15, 0);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (A.matrix[i] != B.matrix[i]) {
            SetColor(6, 0);
            cout << "\nМатрицы разные!\n" << endl;
            SetColor(15, 0);
            return;
        }
    }
    SetColor(10, 0);
    cout << "\nМатрицы одинаковые\n" << endl;
    SetColor(15, 0);
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
    file.close(); //Закрытие файла
    file.clear(); // Окончили запись файла
    SetColor(10, 0);
    cout << "Файл " << filename << " успешно записан на рабочем столе\n" << endl;
    SetColor(15, 0);
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

    if (!file) { //Файл не открыт
        system("cls");
        SetColor(6, 0);
        cout << "Файл не создан! Надо создать заранее(на рабочем столе)!\n" << endl;
        SetColor(15, 0);
        return;
    }
    else { //Файл открыт
        SetColor(10, 0);
        cout << "Все ОК! Файл открыт!\n\n";
        SetColor(15, 0);
    }

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
    file.close(); //Закрытие файла
    matrixs.push_back(*this);
    SetColor(10, 0);
    cout << "Матрица создана и добавлена в список матриц!\n" << endl;
    SetColor(15, 0);
}

void Matrix::assignment(Matrix B) { //Присваивание одной матрицы другой.
    if (this->n != B.n) {
        SetColor(6, 0);
        cout << "\nМатрицы разные по размерам! Присваивание невозможно!\n" << endl;
        SetColor(15, 0);
        return;
    }
    for (int i = 0; i < n; i++) {
        this -> matrix[i] = B.matrix[i];
    }
    SetColor(10, 0);
    cout << "\nПрисваивание B->A: " << endl;
    SetColor(15, 0);
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
                SetColor(6, 0);
                cout << "Надо ввести целое положительное(n > 0) число!" << endl;
                SetColor(15, 0);
            }
        }
        else {
            system("cls");
            SetColor(6, 0);
            cout << "Надо ввести целое положительное(n > 0) число!" << endl;
            SetColor(15, 0);
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
        SetColor(6, 0);
        cout << "Такого варианта нет, введите пожалуйста другой! (Предыдущий: " << char(num) << ")\n" << endl;
        SetColor(15, 0);
    }
}

void z1() { //Ввод
    system("cls");
    string option = "********Ввод матрицы**********\nВыберите функцию:\n1. Ввод матрицы с клавиатуры\n2. Ввод матрицы из файла";
    int num = getchOption(option, 2);
    if (char(num) == '1') { //Клавиатура
        int n = vvodSizeMat();
        Matrix A(n);
        A.inPut();
        matrixs.push_back(A);
        SetColor(10, 0);
        cout << "\nМатрица создана и добавлена в список матриц!\n" << endl;
        SetColor(15, 0);
        system("pause");
        system("cls");
    }
    else if (char(num) == '2') { //Файл
        string filename;
        cout << endl << "Первое число в файле - это размер матрицы! ";
        cout << "Введите имя файла: ";
        cin >> filename;
        Matrix A(1);
        A.readFile(filename);
        system("pause");
        system("cls");
    }
}

void z2_1() { //Вывод в консоль
    if (matrixs.size() > 1) {
        while (true) {
            int k;
            cout << endl << "Матриц создано: 1-" << matrixs.size() << endl;
            cout << "Выберите какую матрицу выводим(номер её): ";
            cin >> k;
            if (k > matrixs.size() or k < 1) {
                string option = "\nТакой матрицы нет(  Желаете вывести их все?\n1. Да!\n2. Ноу\n3. Ввести другой номер";
                int num = getchOption(option, 3);
                if (char(num) == '1') {
                    cout << endl;
                    for (int i = 0; i < matrixs.size(); i++) {
                        cout << i + 1 << ")" << endl;
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

void z2_2() { //Вывод в файл
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
                string option = "\nТакой матрицы нет(  Желаете записать их все?\n1. Да!\n2. Ноу\n3. Ввести другой номер";
                int num = getchOption(option, 3);
                if (char(num) == '1') {
                    matrixs[0].writeFile(filename);
                    for (int i = 1; i < matrixs.size(); i++) {
                        cout << i + 1 << ") Введите название файла, в который будем записывать: ";
                        cin >> filename;
                        matrixs[i].writeFile(filename);
                    }
                    SetColor(10, 0);
                    cout << "\nВсе матрицы записаны!\n" << endl;
                    SetColor(15, 0);
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
    }
    system("pause");
    system("cls");
}

void z2() { //Вывод
    system("cls");
    string option = "*******Вывод матрицы*********\nВыберите функцию:\n1. Вывод матрицы на консоль\n2. Вывод матрицы в файл";
    int num = getchOption(option, 2);
    if (char(num) == '1') //Консоль
        z2_1();

    else if (char(num) == '2') //Файл
        z2_2();
}

void z3() { //Установка значения элемента
    int i, j, k = 1;
    if (matrixs.size() > 1) {
        while (true) {
            cout << endl << "Матриц создано: 1-" << matrixs.size() << endl;
            cout << "Выберите матрицу(номер её): ";
            cin >> k;
            if (k > matrixs.size() or k < 1) {
                system("cls");
                SetColor(6, 0);
                cout << "Такой матрицы нет(  Выберите из предложенного." << endl;
                SetColor(15, 0);
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
            SetColor(6, 0);
            cout << "Индексы элемента должны быть меньше размера матрицы!\n" << endl;
            SetColor(15, 0);
        }
        else
            break;
    }
    matrixs[k - 1].setEl(i - 1, j - 1);
    SetColor(10, 0);
    cout << "\nЗначение установлено!\n" << endl;
    SetColor(15, 0);
    system("pause");
    system("cls");
}

void z4() { //Получение значения элемента
    int i, j, k = 1;
    if (matrixs.size() > 1) {
        while (true) {
            cout << endl << "Матриц создано: 1-" << matrixs.size() << endl;
            cout << "Выберите матрицу(номер её): ";
            cin >> k;
            if (k > matrixs.size() or k < 1) {
                system("cls");
                SetColor(6, 0);
                cout << "Такой матрицы нет(  Выберите из предложенного." << endl;
                SetColor(15, 0);
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
            SetColor(6, 0);
            cout << "Индексы элемента должны быть меньше размера матрицы!\n" << endl;
            SetColor(15, 0);
        }
        else
            break;
    }
    int z = matrixs[k - 1].getEl(i - 1, j - 1);
    SetColor(10, 0);
    cout << "\nЗначение матрицы[" << i << ";" << j << "] = " << z << endl << endl;
    SetColor(15, 0);
    system("pause");
    system("cls");
}

void z5() { //Вычитание двух матриц(разность)
    int k1, k2;
    while (true) {
        cout << endl << "Матриц создано: 1-" << matrixs.size() << endl;
        cout << "Выберите матрицу(уменьшаемое), которую уменьшаем(номер её): ";
        cin >> k1;
        if (k1 > matrixs.size() or k1 < 1) {
            system("cls");
            SetColor(6, 0);
            cout << "Такой матрицы нет(  Выберите из предложенного." << endl;
            SetColor(15, 0);
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
            SetColor(6, 0);
            cout << "Такой матрицы нет(  Выберите из предложенного." << endl;
            SetColor(15, 0);
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
        SetColor(10, 0);
        cout << "Разность выполнена. Матрица записана в список всех матриц!\n" << endl;
        SetColor(15, 0);
    }
    system("pause");
    system("cls");
}

void z6() { //Проверка равенства матриц
    int k1, k2;
    while (true) {
        cout << endl << "Матриц создано: 1-" << matrixs.size() << endl;
        cout << "Выберите 1-ю матрицу, для сравнения(номер её): ";
        cin >> k1;
        if (k1 > matrixs.size() or k1 < 1) {
            system("cls");
            SetColor(6, 0);
            cout << "Такой матрицы нет(  Выберите из предложенного." << endl;
            SetColor(15, 0);
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
            SetColor(6, 0);
            cout << "Такой матрицы нет(  Выберите из предложенного." << endl;
            SetColor(15, 0);
        }
        else
            break;
    }
    matrixs[k1 - 1].simI(matrixs[k1 - 1], matrixs[k2 - 1]);
    system("pause");
    system("cls");
}

void z7() { //Присвоение матриц
    int k1, k2;
    while (true) {
        cout << endl << "Матриц создано: 1-" << matrixs.size() << endl;
        cout << "Выберите матрицу(A), в которую будем присваивать(номер её): ";
        cin >> k1;
        if (k1 > matrixs.size() or k1 < 1) {
            system("cls");
            SetColor(6, 0);
            cout << "Такой матрицы нет(  Выберите из предложенного." << endl;
            SetColor(15, 0);
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
            SetColor(6, 0);
            cout << "Такой матрицы нет(  Выберите из предложенного." << endl;
            SetColor(15, 0);
        }
        else
            break;
    }
    matrixs[k1 - 1].assignment(matrixs[k2 - 1]);
    system("pause");
    system("cls");
}

void exi_t() { //Выход
    system("cls");
    SetColor(10, 0);
    cout << "Спасибо за испольщование программы.\nХорошего дня!\n" << endl;
    SetColor(15, 0);
    system("pause");
    exit(1);
}

void nothing(int num) { //Ничего не выбрали из списка
    SetColor(6, 0);
    system("cls");
    cout << "Такого варианта нет, введите пожалуйста другой. (Предыдущий: " << char(num) << ")\n" << endl;
    SetColor(15, 0);
}

/*ГЛАВНАЯ ФУНКЦИЯ*/
int main()
{
    /* //Установка размера шрифта
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(fontInfo);
    GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
    wcscpy(fontInfo.FaceName, L"Lucida Console");
    fontInfo.dwFontSize.Y = 15;
    SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
    */
    static const TCHAR* myTitle = TEXT("Upper Triangular Matrix"); //Установка заголовка консольного приложения
    SetConsoleTitle(myTitle);

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    int num;

    while (true) { //Меню
        cout << "**********МЕНЮ**********\nВыберите функцию:" << endl;
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

        if (char(num) == '1') //Ввод
            z1();

        else if (char(num) == '2' and !matrixs.empty()) //Вывод
            z2();

        else if (char(num) == '3' and !matrixs.empty()) //Установка значения элемента
            z3();

        else if (char(num) == '4' and !matrixs.empty()) //Получение значения элемента
            z4();

        else if (char(num) == '5' and matrixs.size() > 1) //Вычитание двух матриц(разность)
            z5();

        else if (char(num) == '6' and matrixs.size() > 1) //Проверка равенства матриц
            z6();

        else if (char(num) == '7' and matrixs.size() > 1) //Присвоение матриц
            z7();

        else if (num == 27) //Если пользователь нажал - Esc (Выход)
            exi_t();

        else //Ничего не выбрали из списка
            nothing(num);
    }
}
