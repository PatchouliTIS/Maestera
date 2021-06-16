#include<bits/stdc++.h>
#include "student.h"

using namespace std;

student::student()
{

}

student::student(int id,string name,string pwd)
{
	//有参构造
    this->m_Sid = id;
    this->m_name = name;
    this->m_pwd = pwd;

    //初始化机房记录文件
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
	cout << "欢迎学生代表：" << this->m_name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
}

void student::applyOrder()
{
	cout << "机房开放时间为周一至周五！" << endl;
	//1. 输入预约的时间
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

	int date, interval, PCroom;

	while (cin >> date)
	{
		if (date > 5 || date < 1)
		{
			cout << "输入有误，请重新输入" << endl;
		}
		else
			break;
	}

	//2.输入上午/下午
	cout << "请输入申请预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	while (cin >> interval)
	{
		if (interval > 2 || interval < 1)
		{
			cout << "输入有误，请重新输入" << endl;
		}
		else
			break;
	}

	//3.选择申请的机房
	cout << "请选择机房：" << endl;
	cout << "1号机房容量：" << this->vCPT[0].m_count << endl;
	cout << "2号机房容量：" << this->vCPT[1].m_count << endl;
	cout << "3号机房容量：" << this->vCPT[2].m_count << endl;

	while (cin >> PCroom)
	{
		if (PCroom > 3 || PCroom < 1)
		{
			cout << "输入有误，请重新输入" << endl;
		}
		else
			break;
	}

	//输入完成，开始录入数据
	////用冒号":"来阻隔key和val，便于后续拆分、映射处理
	ofstream ofs;
	ofs.open(Order_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Sid << " ";
	ofs << "stuName:" << this->m_name << " ";
	ofs << "roomId:" << PCroom << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	cout << "预约成功！审核中" << endl;

	system("pause");
	system("cls");

	return;
}

void student::showMyOrder()
{

	orderFile of;
	if(of.m_clause==0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_clause; i++)
	{
		//c_str() string类转char[]
		//并进行atoi  char[]转int
		if(atoi(of.m_orderData[i]["stuId"].c_str())==this->m_Sid)
		{
			//匹配成功，准备输出信息
			cout << "预约日期： 周" << of.m_orderData[i]["date"];
			cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
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
	}

	system("pause");
	system("cls");
}

void student::showAllOrder()
{
	orderFile of;
	if (of.m_clause == 0)
	{
		cout << "无预约记录" << endl;
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

void student::cancelOrder()
{
	orderFile of;
	if (of.m_clause == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "请选择需要取消的预约：(输入0返回)" << endl;
	vector<int> v;
	int select;


	

	//检索文件
	int index = 1;
	for (int i = 0; i < of.m_clause;i++)
	{
		if(atoi(of.m_orderData[i]["stuId"].c_str())==this->m_Sid)
		{
			if(of.m_orderData[i]["status"]=="1"||of.m_orderData[i]["status"]=="2")
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
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;
			}
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
				of.m_orderData[v[select - 1]]["status"] = "0";
				cout << "第" << v[select - 1] + 1 << "号预约已取消！" << endl;
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
