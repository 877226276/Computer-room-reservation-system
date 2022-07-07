#include"student.h"

//Ĭ�Ϲ���
Student::Student()
{

}

//�вι���
Student::Student(int id, string name, string pwd)
{
	//��ʼ������
	this->s_id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(Computer_file, ios::in);
	Computerroom com;
	while (ifs >> com.m_cid && ifs >> com.m_maxnum)
	{
		//����ȡ����Ϣ�ŵ�  ������
		vcom.push_back(com);
	}
	ifs.close();
}

//�˵�����
void Student::operMenu()
{
	cout << "��ӭͬѧ" << this->m_Name << "��¼" << endl;
	cout << "\t\t ��������������������������������������\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             1������ԤԼ              |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             2���鿴����ԤԼ          |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             3���鿴����ԤԼ          |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             4��ȡ��ԤԼ              |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|             0��ע����¼              |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t ��������������������������������������\n";
	cout << "����������ѡ��" << endl;
}

//����ԤԼ
void Student::applyOrder()
{
	cout << "��������ʱ�䣺��һ������" << endl;
	cout << "����������ԤԼ��ʱ��" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	
	int data = 0;//����
	int interval = 0;//ʱ���
	int room = 0;//������

	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		cout << "������������������" << endl;

	}
	cout << "����������ԤԼ��ʱ���" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "��������,����������" << endl;
	}
	cout << "��ѡ�����" << endl;
	for (int i = 0; i < vcom.size(); i++)
	{
		cout << vcom[i].m_cid << "����������Ϊ��" << vcom[i].m_maxnum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "ԤԼ�ɹ��������" << endl;
	ofstream ofs;
	ofs.open(Order_file, ios::app);
	ofs << "data:" << data << " " << "interval:" << interval << " " << "stuid:" << this->s_id << " " << "stuname:" << this->m_Name << " " << "roomid:" << room << " " << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showMyOrder()
{
	Orderfile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		//string ת int
		//string  ���� .c_str() ת const char *
		//����  atoi ( const char * ) ת int
		if (this->s_id == atoi(of.m_orderData[i]["stuid"].c_str()))//�ҵ���������ԤԼ
		{
			cout << " ԤԼ�����ڣ���" << of.m_orderData[i]["data"];
			cout << "  ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "  ������Ϣ��" << of.m_orderData[i]["roomid"];
			
			//1���������   2������ԤԼ  -1����ԤԼʧ��  0����ȡ��ԤԼ
			string status = "״̬��";
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "3")
			{
				status += "ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << " " << status << endl;
		}
	}
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder()
{
	Orderfile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");

	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << " ��";
		cout << "  ԤԼ���ڣ� ��" << of.m_orderData[i]["data"];
		cout << "  ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << "  ѧ�ţ�" << of.m_orderData[i]["stuid"];
		cout << "  ������" << of.m_orderData[i]["stuname"];
		cout << "  ������" << of.m_orderData[i]["roomid"];
		
		string status = "״̬��";
		//1���������  2������ԤԼ  -1����ԤԼʧ��  0����ȡ��
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "3")
		{
			status += "ԤԼʧ��";
		}
		else
		{
			status += "ȡ��ԤԼ";
		}
		cout << "  " << status << endl;
	}
	system("pause");
	system("cls");
}

//ȡ��ԤԼ
void Student::cancelOrder()
{
	Orderfile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
	}

	cout << "����л���ԤԼ�ɹ��ļ�¼����ȡ��" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//���ж�����ѧ��
		if (this->s_id == atoi(of.m_orderData[i]["stuid"].c_str()))
		{
			//��ɸѡ״̬ ����л���ԤԼ�ɹ��Ĳſ���ɾ��
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "��";
				cout << "  ԤԼ���ڣ���" << of.m_orderData[i]["data"];
				cout << "  ԤԼʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << "  ������ţ�" << of.m_orderData[i]["roomid"];

				string status = "״̬��";
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				} 
				cout << "  " << status << endl;
			}

		}
	}
	cout << "������ȡ���ļ�¼,0��������" << endl;
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
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
			
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}