#pragma once
#include<iostream>
using namespace std;
#include"globalfile.h"
#include<fstream>
#include<map>
#include<string>

class Orderfile
{
public:
	//���캯��
	Orderfile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼ԤԼ����
	int m_Size;

	//��¼����ԤԼ��Ϣ������   key ��¼����  value �����¼��ֵ����Ϣ 
	map<int, map<string, string>>m_orderData;

};