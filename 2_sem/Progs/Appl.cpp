#include "Novel.h"
#include "Cl_2.h"
#include "Cl_3.h"
#include "Cl_4.h"
#include "Cl_5.h"
#include <iostream>
#include "Appl.h"

using namespace std;

Appl::Appl(Base* parent) : Base(parent) {} //Конструктор

void Appl::bild_tree_objects() //Построение дерева
{
	Base* t_child;
	Base* h_parent = this;
	Base* t_parent = this;
	string parentName, childName;
	int nclass, kready;
	cin >> parentName;
	setName(parentName);
	setReady(1);
	do
	{
		cin >> parentName;
		if ((parentName == "endtree") /*|| (parentName == childName)*/)
			return;
		cin >> childName >> nclass >> kready;
		t_parent = h_parent->getPar(parentName);
		//cout << "Proverka2: " << parentName << " NEWPARENT: " << t_parent -> getName() << " CHILD: " << childName << endl << endl;
		if (nclass == 2)
			t_child = new Novel(t_parent, childName, kready);
		else if (nclass == 3)
			t_child = new Cl_2(t_parent, childName, kready);
		else if (nclass == 4)
			t_child = new Cl_3(t_parent, childName, kready);
		else if (nclass == 5)
			t_child = new Cl_4(t_parent, childName, kready);
		else if (nclass == 6)
			t_child = new Cl_5(t_parent, childName, kready);
	} while (true);
}

int Appl::exec_app() //Выполнение программы
{
	string str;
	cout << "Object tree\n" << this->getName();
	this->printTree(1);
	//this -> printStatus ()
	cin >> str;
	while (str != "//")
	{
		if (this->getPar(str))
		{
			cout << endl << str << " Object name: " << this->getPar(str)->getName();
			//cout << endl << "ADRES: " << this -> objectWay(getPar(str)) << endl;
		}
		else
			cout << endl << str << " Object not found";
		cin >> str;
	}
	return (0);
}
