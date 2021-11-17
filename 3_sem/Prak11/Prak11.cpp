// Prak11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;
string location = "C:\\Users\\Dima\\Desktop\\"; //Global Путь!

struct Order { //Структура заказ
    int number;
    string fio;
    string name;
    int k;
    int pay;
};

void outPut(Order* spisok) { //Вывод в консоль списка заказов
    for (int i = 0; i < 50; i++) {
        if (spisok[i].number >= 0)
            cout << spisok[i].number << " " << spisok[i].fio << endl;
    }
}

Order* sorti(Order* spisok) { //Сортировка списка
    for (int i = 0; i < 50 - 1; i++) {
        for (int k = i + 1; k < 50; k++) {
            if (spisok[i].number > spisok[k].number) {
                    swap(spisok[i], spisok[k]);
            }
        }
    }
    return spisok;
}

void search(Order* spisok) { //Бинарный поиск
    int key;
    cout << endl << "Введите номер заказа: ";
    cin >> key;
    bool flag = false;
    int l = 0; // левая граница
    int r = 49; // правая граница
    int mid;
    while ((l <= r) && (flag != true)) {
        mid = (l + r) / 2;

        if (spisok[mid].number == key) 
            flag = true;
        if (spisok[mid].number > key) 
            r = mid - 1; // проверяем, какую часть нужно отбросить
        else 
            l = mid + 1;
    }

    if (flag) 
        cout << "Номер заказа " << key << ": " << spisok[mid].fio << " " << spisok[mid].name << " " << spisok[mid].k << " " << spisok[mid].pay << endl;
    else 
        cout << "Извините, но такого элемента в массиве нет" << endl;
}

Order* provfile(string filename, Order* spisok) //Существует ли файл?
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
        cout << "Файл не открыт\nНадо создать.\n";
    else
    {
        cout << "Все ОК! Файл открыт!\n\n";
        int i = 0;
        while (!file.eof())
        {
            getline(file, input);
            if (input != "") {
                //Order* n;
                int a = input.find(" ");
                string str = input.substr(0, a);
                input.erase(0, a + 1);
                //cout << "number: " << str << endl;
                //cout << spisok[i].number << endl;
                spisok[i].number = atoi(str.c_str());
                //n->number = atoi(str.c_str());
                str = "";
                for (int i = 0; i < 3; i++) {
                    a = input.find(" ");
                    string str_1 = input.substr(0, a);
                    input.erase(0, a + 1);
                    if (i == 2)
                        str += str_1;
                    else
                        str = str + str_1 + " ";
                }
                //cout << "fio: " << str << endl;
                spisok[i].fio = str;
                a = input.find(" ");
                str = input.substr(0, a);
                input.erase(0, a + 1);
                //cout << "name: " << str << endl;
                spisok[i].name = str;
                //n->name = str;
                a = input.find(" ");
                str = input.substr(0, a);
                input.erase(0, a + 1);
                //cout << "k: " << str << endl;
                spisok[i].k = atoi(str.c_str());
                //n->k = atoi(str.c_str());
                a = input.find(" ");
                str = input.substr(0, a);
                input.erase(0, a + 1);
                //cout << "pay: " << str << endl;
                spisok[i].pay = atoi(str.c_str());
                //n->pay = atoi(str.c_str());
                i++;
            }

        }
        file.close();
        return spisok;
    }
    return spisok;
}

void inPut(Order* spisok) { //Запись в файл
    ofstream file;
    file.open(location + "Zakaz_1.txt");
    for (int i = 0; i < 50; i++) {
        if (spisok[i].number >= 0)
            file << spisok[i].number << " " << spisok[i].fio << " " << spisok[i].name << " " << spisok[i].k << " " << spisok[i].pay << "\n";
    }
    file.close();
    file.clear(); // окончили запись файла
    cout << "Файл успешно записан" << endl;
}

void writeFile(Order* spisok) { //Запись в бинарный файл
    ofstream fout(location + "Zakaz_1_1.txt", ios::binary);
    if (fout.is_open()) {
        for (int i = 0; i < 50; i++) {
            if (spisok[i].number >= 0) {
                fout << spisok[i].number << " " << spisok[i].fio << " " << spisok[i].name << " " << spisok[i].k << " " << spisok[i].pay << endl;
            }
        }
        fout.close();
        cout << "Информация о товарах успешно записана в двоичный файл";
    }
    else cout << "Запись в двоичный файл: Не удалось открыть файл";
    cout << endl;
}

void binaryRead(Order* spisok) { //Чтение бинарного файла
    ifstream fin(location + "Zakaz_1_1.txt", ios::binary);
    if (fin.is_open()) {
        int i = 0;
        while (!fin.eof()) {
            Order temp;
            fin >> temp.number >> temp.fio >> temp.name >> temp.k >> temp.pay;
            spisok[i] = temp;
            i++;
        }
        fin.close();
        cout << "Информация из бинарного файла:\n";
        outPut(spisok);
    }
    else cout << "Чтение двоичного файла: Не удалось открыть файл";
}

/*ГЛАВНАЯ ФУНКЦИЯ*/
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
    string filename, input;
    cout << "Введите только имя файла" << endl;
    getline(cin, filename);
    Order* spisok = new Order[50];
    provfile(filename, spisok);
    //outPut(spisok);
    sorti(spisok);
    outPut(spisok);
    search(spisok);
    inPut(spisok);
    writeFile(spisok);
	cout << "\nДо свидания!" << endl;
	system("pause");
	return (0);
}