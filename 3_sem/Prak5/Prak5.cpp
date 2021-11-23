// Prak5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <conio.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int k;
	string chis = "";
	char raz[] = " ,.!?:;-";
	char s[100];
	char* word;
	cout << "Ввод текста: ";
	cin.getline(s, 100);
	word = strtok(s, raz);
	while (word != 0)
	{
		k = 1;
		for (int i = 0; i < strlen(word); i++) {
			if (isdigit(word[i]) == 0) {
				k = 0;
			}
		}
		if (k == 1 and strlen(word) > chis.size()) {
			chis = word;
		}
		word = strtok(0, raz);
	}
	if (chis == "") {
		cout << "Слов чисел в тексте нет!";
	}
	else {
		cout << "Максимальное слово число: " << chis;
	}
	return 0;
}