// Prak4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string s;
	cout << "Введите email: ";
	cin >> s;
	int k = s.find('@');
	if (s.substr(k) != "@mail.ru" and s.substr(k) != "@cs.mcgill.ca" and
		s.substr(k) != "@mtu-shet.info") {
		cout << "Wrong email!";
	}
	else {
		s.erase(k);
		if (isalpha(s[0]) and isalnum(s[s.size() - 1])) {
			cout << "Correct email!" << endl;
		}
		else {
			cout << "Wrong email!" << endl;
		}
	}
	return 0;
}