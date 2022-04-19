#pragma once
#ifndef BASE_H
#define BASE_H
#include <vector>
#include <string>
using namespace std;
class Base
{
	string name; //Имя объекта
	Base* parent; //Указатель на родителя объекта
	int kready; //Статус готовности объекта
	vector < Base* > children; //Список детей объекта
	vector < Base* > ::iterator it_children; //Итератор для списка детей объекта
public:
	Base(Base* parent, string name = ""); //Конструктор
	void setName(string name); //Установление имени объекта
	string getName(); //Возврат имени объекта
	void switchParent(Base* parent); //Поменять родителя объекта
	Base* getParent(); //Возврат родителя объекта
	void printNames(); //Вывод имён объектов
	Base* findParent(string parentName); //Нахождение указателя на объект по имени
	void setReady(int k = 1); //Установление готовности объекта
	int statusReady(); //Возврат готовности объекта
	void printStatus(); //Вывод статуса готовности
	void printTree(int level); //Вывод дерева иерархии
	string objectWay(Base* t_parent); //Возврат пути до объекта
	Base* getPar(string parentName); //Возврат указателя на объект по его пути
	string findObj(string parentName); //Нахождение имени объекта по его пути
};
#endif