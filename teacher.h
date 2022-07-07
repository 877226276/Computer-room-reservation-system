#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<string>
#include"orderfile.h"
#include<vector>

//教师类
class Teacher :public Identity
{
public:
	//默认构造
	Teacher();

	//有参构造
	Teacher(int id, string name, string pwd);

	//菜单界面
	virtual void operMenu();
	
	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

	//职工编号
	int t_id;

};