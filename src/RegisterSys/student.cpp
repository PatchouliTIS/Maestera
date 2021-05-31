#include<bits/stdc++.h>
#include "student.h"
using namespace std;

student::student()
{

}

student::student(int id,string name,string pwd)
{
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

    ifs.close;
}

void student::show_menu()
{
{
	cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
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

void student::apllyOrder()
{

}

void student::showMyOrder()
{

}

void student::showAllOrder()
{

}

void student::cancelOrder()
{
    
}
