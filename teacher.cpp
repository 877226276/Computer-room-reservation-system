#include"teacher.h"

//默认构造
Teacher::Teacher()
{

}

//有参构造
Teacher::Teacher(int id, string name, string pwd)
{
	//初始化属性
	this->t_id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//菜单界面
void Teacher::operMenu()
{
	cout << "欢迎教师：" << this->m_Name << "登录" << endl;
	cout << "\t\t ———————————————————\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             1、查看所有预约          |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             2、审核预约              |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             0、注销登录              |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t ———————————————————\n";
	cout << "请输入您的选择：" << endl;
}

//查看所有预约
void Teacher::showAllOrder()
{
	Orderfile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "、";
		cout << "  预约的日期：周" << of.m_orderData[i]["data"];
		cout << "  时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << "  学号：" << of.m_orderData[i]["stuid"];
		cout << "  姓名：" << of.m_orderData[i]["stuname"];
		cout << "  机房编号：" << of.m_orderData[i]["roomid"];

		string status = "状态：";
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "3")
		{
			status += "预约失败，审核未通过";
		}
		else
		{
			status += "预约已取消";
		}
		cout << "  " << status << endl;
	}
	system("pause");
	system("cls");
}

//审核预约
void Teacher::validOrder()
{
	Orderfile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约记录如下：" << endl;
	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << " ";
			cout << "预约日期：周" << of.m_orderData[i]["data"];
			cout << "时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "学生的编号：" << of.m_orderData[i]["stuid"];
			cout << "学生姓名：" << of.m_orderData[i]["stuname"];
			cout << "机房编号：" << of.m_orderData[i]["roomid"];
			string status = "状态：审核中";
			cout << " " << status << endl;
		}
	}
	cout << "请输入审核的预约记录，0代表返回" << endl;
	int select = 0;//接受用户选择的预约记录
	int ret = 0;//接受预约结果记录

	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入审核结果：" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
				cin >> ret;
				if (ret == 1)
				{
					//通过
					of.m_orderData[v[select]]["status"] = "2";
					of.updateOrder();//更新预约记录
					cout << "审核完毕" << endl;
					break;
				}
				else
				{
					of.m_orderData[v[select-1]]["status"] = "3";
					of.updateOrder();//更新预约记录
					cout << "审核完毕" << endl;
					break;
				}
				
			}
		}
		
	}
	system("pause");
	system("cls");
}