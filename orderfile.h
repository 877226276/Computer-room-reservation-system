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
	//构造函数
	Orderfile();

	//更新预约记录
	void updateOrder();

	//记录预约次数
	int m_Size;

	//记录所有预约信息的容器   key 记录条数  value 具体记录键值对信息 
	map<int, map<string, string>>m_orderData;

};