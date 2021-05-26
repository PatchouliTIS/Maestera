#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    while(1)
    {
        int select;
        cout << "===============欢迎来到本宁堡机房预约系统===============" << endl;
        cout << "\t\t\tR L T W\n"
            << "\t\t ----------------------- \n"
            << "\t\t|        1. 学生        |\n"
            << "\t\t|                       |\n"
            << "\t\t|        2. 老师        |\n"
            << "\t\t|                       |\n"
            << "\t\t|       3. 管理员       |\n"
            << "\t\t|                       |\n"
            << "\t\t|      0. 退出系统      |\n"
            << "\t\t|                      |\n"
            << "\t\t ----------------------- \n";

        cin >> select;
        switch(select)
        {
            case 0:         //退出系统
                cout << "要退出吗？(Y/N)" << endl;
                char flag;
                while(flag=getchar())
                {
                    fflush(stdin);
                    if(flag=='Y'||flag=='y')
                    {
                        cout << "欢迎下次使用！" << endl;
                        system("pause");
                        exit(0);
                    }
                    else
                    {
                        cout << "输入错误！请从新输入：" << endl;
                    }
                }
                break;
            case 1:         //学生类调用

                break;
            case 2:         //老师类调用

                break;
            case 3:         //管理员类调用

                break;

            default:
                cout << "输入有误！请重新输入：" << endl;
                system("pause");
                system("cls");
                break;
        }
    }
    return 0;
}
