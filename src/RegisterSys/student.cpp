#include<bits/stdc++.h>
#include "student.h"

using namespace std;

student::student()
{

}

student::student(int id,string name,string pwd)
{
	//�вι���
    this->m_Sid = id;
    this->m_name = name;
    this->m_pwd = pwd;

    //��ʼ��������¼�ļ�
    this->initVector();
}

void student::initVector()
{
    ifstream ifs;
    ifs.open(PC_FILE, ios::in);
    CPT tmpC;
    while (ifs >> tmpC.m_Num && ifs >> tmpC.m_count)
    {
        this->vCPT.push_back(tmpC);
    }

    ifs.close();
}

void student::show_menu()
{
{
	cout << "��ӭѧ������" << this->m_name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
}

void student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	//1. ����ԤԼ��ʱ��
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;

	int date, interval, PCroom;

	while (cin >> date)
	{
		if (date > 5 || date < 1)
		{
			cout << "������������������" << endl;
		}
		else
			break;
	}

	//2.��������/����
	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	while (cin >> interval)
	{
		if (interval > 2 || interval < 1)
		{
			cout << "������������������" << endl;
		}
		else
			break;
	}

	//3.ѡ������Ļ���
	cout << "��ѡ�������" << endl;
	cout << "1�Ż���������" << this->vCPT[0].m_count << endl;
	cout << "2�Ż���������" << this->vCPT[1].m_count << endl;
	cout << "3�Ż���������" << this->vCPT[2].m_count << endl;

	while (cin >> PCroom)
	{
		if (PCroom > 3 || PCroom < 1)
		{
			cout << "������������������" << endl;
		}
		else
			break;
	}

	//������ɣ���ʼ¼������
	////��ð��":"�����key��val�����ں�����֡�ӳ�䴦��
	ofstream ofs;
	ofs.open(Order_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Sid << " ";
	ofs << "stuName:" << this->m_name << " ";
	ofs << "roomId:" << PCroom << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	cout << "ԤԼ�ɹ��������" << endl;

	system("pause");
	system("cls");

	return;
}

void student::showMyOrder()
{

	orderFile of;
	if(of.m_clause==0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_clause; i++)
	{
		//c_str() string��תchar[]
		//������atoi  char[]תint
		if(atoi(of.m_orderData[i]["stuId"].c_str())==this->m_Sid)
		{
			//ƥ��ɹ���׼�������Ϣ
			cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
			cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ������" << of.m_orderData[i]["roomId"];
			string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "���δͨ����ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}

	system("pause");
	system("cls");
}

void student::showAllOrder()
{
	orderFile of;
	if (of.m_clause == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_clause; i++)
	{
		cout << i + 1 << "�� ";

		cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
		cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ѧ�ţ�" << of.m_orderData[i]["stuId"];
		cout << " ������" << of.m_orderData[i]["stuName"];
		cout << " ������" << of.m_orderData[i]["roomId"];
		string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}

void student::cancelOrder()
{
	orderFile of;
	if (of.m_clause == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "��ѡ����Ҫȡ����ԤԼ��(����0����)" << endl;
	vector<int> v;
	int select;


	

	//�����ļ�
	int index = 1;
	for (int i = 0; i < of.m_clause;i++)
	{
		if(atoi(of.m_orderData[i]["stuId"].c_str())==this->m_Sid)
		{
			if(of.m_orderData[i]["status"]=="1"||of.m_orderData[i]["status"]=="2")
			{
				v.push_back(i);
				cout << index++ << ". " ;
				cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
				cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << " ������" << of.m_orderData[i]["roomId"];
				string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}

	while(1)
	{
		//ɾ������
		cin >> select;
		if (select >= 0 && select < index )
		{
			if (select == 0)
			{
				break;
			}

			else
			{
				of.m_orderData[v[select - 1]]["status"] = "0";
				cout << "��" << v[select - 1] + 1 << "��ԤԼ��ȡ����" << endl;
				cout << "���ٴ�ѡ�񣺣�����0���أ�" << endl;
			}
		}
		else
		{
			cout << "����������������룺" << endl;
		}




	}


	//�˳�ǰ����ԤԼ�ļ�
	of.updateOrder();
	system("pause");
	system("cls");
}
