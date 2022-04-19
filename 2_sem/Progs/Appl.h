#ifndef APPL_H
#define APPL_H
#include "Base.h"
class Appl : public Base
{
public:
	Appl(Base* parent = 0);		//Конструктор
	void bild_tree_objects();   //Построение дерева
	int exec_app();				//Выполнение программы
};
#endif
