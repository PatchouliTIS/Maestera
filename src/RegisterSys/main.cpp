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
        cout << "===============��ӭ��������������ԤԼϵͳ===============" << endl;
        cout << "\t\t\tR L T W\n"
            << "\t\t ----------------------- \n"
            << "\t\t|        1. ѧ��        |\n"
            << "\t\t|                       |\n"
            << "\t\t|        2. ��ʦ        |\n"
            << "\t\t|                       |\n"
            << "\t\t|       3. ����Ա       |\n"
            << "\t\t|                       |\n"
            << "\t\t|      0. �˳�ϵͳ      |\n"
            << "\t\t|                      |\n"
            << "\t\t ----------------------- \n";

        cin >> select;
        switch(select)
        {
            case 0:         //�˳�ϵͳ
                cout << "Ҫ�˳���(Y/N)" << endl;
                char flag;
                while(flag=getchar())
                {
                    fflush(stdin);
                    if(flag=='Y'||flag=='y')
                    {
                        cout << "��ӭ�´�ʹ�ã�" << endl;
                        system("pause");
                        exit(0);
                    }
                    else
                    {
                        cout << "���������������룺" << endl;
                    }
                }
                break;
            case 1:         //ѧ�������

                break;
            case 2:         //��ʦ�����

                break;
            case 3:         //����Ա�����

                break;

            default:
                cout << "�����������������룺" << endl;
                system("pause");
                system("cls");
                break;
        }
    }
    return 0;
}
