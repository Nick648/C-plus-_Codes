#pragma once
#ifndef BASE_H
#define BASE_H
#include <vector>
#include <string>
using namespace std;
class Base
{
	string name; //��� �������
	Base* parent; //��������� �� �������� �������
	int kready; //������ ���������� �������
	vector < Base* > children; //������ ����� �������
	vector < Base* > ::iterator it_children; //�������� ��� ������ ����� �������
public:
	Base(Base* parent, string name = ""); //�����������
	void setName(string name); //������������ ����� �������
	string getName(); //������� ����� �������
	void switchParent(Base* parent); //�������� �������� �������
	Base* getParent(); //������� �������� �������
	void printNames(); //����� ��� ��������
	Base* findParent(string parentName); //���������� ��������� �� ������ �� �����
	void setReady(int k = 1); //������������ ���������� �������
	int statusReady(); //������� ���������� �������
	void printStatus(); //����� ������� ����������
	void printTree(int level); //����� ������ ��������
	string objectWay(Base* t_parent); //������� ���� �� �������
	Base* getPar(string parentName); //������� ��������� �� ������ �� ��� ����
	string findObj(string parentName); //���������� ����� ������� �� ��� ����
};
#endif