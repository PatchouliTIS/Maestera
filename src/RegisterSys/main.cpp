#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <bits/stdc++.h>
#include "ID.h"
#include "Adm.h"
#include "student.h"
#include "teacher.h"
#include "login_File.h"

using namespace std;

void personCheck(string filename, int type);

void manageMenu(ID *person);//管理员菜单接口

void stuMenu(ID *person);//学生菜单接口

void tchrMenu(ID *person);//职工菜单接口

int main()
{
    while(1)
    {
        int select;
        cout << "===============欢迎来到本宁堡机房预约系统===============" << endl;
        cout << "\t\t\tR L T W\n"
            << "\t\t ------------------------ \n"
            << "\t\t|        1. 学生          |\n"
            << "\t\t|                         |\n"
            << "\t\t|        2. 老师          |\n"
            << "\t\t|                         |\n"
            << "\t\t|       3. 管理员         |\n"
            << "\t\t|                        |\n"
            << "\t\t|      0. 退出系统        |\n"
            << "\t\t|                        |\n"
            << "\t\t ------------------------ \n";
        cout << "请输入您的选择：" << endl;
        cin >> select ;
        switch(select)
        {
            case 0:         //退出系统
                cout << "要退出吗？(Y/N)" << endl;
                char flag;
                fflush(stdin);
                while(flag=getchar())
                {
                    if(flag=='Y'||flag=='y')
                    {
                        cout << "欢迎下次使用！" << endl;
                        system("pause");
                        exit(0);
                    }
                    else if(flag=='N'||flag=='n')
                    {
                        cout << "操作取消，返回主菜单中" << endl;
                        break;
                    }
                    else
                    {
                        cout << "输入错误！请从新输入：" << endl;
                    }
                    fflush(stdin);
                }
                break;
            case 1:         //学生类调用
                personCheck(Std_FILE, 1);       //初始化文件与管理类
                break;
            case 2:         //老师类调用
                personCheck(Tch_FILE, 2);
                break;
            case 3:         //管理员类调用
                personCheck(Adm_FILE, 3);       //内接菜单接口
                break;

            default:
                cout << "输入有误！请重新输入：" << endl;
                break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}


void manageMenu(ID *person)
{
    Adm *adm = (Adm *)person;       //类型强转换
    while(1)
    {
        adm->show_menu();
        int select;
        cout << "请输入您的选择：" << endl;
        cin >> select;
        switch(select)
        {
            case 0:
            //注销
                cout << "确认注销：（Y/N）" << endl;
                char ch;
                fflush(stdin);
                while(ch=getchar())
                {
                    if(ch=='Y'||ch=='y')
                    {
                        delete adm;
                        cout << "完成注销！返回上级菜单" << endl;
                        system("pause");
                        system("cls");
                        return;
                    }
                    else if(ch=='N'||ch=='n')
                    {
                        cout << "确认取消，返回菜单中" << endl;
                        break;
                    }
                    else
                    {
                        cout << "输入有误，请重新输入：" << endl;
                    }
                    fflush(stdin);
                }
                break;
            case 1:
            //添加账号
                adm->addID();
                break;
            case 2:
            //查看账号
                adm->showID();
                break;
            case 3:
            //查看机房
                adm->showPC();
                break;
            case 4:
            //查看记录
                adm->showRcrd();
                break;
            case 5:
            //清空记录
                adm->clearRcrd();
                break;
            default:
                cout << "输入错误！" << endl;
                break;
        }
    system("pause");
    system("cls");
    }
}

void stuMenu(ID *person)
{
    student *stu= (student *)person;
    while(1)
    {    
        stu->show_menu();
        int select;
        cout << "请输入您的选择：" << endl;
        cin >> select;
        switch(select)
        {
            case 0:
            //注销
                cout << "确认注销：（Y/N）" << endl;
                char ch;
                fflush(stdin);
                while(ch=getchar())
                {
                    if(ch=='Y'||ch=='y')
                    {
                        delete stu;
                        cout << "完成注销！返回上级菜单" << endl;
                        system("pause");
                        system("cls");
                        return;
                    }
                    else if(ch=='N'||ch=='n')
                    {
                        cout << "确认取消，返回菜单中" << endl;
                        break;
                    }
                    else
                    {
                        cout << "输入有误，请重新输入：" << endl;
                    }
                    fflush(stdin);
                }
                break;
            case 1:
            //申请机器
                stu->applyOrder();
                break;
            case 2:
            //查看我的申请记录
                stu->showMyOrder();
                break;
            case 3:
            //查看所有申请记录
                stu->showAllOrder();
                break;
            case 4:
            //取消申请
                stu->cancelOrder();
                break;
            default:
                cout << "输入错误！" << endl;
                break;
        }
    system("pause");
    system("cls");

    }


    
}

void tchrMenu(ID *person)
{
    //类型强转
    teacher *tchr= (teacher *)person;
    while(1)
    {    
        tchr->show_menu();
        int select;
        cout << "请输入您的选择：" << endl;
        cin >> select;
        switch(select)
        {
            case 0:
            //注销
                cout << "确认注销：（Y/N）" << endl;
                char ch;
                fflush(stdin);
                while(ch=getchar())
                {
                    if(ch=='Y'||ch=='y')
                    {
                        delete tchr;
                        cout << "完成注销！返回上级菜单" << endl;
                        system("pause");
                        system("cls");
                        return;
                    }
                    else if(ch=='N'||ch=='n')
                    {
                        cout << "确认取消，返回菜单中" << endl;
                        break;
                    }
                    else
                    {
                        cout << "输入有误，请重新输入：" << endl;
                    }
                    fflush(stdin);
                }
                break;
            case 1:
            //查看所有申请记录
                tchr->showAllOrder();
                break;
            case 2:
            //审核申请
                tchr->validOrder();
                break;
            default:
                cout << "输入错误！" << endl;
                break;
        }
    system("pause");
    system("cls");

    }
}

void personCheck(string filename, int type) 
{
    ID *person = NULL;          //父类指针

    ifstream ifs;
    ifs.open(filename, ios::in);//用于实现登录验证

    //////////////检测机制//////////////////
    if(!ifs.is_open())
    {
        cout << "该文件不存在！" << endl;
        return;
    }
    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        cout << "该文件为空！" << endl;
        return;
    }
    ifs.putback(ch);
    //////////////检测机制//////////////////


    //输入登录信息 
    int flag;
    string name;
    string pwd;


    if(type==1)
    {
        
        cout << "请输入学号：" << endl;
        cin >> flag;
    }
    else if(type==2)
    {
        
        cout << "请输入职工号：" << endl;
        cin >> flag;
    }

    cout << "请输入您的用户名：" << endl;
    cin >> name;

    cout << "请输入您的密码：" << endl;
    cin >> pwd;

    ///////////////////身份认证模块////////////////////////
    if(type==1)
    {
        int sid;
        string fname;
        string fpwd;

        //用文件指针ifs
        while (ifs >> sid && ifs >> fname && ifs >> fpwd)
        {
            if (sid == flag && fname == name && fpwd == pwd)
            {
                cout << "学生身份认证成功！" << endl;
                //1. 创建人类对象，用一开始的person类
                person = new student(sid,name, pwd);
                //2. 进入子类菜单
                stuMenu(person);

                return;
            }
        }
    }
    else if(type==2)
    {
        int sid;
        string fname;
        string fpwd;

        //用文件指针ifs
        while (ifs >> sid && ifs >> fname && ifs >> fpwd)
        {
            if (sid == flag && fname == name && fpwd == pwd)
            {
                cout << "职工身份认证成功！" << endl;
                //1. 创建人类对象，用一开始的person类
                person = new teacher(sid,name, pwd);
                //2. 进入子类菜单
                tchrMenu(person);

                return;
            }
        }




    }
    else
    {
        string fname;
        string fpwd;

        //用文件指针ifs
        while (ifs >> fname && ifs >> fpwd)
        {
            if (fname == name && fpwd == pwd)
            {
                cout << "管理员身份认证成功！" << endl;
                //1. 创建人类对象，用一开始的person类
                person = new Adm(name, pwd);
                //2. 进入子类菜单功能
                manageMenu(person);

                return;
            }
        }
    }

    cout << "认证失败！即将返回主菜单" << endl;

    fflush(stdin);

    system("pause");
    system("cls");
    return;
}