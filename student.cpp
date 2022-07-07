#include"student.h"

//默认构造
Student::Student()
{

}

//有参构造
Student::Student(int id, string name, string pwd)
{
	//初始化属性
	this->s_id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化机房信息
	ifstream ifs;
	ifs.open(Computer_file, ios::in);
	Computerroom com;
	while (ifs >> com.m_cid && ifs >> com.m_maxnum)
	{
		//将读取的信息放到  容器中
		vcom.push_back(com);
	}
	ifs.close();
}

//菜单界面
void Student::operMenu()
{
	cout << "欢迎同学" << this->m_Name << "登录" << endl;
	cout << "\t\t ———————————————————\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             1、申请预约              |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             2、查看自身预约          |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             3、查看所有预约          |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             4、取消预约              |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             0、注销登录              |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t ———————————————————\n";
	cout << "请输入您的选择：" << endl;
}

//申请预约
void Student::applyOrder()
{
	cout << "机房开放时间：周一至周五" << endl;
	cout << "请输入申请预约的时间" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	
	int data = 0;//日期
	int interval = 0;//时间段
	int room = 0;//机房号

	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;

	}
	cout << "请输入申请预约的时间段" << endl;
	cout << "1、上午" << endl;
	cout << "2、上午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误,请重新输入" << endl;
	}
	cout << "请选择机房" << endl;
	for (int i = 0; i < vcom.size(); i++)
	{
		cout << vcom[i].m_cid << "机房的容量为：" << vcom[i].m_maxnum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "预约成功！审核中" << endl;
	ofstream ofs;
	ofs.open(Order_file, ios::app);
	ofs << "data:" << data << " " << "interval:" << interval << " " << "stuid:" << this->s_id << " " << "stuname:" << this->m_Name << " " << "roomid:" << room << " " << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
}

//查看自身预约
void Student::showMyOrder()
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
		//string 转 int
		//string  利用 .c_str() 转 const char *
		//利用  atoi ( const char * ) 转 int
		if (this->s_id == atoi(of.m_orderData[i]["stuid"].c_str()))//找到了自身的预约
		{
			cout << " 预约的日期：周" << of.m_orderData[i]["data"];
			cout << "  时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "  机房信息：" << of.m_orderData[i]["roomid"];
			
			//1——审核中   2——已预约  -1——预约失败  0——取消预约
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
				status += "预约失败";
			}
			else
			{
				status += "预约已取消";
			}
			cout << " " << status << endl;
		}
	}
	system("pause");
	system("cls");
}

//查看所有预约
void Student::showAllOrder()
{
	Orderfile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");

	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << " 、";
		cout << "  预约日期： 周" << of.m_orderData[i]["data"];
		cout << "  时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << "  学号：" << of.m_orderData[i]["stuid"];
		cout << "  姓名：" << of.m_orderData[i]["stuname"];
		cout << "  机房：" << of.m_orderData[i]["roomid"];
		
		string status = "状态：";
		//1——审核中  2——已预约  -1——预约失败  0——取消
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
			status += "预约失败";
		}
		else
		{
			status += "取消预约";
		}
		cout << "  " << status << endl;
	}
	system("pause");
	system("cls");
}

//取消预约
void Student::cancelOrder()
{
	Orderfile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
	}

	cout << "审核中或者预约成功的记录可以取消" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//先判断自身学号
		if (this->s_id == atoi(of.m_orderData[i]["stuid"].c_str()))
		{
			//再筛选状态 审核中或者预约成功的才可以删除
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、";
				cout << "  预约日期：周" << of.m_orderData[i]["data"];
				cout << "  预约时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
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
				cout << "  " << status << endl;
			}

		}
	}
	cout << "请输入取消的记录,0代表返回" << endl;
	int select = 0;
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
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "已取消预约" << endl;
				break;
			}
			
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}