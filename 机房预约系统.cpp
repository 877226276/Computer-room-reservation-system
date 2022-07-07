#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include<string>
#include"globalfile.h"
#include"manager.h"
#include"student.h"
#include"teacher.h"

//进入管理员的子菜单界面
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//调用管理员的子菜单
		manager->operMenu();

		//将父类的指针转为子类的指针  调用子类中的其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		//接受用户的选择
		cin >> select;
		if (select == 1)//添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)//查看机房信息
		{
			cout << "查看机房信息" << endl;
			man->showCompter();
		}
		else if (select == 4)//清空预约
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else//注销
		{
			delete manager;//销毁掉堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入学生的子菜单界面
void studengtMenu(Identity*& student)
{
	while (true)
	{
		//调用学生的子菜单
		student->operMenu();

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		if (select == 1)//申请预约
		{
			(*stu).applyOrder();
		}
		else if(select==2)//查看我的预约
		{
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			stu->cancelOrder();
		}
		else if (select == 0)//注销登录
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入教师子菜单的界面
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//调用子菜单的界面
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		//接受用户选择
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录的功能   参数1 操作文件名  参数2 操作身份类型
void loginin(string fileName, int type)
{
	//父类指针用于指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接受用户信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)
	{
		cout << "请输入学号" << endl;
		cin >> id;
	}
	else if(type==2)
	{
		cout << "请输入职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生身份验证
		int fid;//从文件中读取的id
		string fname;//从文件中获取的姓名
		string fpwd;//从文件中获取的密码
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//与用户输入信息做对比
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "学生验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id,name,pwd);
				
				//进带学生身份的子菜单
				studengtMenu(person);


				return;
			}
		}
	}
	else if(type == 2)
	{
		//教师身份验证 
		int fid;//从文件中读取的id
		string fname;//从文件中获取的姓名
		string fpwd;//从文件中获取的密码
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//与用户输入信息做对比
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "老师验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//进带教师身份的子菜单
				teacherMenu(person);


				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员身份验证
		string fname;//从文件中获取的姓名
		string fpwd;//从文件中获取的密码
		while (ifs >> fname && ifs >> fpwd)
		{
			//与用户输入信息做对比
			if (fname == name && fpwd == pwd)
			{
				cout << "管理员验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				//进带管理员身份的子菜单
				managerMenu(person);



				return;
			}
		}
	}
	cout << "验证失败" << endl;
	system("pause");
	system("cls");
	return;
}


int main()
{
	while (true)
	{
		int select = 0;//接受用户选择
		cout << "请输入您的身份。" << endl;
		cout << "\t\t ———————————————————\n";
		cout << "\t\t|                                      |\n";
		cout << "\t\t|             1、学生代表              |\n";
		cout << "\t\t|                                      |\n";
		cout << "\t\t|             2、老    师              |\n";
		cout << "\t\t|                                      |\n";
		cout << "\t\t|             3、管 理 员              |\n";
		cout << "\t\t|                                      |\n";
		cout << "\t\t|             0、退    出              |\n";
		cout << "\t\t|                                      |\n";
		cout << "\t\t ———————————————————\n";
		cout << "请输入您的选择：" << endl;

		cin >> select;
		switch (select)
		{
		case 1://学生身份
			loginin(Student_file, 1);
			break;
		case 2://老师身份
			loginin(Teacher_file, 2);
			break;
		case 3://管理员
			loginin(Admin_file, 3);
			break;
		case 0://退出系统
			cout << "欢迎下次使用。" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	



	system("pause");
	return 0;
}