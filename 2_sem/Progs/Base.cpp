#include <iostream>
#include "Base.h"
//#include <string>
using namespace std;

Base::Base(Base* parent, string name) //�����������
{
	setName(name);
	this->parent = parent;
	if (parent)
		parent->children.push_back(this);
}

void Base::setName(string name) //������������ ����� �������
{
	this->name = name;
}

string Base::getName() //������� ����� �������
{
	return this->name;
}

void Base::switchParent(Base* newparent) //�������� �������� �������
{
	for (int i = 0; i < (this->parent->children.size()); i++) //����� ����� �������� ������� �
	{
		if ((this->parent->children[i]->getName()) == this -> getName()) //������ children ��� �������� ��������
		{
			this->parent->children.erase(this->parent -> children.begin() + i); //��� �������� ������ � ������ ��� ��������
			break;
		}
	}
	this->parent = newparent;
	parent->children.push_back(this);
}

Base* Base::getParent() //������� �������� �������
{
	return this->parent;
}

void Base::printNames() //����� ��� ��������
{
	if (children.empty())
		return;
	cout << endl << name;
	it_children = children.begin();
	while (it_children != children.end())
	{
		cout << " " << (*it_children)->getName();
		it_children++;
	}
	it_children--;
	(*it_children)->printNames();
}

Base* Base::findParent(string parentName) //���������� ��������� �� ������ �� �����
{
	Base* s_parent = 0;
	if (this->getName() == parentName)
		return this;
	for (int i = 0; i < (this->children.size()); i++)
	{
		if (this->children[i]->getName() == parentName)
			return this->children[i];
		else if ((s_parent) && s_parent->getName() == parentName)
			break;
		else
			s_parent = this->children[i]->findParent(parentName);
	}
	return s_parent;
}

void Base::setReady(int k) //������������ ���������� �������
{
	this->kready = k;
}

int Base::statusReady() //������� ���������� �������
{
	return kready;
}

void Base::printStatus() //����� ������� ����������
{
	/*cout << "Name: " << this -> getName() << endl << "<------" << endl;
	this -> printNames();
	cout << endl << "-------->" << endl;*/
	cout << endl << "The object " << this->getName();
	if (this->statusReady() > 0)
		cout << " is ready";
	else
		cout << " is not ready";
	it_children = children.begin();
	while (it_children != children.end())
	{
		(*it_children)->printStatus();
		it_children++;
	}
	it_children--;
}

void Base::printTree(int level) //����� ������ ��������
{
	string space;
	space.append(4 * level, ' ');
	it_children = children.begin();
	while (it_children != children.end())
	{
		cout << "\n" << space << (*it_children)->getName();
		(*it_children)->printTree(level + 1);
		it_children++;
	}
}

string Base::objectWay(Base* t_parent) //������� ���� �� �������
{
	if (!t_parent->parent)
		return "/" + t_parent->getName();
	return objectWay(t_parent->parent) + "/" + t_parent->getName();
}

Base* Base::getPar(string parentName) //������� ��������� �� ������ �� ��� ����
{
	if (parentName[0] == '/' && parentName[1] == '/')
		return findParent(parentName.substr(2, parentName.length() - 2));
	return this->findParent(findObj(parentName));
}

string Base::findObj(string parentName) //���������� ����� ������� �� ��� ����
{
	int x, y, r;
	Base* t_parent;
	if (parentName.find('/', 1) < parentName.length())
		t_parent = this->findParent(parentName.substr(1,
			parentName.find('/', 1) - 1));
	else
		t_parent = this->findParent(parentName.substr(1,
			parentName.find('/', 1)));
	parentName = parentName.substr(1, parentName.length() - 1);
	while (parentName.find('/') < parentName.length())
	{
		//cout << "STROKA: " << parentName << endl;
		r = -1;
		x = parentName.find('/', 1);
		y = parentName.find('/', x + 1);
		for (int i = 0; i < (t_parent->children.size()); i++)
		{
			if (t_parent->children[i]->getName() ==
				parentName.substr(x + 1, parentName.length() - y - 1))
				r = 1;
		}
		if (r == -1)
			return "";
		t_parent = this->findParent(parentName.substr(x + 1,
			parentName.length() - y - 1));
		parentName = parentName.erase(0, x + 1);
	}
	//cout << "Return: " << parentName << endl;
	return parentName;
}