#include"orderfile.h"

//构造函数
Orderfile::Orderfile()
{
	ifstream ifs;
	ifs.open(Order_file, ios::in);

	string data;//日期
	string interval;//时间段
	string stuid;//学生编号
	string stuname;//学生姓名
	string roomid;//预约机房号
	string status;//预约状态

	this->m_Size = 0;//预约记录条数
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

		int pos = data.find(":");//返回4
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

		//将小的map容器放到大的map容器中
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();

	//测试最大的map容器
	//for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	//{
	//	cout << " 条数key=" << it->first << "  value=" << endl;
	//	for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++)
	//	{
	//		cout << " key=" << mit->first << "  value=" << mit->second << endl;
	//	}
	//}
}

//更新预约记录
void Orderfile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;//预约记录为0  直接return
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