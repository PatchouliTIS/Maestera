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
    string errortip;
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
                    errortip = "学号重复！请重新输入：";
                    mk = 0;
                    break;
                case 2:
                    filename = Tch_FILE;
                    tip = "请输入职工号：";
                    errortip = "职工号重复！请重新输入：";
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
        //去重操作
        while(!this->checkRepeat(id,flag))
        {
            cout << errortip << endl;
            cin >> id;
        }

        cout << "请输入账号：" << endl;
        cin >> name;

        cout << "请输入密码：" << endl;
        cin >> pwd;

        ofs << id << " " << name << " " << pwd << " " << endl;

        cout << "添加成功！" << endl;
        ofs.close();

        //////////////////////////
        //每次通过软件添加账号之后用文件操作将数据写回记录文件
        //以此解决新添加的记录无法判重的问题
        this->initVector();

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
    //全局函数
    static void printStu(student & s)
    {
        cout << "学生编号：" << s.m_Sid << "      "
             << "学生账号：" << s.m_name << "      "
             << "学生密码：" << s.m_pwd << endl;
    }

    static void printTchr(teacher & t)
    {
        cout << "职工编号：" << t.m_Tid << "      "
             << "职工账号：" << t.m_name << "      "
             << "职工密码：" << t.m_pwd << endl;
    }

    cout << "请选择查看对象：" << endl
         << "1. 查看学生账号" << endl
         << "2. 查看老师账号" << endl;

    int select;
    cin >> select;
    while(1)
    {
        switch(select)
        {
            case 1:
                cout << "所有学生信息如下：" << endl;
                for_each(vStu.begin(), vStu.end(), printStu);
                break;
            case 2:
                cout << "所有老师信息如下：" << endl;
                for_each(vTchr.begin(), vTchr.end(), printTchr);
                break;
            default:
                cout << "输入错误！请重新输入：" << endl;
                break;
        }
    }

    system("pause");
    system("cls");
    return;
}

void Adm::showPC()
{
    cout << "所有机房信息如下：" << endl;
    for (vector<CPT>::iterator it = this->vCPT.begin(); it != this->vCPT.end(); it++)
    {
        cout << "第" << it->m_Num << "号机房目前共有" << it->m_count << "台机器可供使用" << endl;
    }

    system("pause");
    system("cls");
}

void Adm::showRcrd()
{

}

void Adm::initVector()
{
    this->vStu.clear();
    this->vTchr.clear();
    this->vCPT.clear();

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

    //3. 打开机房记录文件
    CPT tmpC;
    ifs.open(PC_FILE, ios::in);
    if(!ifs.is_open())
    {
        cout << "文件不存在！返回上级菜单" << endl;
        return;
    }

    while (ifs >> tmpC.m_Num && ifs >> tmpC.m_count)
    {
        vCPT.push_back(tmpC);
    }
    cout << "目前共有" << vCPT.size() << "个机房可供使用" << endl;
    ifs.close();


    return;
}



void Adm::clearRcrd()
{
    ofstream ofs;
    ofs.open(Order_FILE, ios::trunc);
    ofs.close();

    cout << "删除成功！按任意键返回主菜单" << endl;
    system("pause");
    system("cls");
}


bool Adm::checkRepeat(int id,int type)
{
    if (type == 1)      //学生
    {
        for (vector<student>::iterator it = this->vStu.begin(); it != this->vStu.end(); it++)
        {
            if(id==it->m_Sid)
            {
                return false;
            }
        }
        return true;
    }
    else if(type == 2)
    {
        for (vector<teacher>::iterator it = this->vTchr.begin(); it != this->vTchr.end(); it++)
        {
            if(id==it->m_Tid)
            {
                return false;
            }
        }
        return true;
    }
}