#include<bits/stdc++.h>
#include "Adm.h"
using namespace std;


Adm::Adm()
{

}

Adm::Adm(string name,string pwd)
{
    this->m_name = name;
    this->m_pwd = pwd;

    this->initVector();
}

void Adm::show_menu()
{
    cout << "===============欢迎，管理员===============" << endl;
    cout << "\t\t\tR L T W\n"
        << "\t\t --------------------------- \n"
        << "\t\t|        1. 添加账号        |\n"
        << "\t\t|                          |\n"
        << "\t\t|        2. 查看账号        |\n"
        << "\t\t|                          |\n"
        << "\t\t|        3. 查看机房        |\n"
        << "\t\t|                          |\n"
        << "\t\t|        4. 查看预约        |\n"
        << "\t\t|                          |\n"
        << "\t\t|        5. 清空预约        |\n"
        << "\t\t|                          |\n"
        << "\t\t|        0. 注销登录        |\n"
        << "\t\t --------------------------- \n";
}

void Adm::addID()
{
    string filename;
    string tip;
    while(1)
    {
        cout << "请选择添加对象：" << endl;
        cout << "1.添加学生账号" << endl;
        cout << "2.添加职工账号" << endl;

        int flag,mk=1;
        while(mk)
        {
            cin >> flag;
            switch(flag)
            {
                case 1:
                    filename = Stu_FILE;
                    tip = "请输入学号：";
                    mk = 0;
                    break;
                case 2:
                    filename = Tch_FILE;
                    tip = "请输入职工号：";
                    mk = 0;
                    break;
                default:
                    cout << "输入错误！请重新输入" << endl;
                    break;
            }
        }

        int id;
        string name;
        string pwd;
        ofstream ofs;

        ofs.open(filename, ios::out | ios::app);
        if(!ofs.is_open())
        {
            cout << "文件不存在，无法执行。返回上级菜单" << endl;
            return;
        }

        cout << tip << endl;
        cin >> id;

        cout << "请输入账号：" << endl;
        cin >> name;

        cout << "请输入密码：" << endl;
        cin >> pwd;

        ofs << id << " " << name << " " << pwd << " " << endl;

        cout << "添加成功！" << endl;
        ofs.close();



        cout << "是否继续添加？" << endl
            << "(Y/N)" << endl;
        char ch;
        fflush(stdin);
        while(cin>>ch)
        {
            if(ch=='N'||ch=='n')
            {
                cout << "添加成功，返回上级菜单" << endl;
                system("cls");
                system("pause");
                return;
            }
            else if(ch!='Y'||ch!='y')
            {
                cout << "输入错误，请重新输入：" << endl;
            }
            else
            {   
                system("cls");
                break;
            }
            fflush(stdin);
        }
    }
}

void Adm::showID()
{

}

void Adm::showPC()
{

}

void Adm::showRcrd()
{

}

void Adm::initVector()
{
    this->vStu.clear();
    this->vTchr.clear();

    student tmpS;

    ifstream ifs;
    //1. 打开学生记录文件
    ifs.open(Stu_FILE, ios::in);
    if(!ifs.is_open())
    {
        cout << "文件不存在！返回上级菜单" << endl;
        return;
    }

    while (ifs >> tmpS.m_Sid && ifs >> tmpS.m_name && ifs >> tmpS.m_pwd)
    {
        vStu.push_back(tmpS);
    }
    cout << "系统中共有" << vStu.size() << "个学生账号" << endl;
    ifs.close();

    cout << "===================================" << endl;

    //2. 打开老师记录文件
    teacher tmpT;
    ifs.open(Tch_FILE, ios::in);
    if(!ifs.is_open())
    {
        cout << "文件不存在！返回上级菜单" << endl;
        return;
    }

    while (ifs >> tmpT.m_Tid && ifs >> tmpT.m_name && ifs >> tmpT.m_pwd)
    {
        vTchr.push_back(tmpT);
    }
    cout << "系统中共有" << vTchr.size() << "个职工账号" << endl;
    ifs.close();

    return;
}

void Adm::clearRcrd()
{
    
}

