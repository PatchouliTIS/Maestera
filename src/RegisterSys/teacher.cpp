#include<bits/stdc++.h>
#include "teacher.h"
using namespace std;


teacher::teacher()
{

}

teacher::teacher(int id, string name, string pwd)
{
    //��ʼ��ְ����Ϣ
    this->m_Tid = id;
    this->m_name = name;
    this->m_pwd = pwd;
}

void teacher::show_menu()
{
	cout << "��ӭ��ʦ��" << this->m_name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout <<  endl;
}

void teacher::showAllOrder()
{
    orderFile of;
    if(of.m_clause==0)
    {
        cout << "�ļ�Ϊ�գ������ϼ��˵�" << endl;
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

void teacher::validOrder()
{
	orderFile of;
	if (of.m_clause == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "��ѡ����˵�ԤԼ��(����0����)" << endl;
	vector<int> v;
	int select;
    int opt;        //1.��׼   2.����

    //�����ļ�
	int index = 1;
	for (int i = 0; i < of.m_clause;i++)
	{

        if(of.m_orderData[i]["status"]=="1")
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
            cout << status << endl;
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
                cout << "��������˽��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
                while(1)
                {
				    cin >> opt;
                    if (opt == 1)
                    {
                        of.m_orderData[v[select - 1]]["status"] = "2";
                        break;
                    }
                    else if (opt == 2)
                    {
                        of.m_orderData[v[select - 1]]["status"] = "-1";
                        break;
                    }
                    else
                    {
                        cout << "����������������룡" << endl;
                    }
                }

                cout << "��" << v[select - 1] + 1 << "��ԤԼ�����ϣ�"<< endl;
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

