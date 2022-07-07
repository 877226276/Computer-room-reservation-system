#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include<string>
#include"globalfile.h"
#include"manager.h"
#include"student.h"
#include"teacher.h"

//�������Ա���Ӳ˵�����
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//���ù���Ա���Ӳ˵�
		manager->operMenu();

		//�������ָ��תΪ�����ָ��  ���������е������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		//�����û���ѡ��
		cin >> select;
		if (select == 1)//����˺�
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)//�鿴������Ϣ
		{
			cout << "�鿴������Ϣ" << endl;
			man->showCompter();
		}
		else if (select == 4)//���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else//ע��
		{
			delete manager;//���ٵ���������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//����ѧ�����Ӳ˵�����
void studengtMenu(Identity*& student)
{
	while (true)
	{
		//����ѧ�����Ӳ˵�
		student->operMenu();

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		if (select == 1)//����ԤԼ
		{
			(*stu).applyOrder();
		}
		else if(select==2)//�鿴�ҵ�ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3)//�鿴����ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else if (select == 0)//ע����¼
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�����ʦ�Ӳ˵��Ľ���
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//�����Ӳ˵��Ľ���
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		//�����û�ѡ��
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
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��¼�Ĺ���   ����1 �����ļ���  ����2 �����������
void loginin(string fileName, int type)
{
	//����ָ������ָ���������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1)
	{
		cout << "������ѧ��" << endl;
		cin >> id;
	}
	else if(type==2)
	{
		cout << "������ְ����" << endl;
		cin >> id;
	}

	cout << "�������û���" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ�������֤
		int fid;//���ļ��ж�ȡ��id
		string fname;//���ļ��л�ȡ������
		string fpwd;//���ļ��л�ȡ������
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//���û�������Ϣ���Ա�
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id,name,pwd);
				
				//����ѧ����ݵ��Ӳ˵�
				studengtMenu(person);


				return;
			}
		}
	}
	else if(type == 2)
	{
		//��ʦ�����֤ 
		int fid;//���ļ��ж�ȡ��id
		string fname;//���ļ��л�ȡ������
		string fpwd;//���ļ��л�ȡ������
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//���û�������Ϣ���Ա�
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//������ʦ��ݵ��Ӳ˵�
				teacherMenu(person);


				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա�����֤
		string fname;//���ļ��л�ȡ������
		string fpwd;//���ļ��л�ȡ������
		while (ifs >> fname && ifs >> fpwd)
		{
			//���û�������Ϣ���Ա�
			if (fname == name && fpwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				//��������Ա��ݵ��Ӳ˵�
				managerMenu(person);



				return;
			}
		}
	}
	cout << "��֤ʧ��" << endl;
	system("pause");
	system("cls");
	return;
}


int main()
{
	while (true)
	{
		int select = 0;//�����û�ѡ��
		cout << "������������ݡ�" << endl;
		cout << "\t\t ��������������������������������������\n";
		cout << "\t\t|                                      |\n";
		cout << "\t\t|             1��ѧ������              |\n";
		cout << "\t\t|                                      |\n";
		cout << "\t\t|             2����    ʦ              |\n";
		cout << "\t\t|                                      |\n";
		cout << "\t\t|             3���� �� Ա              |\n";
		cout << "\t\t|                                      |\n";
		cout << "\t\t|             0����    ��              |\n";
		cout << "\t\t|                                      |\n";
		cout << "\t\t ��������������������������������������\n";
		cout << "����������ѡ��" << endl;

		cin >> select;
		switch (select)
		{
		case 1://ѧ�����
			loginin(Student_file, 1);
			break;
		case 2://��ʦ���
			loginin(Teacher_file, 2);
			break;
		case 3://����Ա
			loginin(Admin_file, 3);
			break;
		case 0://�˳�ϵͳ
			cout << "��ӭ�´�ʹ�á�" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	



	system("pause");
	return 0;
}