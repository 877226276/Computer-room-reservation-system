#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"Identity.h"
#include"computerroom.h"
#include<vector>
#include<fstream>
#include"globalfile.h"
#include"orderfile.h"

//ѧ����
class Student:public Identity
{
public:
	//Ĭ�Ϲ���
	Student();

	//�вι���
	Student(int id, string name, string pwd);
	
	//�˵�����
	virtual void operMenu();
	
	//����ԤԼ
	void applyOrder();
	
	//�鿴����ԤԼ
	void showMyOrder();
	
	//�鿴����ԤԼ
	void showAllOrder();
	
	//ȡ��ԤԼ
	void cancelOrder();
	
	//ѧ����
	int s_id;

	//��������
	vector<Computerroom>vcom;
};