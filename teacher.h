#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<string>
#include"orderfile.h"
#include<vector>

//��ʦ��
class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι���
	Teacher(int id, string name, string pwd);

	//�˵�����
	virtual void operMenu();
	
	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//ְ�����
	int t_id;

};