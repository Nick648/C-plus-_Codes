// HW_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <vector>
#include <algorithm>
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
                    cout << "Вы ввели не число( " << endl;
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
        cout << "Вы ввели пустую строку( " << endl;
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
            cout << "Вы ввели отрицательное число( " << endl;
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
            cout << "Вы ввели вещественное число( " << endl;
            return false;
        }
    }
    else
        return false;
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
        cout << "Файл не открыт\nНадо создать.\nВведите содержимое файла, для окончания ввода введиту пустую строку(просто нажмите Enter).\n";
        ofstream file(location + filename + ".txt");
        getline(cin, input);
        while (input != "")
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

void z1()
{
    system("cls");
    cout << "Задача №1: «Заем». " << endl;
    string str;
    while (true)
    {
        cout << "Введите значение: S - займ: " << endl;
        cin >> str;
        if (polchis(str))
            break;
    }
    double S = atof(str.c_str());
    while (true)
    {
        cout << "Введите значение: p - процент: " << endl;
        cin >> str;
        if (chis(str))
            if (atof(str.c_str()) >= 100 || atof(str.c_str()) <= 0)
                cout << "Процент должен быть: 0 < p < 100 " << endl;
            else
                break;
    }
    double p = atof(str.c_str());
    while (true)
    {
        cout << "Введите значение: n - количество лет: " << endl;
        cin >> str;
        if (chis(str))
            if (atof(str.c_str()) <= 0 || atof(str.c_str()) >= 100)
                cout << "Число не может быть отрицательным и больше 99 " << endl;
            else
                break;
    }
    double n = atof(str.c_str());
    cout << "Месячная выплата составит примерно: " << endl;
    cout << ((S * 0.01 * p) * pow((1 + 0.01 * p), n)) / (12 * (pow((1 + 0.01 * p), n) - 1)) << " рублей" << endl;
}

void z2()
{
    system("cls");
    cout << "Задача №2: «Ссуда». " << endl;
    double raz, needi;
    string str;
    while (true)
    {
        cout << "Введите значение: S - займ: " << endl;
        cin >> str;
        if (polchis(str))
            break;
    }
    double S = atof(str.c_str());
    while (true)
    {
        cout << "Введите значение: n - количество лет: " << endl;
        cin >> str;
        if (chis(str))
            if (atof(str.c_str()) <= 0 || atof(str.c_str()) >= 100)
                cout << "Число не может быть отрицательным и больше 99 " << endl;
            else
                break;
    }
    double n = atof(str.c_str());
    while (true)
    {
        cout << "Введите значение: m - месячную выплату: " << endl;
        cin >> str;
        if (polchis(str))
            break;
    }
    double m = atof(str.c_str());
    raz = abs(m - (((S * 0.01 * 0.1) * pow((1 + 0.01 * 0.1), n)) / (12 * (pow((1 + 0.01 * 0.1), n) - 1))));
    cout << "Процентная ставка примерно:" << endl;
    for (double i = 0.1; i <= 100; i += 0.1)
    {
        //cout << "-----> " << i << "%) " << (((S * 0.01 * i) * pow((1 + 0.01 * i), n)) / (12 * (pow((1 + 0.01 * i), n) - 1))) << endl;
        if (raz > abs(m - (((S * 0.01 * i) * pow((1 + 0.01 * i), n)) / (12 * (pow((1 + 0.01 * i), n) - 1)))))
        {
            raz = abs(m - (((S * 0.01 * i) * pow((1 + 0.01 * i), n)) / (12 * (pow((1 + 0.01 * i), n) - 1))));
            //cout << i << "%) " << raz << endl;
            needi = i;
        }
    }
    cout << needi << "%" << endl;
}

void z3()
{
    system("cls");
    cout << "Задача №3: «Копирование файла». " << endl;
    string filename, input;
    cout << "Введите имя файла" << endl;
    getline(cin, filename);
    ofstream file(location + filename + ".txt");
    cout << "Введите содеражние файла. Для окончания ввода введиту пустую строку(просто нажмите Enter)." << endl;
    getline(cin, input);
    while (input != "") //input != "ENDTEXT"
    {
        file << input << "\n";
        getline(cin, input);
    }
    file.close();
    //file.clear();
    cout << "Файл успешно записан и создан на рабочес столе." << endl;
    ifstream file2(location + filename + ".txt");
    while (file2)
    {
        getline(file2, input);
        cout << input << endl;
    }
    file2.close();
}

void z4()
{
    system("cls");
    cout << "Задача №4: «Фильтр». " << endl;
    string line, filename;
    cout << "Введите имя файла" << endl;
    getline(cin, filename);
    filename = provfile(filename);
    cout << "Ваши числа: " << endl;
    ifstream file2(location + filename + ".txt");
    while (file2)
    {
        getline(file2, line);
        for (int i = 0; i < line.length(); i++)
        {
            if (int(line[i]) > 47 && int(line[i]) < 58)
                cout << line[i] << " ";
        }
    }
    file2.close();
    cout << endl;
}

void z5()
{
    system("cls");
    cout << "Задача №5: «Сортировка букв». " << endl;
    string str, s = "";
    char t;
    vector <int> ascii;
    cout << "Введите строку, которую хотите получить в алфавитном порядке.\nМаксимум 30 букв" << endl;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != 32) //char(32) = " "
            if ((int(str[i]) > 64 && int(str[i]) < 91) || (int(str[i]) > 96 && int(str[i]) < 123) || (int(str[i]) > 127 && int(str[i]) < 176) 
                || (int(str[i]) > 224 && int(str[i]) < 240)) //Буквы
            {
                s += str[i];
                ascii.push_back(int(str[i]));
            }
        if (s.length() == 30)
            break;
    }
    cout << "Ваша строка:" << endl;
    for (int i = 0; i < s.length(); i++)
        cout << s[i] << " ";
    sort(ascii.begin(), ascii.end());
    cout << endl << "Ваша строка в алфавитном порядке" << endl;
    for (int i = 0; i < ascii.size(); i++)
        cout << char(ascii[i]) << " ";
    cout << endl;
}

int main()
{
    //setlocale(LC_ALL, "Russian");
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
    cout << "Всего хорошего!" << endl;
    system("pause");
    return (0);
}