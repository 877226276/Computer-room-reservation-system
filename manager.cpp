#include"manager.h"


//默认构造
Manager::Manager()
{

}

//有参构造
Manager::Manager(string name, string pwd)
{
	//初始化管理员的信息
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器  获取所有文件中老师和学生的信息
	this->initvector();

	//初始化机房信息
	ifstream ifs;
	ifs.open(Computer_file, ios::in);
	Computerroom com;
	while (ifs >> com.m_cid && ifs >> com.m_maxnum)
	{
		vc.push_back(com);
	}
	ifs.close();
	cout << "机房的数量：" << vc.size() << endl;
}

//菜单界面
void Manager::operMenu()
{
	cout << "观影管理员" << this->m_Name << "登录" << endl;
	cout << "\t\t ———————————————————\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             1、添加账号              |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             2、查看账号              |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             3、查看机房              |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             4、清空预约              |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             0、注销登录              |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t ———————————————————\n";
	cout << "请输入您的选择：" << endl;
}

//添加账号
void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

	string filename;//操作文件名
	string tip;//提示
	ofstream ofs;//文件操作
	string errotip;//错误提示

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//添加的是学生
		filename = Student_file;
		tip = "请输入学号：";
		errotip = "学号重复，请重新输入";
	}
	else
	{
		filename = Teacher_file;
		tip = "请输入职工编号：";
		errotip = "职工号重复，请重新输入";
	}
	
	//利用追加的方式写文件
	ofs.open(filename, ios::in | ios::app);

	int id;
	string name;
	string pwd;

	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret=checkrepeat(id, select);
		if (ret)
		{
			cout << errotip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
	ofs.close();

	//调用初始化文件的接口  重新获取文件数据
	this->initvector();
}

void printstudent(Student&s)//打印函数不能写在类里
{
	cout << " 学号：" << s.s_id << " 姓名：" << s.m_Name<< " 密码：" << s.m_Pwd << endl;
}
void printteacher(Teacher&t)//打印函数不能写在类里
{
	cout << " 职工号：" << t.t_id << " 姓名：" << t.m_Name << " 密码：" << t.m_Pwd << endl;
}
//查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容" << endl;
	cout << "1、所有学生" << endl;
	cout << "2、所有老师" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//查看学生
		cout << "所有学生如下：" << endl;
		for_each(vs.begin(), vs.end(), printstudent);
	}
	else
	{
		//查看老师
		cout << "所有老师如下：" << endl;
		for_each(vt.begin(), vt.end(), printteacher);
	}
	system("pause");
	system("cls");

}

//查看机房信息
void Manager::showCompter()
{
	cout << "机房的信息如下：" << endl;
	for (vector<Computerroom>::iterator it = vc.begin(); it != vc.end(); it++)
	{
		cout << "机房的编号：" << (*it).m_cid << " 机房的最大容量：" << (*it).m_maxnum << endl;
	}
	system("pause");
	system("cls");
}

//清空所有预约记录
void Manager::cleanFile()
{
	ofstream ofs(Order_file, ios::trunc);
	ofs.close();
	cout << "清空成功" << endl;
	system("pause");
	system("cls");

}

//初始化容器
void Manager::initvector()
{
	//确保文件是清空状态
	vs.clear();
	vt.clear();
	//读取学生信息
	ifstream ifs1;
	ifs1.open(Student_file, ios::in);
	if (!ifs1.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Student s;
	while (ifs1 >> s.s_id && ifs1 >> s.m_Name && ifs1 >> s.m_Pwd)
	{
		vs.push_back(s);
	}
	cout << "当前的学生数量为：" << vs.size() << endl;
	//for_each(vs.begin(), vs.end(), printstudent);
	ifs1.close();

	//读取学生信息
	ifstream ifs2;
	ifs2.open(Teacher_file, ios::in);
	if (!ifs2.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Teacher t;
	while (ifs2 >> t.t_id && ifs2 >> t.m_Name && ifs2 >> t.m_Pwd)
	{
		vt.push_back(t);
	}
	cout << "当前的老师数量为：" << vt.size() << endl;
	//for_each(vt.begin(), vt.end(), printteacher);
	ifs2.close();

}

//检测重复  学号或者职工号   检测类型
bool Manager::checkrepeat(int id, int type)
{
	if (type == 1)//检测学生
	{
		for (vector<Student>::iterator sit = vs.begin(); sit != vs.end(); sit++)
		{
			if (id == (*sit).s_id)
			{
				return true;
			}
		}
	}
	else//检测老师
	{
		for (vector<Teacher>::iterator tit = vt.begin(); tit != vt.end(); tit++)
		{
			if (id == (*tit).t_id)
			{
				return true;
			}
		}
	}
	return false;
}