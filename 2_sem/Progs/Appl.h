#ifndef APPL_H
#define APPL_H
#include "Base.h"
class Appl : public Base
{
public:
	Appl(Base* parent = 0);		//�����������
	void bild_tree_objects();   //���������� ������
	int exec_app();				//���������� ���������
};
#endif
