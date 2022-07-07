#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<string>
#include<fstream>
#include"globalfile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerroom.h"

class Manager:public Identity
{
public:

	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showCompter();

	//�������ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initvector();

	//ѧ������
	vector<Student>vs;

	//��ʦ����
	vector<Teacher>vt;

	//����ظ�  ѧ�Ż���ְ����   �������
	bool checkrepeat(int id,int type);

	//������Ϣ����
	vector<Computerroom>vc;
};
