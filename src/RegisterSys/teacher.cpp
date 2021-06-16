#include<bits/stdc++.h>
#include "teacher.h"
using namespace std;


teacher::teacher()
{

}

teacher::teacher(int id, string name, string pwd)
{
    //初始化职工信息
    this->m_Tid = id;
    this->m_name = name;
    this->m_pwd = pwd;
}

void teacher::show_menu()
{
	cout << "欢迎教师：" << this->m_name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout <<  endl;
}

void teacher::showAllOrder()
{
    orderFile of;
    if(of.m_clause==0)
    {
        cout << "文件为空！返回上级菜单" << endl;
        system("pause");
		system("cls");
        return;
    }

    for (int i = 0; i < of.m_clause; i++)
	{
		cout << i + 1 << "、 ";

		cout << "预约日期： 周" << of.m_orderData[i]["date"];
		cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学号：" << of.m_orderData[i]["stuId"];
		cout << " 姓名：" << of.m_orderData[i]["stuName"];
		cout << " 机房：" << of.m_orderData[i]["roomId"];
		string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "审核未通过，预约失败";
		}
		else
		{
			status += "预约已取消";
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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "请选择审核的预约：(输入0返回)" << endl;
	vector<int> v;
	int select;
    int opt;        //1.批准   2.驳回

    //检索文件
	int index = 1;
	for (int i = 0; i < of.m_clause;i++)
	{

        if(of.m_orderData[i]["status"]=="1")
        {
            v.push_back(i);
            cout << index++ << ". " ;
            cout << "预约日期： 周" << of.m_orderData[i]["date"];
            cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
            cout << " 机房：" << of.m_orderData[i]["roomId"];
            string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
            if (of.m_orderData[i]["status"] == "1")
            {
                status += "审核中";
            }
            cout << status << endl;
        }
		
	}

	while(1)
	{
		//删除操作
		cin >> select;
        if (select >= 0 && select < index )
		{
			if (select == 0)
			{
				break;
			}

			else
			{
                cout << "请输入审核结果" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
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
                        cout << "输入错误，请重新输入！" << endl;
                    }
                }

                cout << "第" << v[select - 1] + 1 << "号预约审核完毕！"<< endl;
                cout << "请再次选择：（输入0返回）" << endl;


			}
		}
		else
		{
			cout << "输入错误！请重新输入：" << endl;
		}




	}


	//退出前更新预约文件
	of.updateOrder();
	system("pause");
	system("cls");
}

