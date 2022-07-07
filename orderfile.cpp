#include"orderfile.h"

//���캯��
Orderfile::Orderfile()
{
	ifstream ifs;
	ifs.open(Order_file, ios::in);

	string data;//����
	string interval;//ʱ���
	string stuid;//ѧ�����
	string stuname;//ѧ������
	string roomid;//ԤԼ������
	string status;//ԤԼ״̬

	this->m_Size = 0;//ԤԼ��¼����
	while (ifs >> data && ifs >> interval && ifs >> stuid && ifs >> stuname && ifs >> roomid && ifs >> status)
	{
		/*cout << date << endl;
		cout << interval << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << roomId << endl;
		cout << status << endl;*/

		string key;
		string value;
		map<string, string>m;

		int pos = data.find(":");//����4
		if (pos != -1)
		{
			key = data.substr(0, pos);
			value = data.substr(pos + 1, data.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		
		/*cout << "key=" << key << endl;
		cout << "value=" << value << endl;*/

		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = stuid.find(":");
		if (pos != -1)
		{
			key = stuid.substr(0, pos);
			value = stuid.substr(pos + 1, stuid.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = stuname.find(":");
		if (pos != -1)
		{
			key = stuname.substr(0, pos);
			value = stuname.substr(pos + 1, stuname.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = roomid.find(":");
		if (pos != -1)
		{
			key = roomid.substr(0, pos);
			value = roomid.substr(pos + 1, roomid.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//��С��map�����ŵ����map������
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();

	//��������map����
	//for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	//{
	//	cout << " ����key=" << it->first << "  value=" << endl;
	//	for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++)
	//	{
	//		cout << " key=" << mit->first << "  value=" << mit->second << endl;
	//	}
	//}
}

//����ԤԼ��¼
void Orderfile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;//ԤԼ��¼Ϊ0  ֱ��return
	}

	ofstream ofs(Order_file, ios::trunc);
	for (int i = 0; i < m_Size; i++)
	{
		ofs << "data:" << this->m_orderData[i]["data"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuid:" << this->m_orderData[i]["stuid"] << " ";
		ofs << "stuname:" << this->m_orderData[i]["stuname"] << " ";
		ofs << "roomid:" << this->m_orderData[i]["roomid"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();

}