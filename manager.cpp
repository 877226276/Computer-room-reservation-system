#include"manager.h"


//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι���
Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա����Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������  ��ȡ�����ļ�����ʦ��ѧ������Ϣ
	this->initvector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(Computer_file, ios::in);
	Computerroom com;
	while (ifs >> com.m_cid && ifs >> com.m_maxnum)
	{
		vc.push_back(com);
	}
	ifs.close();
	cout << "������������" << vc.size() << endl;
}

//�˵�����
void Manager::operMenu()
{
	cout << "��Ӱ����Ա" << this->m_Name << "��¼" << endl;
	cout << "\t\t ��������������������������������������\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             1������˺�              |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             2���鿴�˺�              |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             3���鿴����              |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             4�����ԤԼ              |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             0��ע����¼              |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t ��������������������������������������\n";
	cout << "����������ѡ��" << endl;
}

//����˺�
void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	string filename;//�����ļ���
	string tip;//��ʾ
	ofstream ofs;//�ļ�����
	string errotip;//������ʾ

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//��ӵ���ѧ��
		filename = Student_file;
		tip = "������ѧ�ţ�";
		errotip = "ѧ���ظ�������������";
	}
	else
	{
		filename = Teacher_file;
		tip = "������ְ����ţ�";
		errotip = "ְ�����ظ�������������";
	}
	
	//����׷�ӵķ�ʽд�ļ�
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

	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
	ofs.close();

	//���ó�ʼ���ļ��Ľӿ�  ���»�ȡ�ļ�����
	this->initvector();
}

void printstudent(Student&s)//��ӡ��������д������
{
	cout << " ѧ�ţ�" << s.s_id << " ������" << s.m_Name<< " ���룺" << s.m_Pwd << endl;
}
void printteacher(Teacher&t)//��ӡ��������д������
{
	cout << " ְ���ţ�" << t.t_id << " ������" << t.m_Name << " ���룺" << t.m_Pwd << endl;
}
//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴����" << endl;
	cout << "1������ѧ��" << endl;
	cout << "2��������ʦ" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//�鿴ѧ��
		cout << "����ѧ�����£�" << endl;
		for_each(vs.begin(), vs.end(), printstudent);
	}
	else
	{
		//�鿴��ʦ
		cout << "������ʦ���£�" << endl;
		for_each(vt.begin(), vt.end(), printteacher);
	}
	system("pause");
	system("cls");

}

//�鿴������Ϣ
void Manager::showCompter()
{
	cout << "��������Ϣ���£�" << endl;
	for (vector<Computerroom>::iterator it = vc.begin(); it != vc.end(); it++)
	{
		cout << "�����ı�ţ�" << (*it).m_cid << " ���������������" << (*it).m_maxnum << endl;
	}
	system("pause");
	system("cls");
}

//�������ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(Order_file, ios::trunc);
	ofs.close();
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");

}

//��ʼ������
void Manager::initvector()
{
	//ȷ���ļ������״̬
	vs.clear();
	vt.clear();
	//��ȡѧ����Ϣ
	ifstream ifs1;
	ifs1.open(Student_file, ios::in);
	if (!ifs1.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Student s;
	while (ifs1 >> s.s_id && ifs1 >> s.m_Name && ifs1 >> s.m_Pwd)
	{
		vs.push_back(s);
	}
	cout << "��ǰ��ѧ������Ϊ��" << vs.size() << endl;
	//for_each(vs.begin(), vs.end(), printstudent);
	ifs1.close();

	//��ȡѧ����Ϣ
	ifstream ifs2;
	ifs2.open(Teacher_file, ios::in);
	if (!ifs2.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Teacher t;
	while (ifs2 >> t.t_id && ifs2 >> t.m_Name && ifs2 >> t.m_Pwd)
	{
		vt.push_back(t);
	}
	cout << "��ǰ����ʦ����Ϊ��" << vt.size() << endl;
	//for_each(vt.begin(), vt.end(), printteacher);
	ifs2.close();

}

//����ظ�  ѧ�Ż���ְ����   �������
bool Manager::checkrepeat(int id, int type)
{
	if (type == 1)//���ѧ��
	{
		for (vector<Student>::iterator sit = vs.begin(); sit != vs.end(); sit++)
		{
			if (id == (*sit).s_id)
			{
				return true;
			}
		}
	}
	else//�����ʦ
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