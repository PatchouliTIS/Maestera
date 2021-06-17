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

void manageMenu(ID *person);//����Ա�˵��ӿ�

void stuMenu(ID *person);//ѧ���˵��ӿ�

void tchrMenu(ID *person);//ְ���˵��ӿ�

int main()
{
    while(1)
    {
        int select;
        cout << "===============��ӭ��������������ԤԼϵͳ===============" << endl;
        cout << "\t\t\tR L T W\n"
            << "\t\t ------------------------ \n"
            << "\t\t|        1. ѧ��          |\n"
            << "\t\t|                         |\n"
            << "\t\t|        2. ��ʦ          |\n"
            << "\t\t|                         |\n"
            << "\t\t|       3. ����Ա         |\n"
            << "\t\t|                        |\n"
            << "\t\t|      0. �˳�ϵͳ        |\n"
            << "\t\t|                        |\n"
            << "\t\t ------------------------ \n";
        cout << "����������ѡ��" << endl;
        cin >> select ;
        switch(select)
        {
            case 0:         //�˳�ϵͳ
                cout << "Ҫ�˳���(Y/N)" << endl;
                char flag;
                fflush(stdin);
                while(flag=getchar())
                {
                    if(flag=='Y'||flag=='y')
                    {
                        cout << "��ӭ�´�ʹ�ã�" << endl;
                        system("pause");
                        exit(0);
                    }
                    else if(flag=='N'||flag=='n')
                    {
                        cout << "����ȡ�����������˵���" << endl;
                        break;
                    }
                    else
                    {
                        cout << "���������������룺" << endl;
                    }
                    fflush(stdin);
                }
                break;
            case 1:         //ѧ�������
                personCheck(Std_FILE, 1);       //��ʼ���ļ��������
                break;
            case 2:         //��ʦ�����
                personCheck(Tch_FILE, 2);
                break;
            case 3:         //����Ա�����
                personCheck(Adm_FILE, 3);       //�ڽӲ˵��ӿ�
                break;

            default:
                cout << "�����������������룺" << endl;
                break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}


void manageMenu(ID *person)
{
    Adm *adm = (Adm *)person;       //����ǿת��
    while(1)
    {
        adm->show_menu();
        int select;
        cout << "����������ѡ��" << endl;
        cin >> select;
        switch(select)
        {
            case 0:
            //ע��
                cout << "ȷ��ע������Y/N��" << endl;
                char ch;
                fflush(stdin);
                while(ch=getchar())
                {
                    if(ch=='Y'||ch=='y')
                    {
                        delete adm;
                        cout << "���ע���������ϼ��˵�" << endl;
                        system("pause");
                        system("cls");
                        return;
                    }
                    else if(ch=='N'||ch=='n')
                    {
                        cout << "ȷ��ȡ�������ز˵���" << endl;
                        break;
                    }
                    else
                    {
                        cout << "�����������������룺" << endl;
                    }
                    fflush(stdin);
                }
                break;
            case 1:
            //�����˺�
                adm->addID();
                break;
            case 2:
            //�鿴�˺�
                adm->showID();
                break;
            case 3:
            //�鿴����
                adm->showPC();
                break;
            case 4:
            //�鿴��¼
                adm->showRcrd();
                break;
            case 5:
            //��ռ�¼
                adm->clearRcrd();
                break;
            default:
                cout << "�������" << endl;
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
        cout << "����������ѡ��" << endl;
        cin >> select;
        switch(select)
        {
            case 0:
            //ע��
                cout << "ȷ��ע������Y/N��" << endl;
                char ch;
                fflush(stdin);
                while(ch=getchar())
                {
                    if(ch=='Y'||ch=='y')
                    {
                        delete stu;
                        cout << "���ע���������ϼ��˵�" << endl;
                        system("pause");
                        system("cls");
                        return;
                    }
                    else if(ch=='N'||ch=='n')
                    {
                        cout << "ȷ��ȡ�������ز˵���" << endl;
                        break;
                    }
                    else
                    {
                        cout << "�����������������룺" << endl;
                    }
                    fflush(stdin);
                }
                break;
            case 1:
            //�������
                stu->applyOrder();
                break;
            case 2:
            //�鿴�ҵ������¼
                stu->showMyOrder();
                break;
            case 3:
            //�鿴���������¼
                stu->showAllOrder();
                break;
            case 4:
            //ȡ������
                stu->cancelOrder();
                break;
            default:
                cout << "�������" << endl;
                break;
        }
    system("pause");
    system("cls");

    }


    
}

void tchrMenu(ID *person)
{
    //����ǿת
    teacher *tchr= (teacher *)person;
    while(1)
    {    
        tchr->show_menu();
        int select;
        cout << "����������ѡ��" << endl;
        cin >> select;
        switch(select)
        {
            case 0:
            //ע��
                cout << "ȷ��ע������Y/N��" << endl;
                char ch;
                fflush(stdin);
                while(ch=getchar())
                {
                    if(ch=='Y'||ch=='y')
                    {
                        delete tchr;
                        cout << "���ע���������ϼ��˵�" << endl;
                        system("pause");
                        system("cls");
                        return;
                    }
                    else if(ch=='N'||ch=='n')
                    {
                        cout << "ȷ��ȡ�������ز˵���" << endl;
                        break;
                    }
                    else
                    {
                        cout << "�����������������룺" << endl;
                    }
                    fflush(stdin);
                }
                break;
            case 1:
            //�鿴���������¼
                tchr->showAllOrder();
                break;
            case 2:
            //�������
                tchr->validOrder();
                break;
            default:
                cout << "�������" << endl;
                break;
        }
    system("pause");
    system("cls");

    }
}

void personCheck(string filename, int type) 
{
    ID *person = NULL;          //����ָ��

    ifstream ifs;
    ifs.open(filename, ios::in);//����ʵ�ֵ�¼��֤

    //////////////������//////////////////
    if(!ifs.is_open())
    {
        cout << "���ļ������ڣ�" << endl;
        return;
    }
    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        cout << "���ļ�Ϊ�գ�" << endl;
        return;
    }
    ifs.putback(ch);
    //////////////������//////////////////


    //�����¼��Ϣ 
    int flag;
    string name;
    string pwd;


    if(type==1)
    {
        
        cout << "������ѧ�ţ�" << endl;
        cin >> flag;
    }
    else if(type==2)
    {
        
        cout << "������ְ���ţ�" << endl;
        cin >> flag;
    }

    cout << "�����������û�����" << endl;
    cin >> name;

    cout << "�������������룺" << endl;
    cin >> pwd;

    ///////////////////������֤ģ��////////////////////////
    if(type==1)
    {
        int sid;
        string fname;
        string fpwd;

        //���ļ�ָ��ifs
        while (ifs >> sid && ifs >> fname && ifs >> fpwd)
        {
            if (sid == flag && fname == name && fpwd == pwd)
            {
                cout << "ѧ��������֤�ɹ���" << endl;
                //1. �������������һ��ʼ��person��
                person = new student(sid,name, pwd);
                //2. ��������˵�
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

        //���ļ�ָ��ifs
        while (ifs >> sid && ifs >> fname && ifs >> fpwd)
        {
            if (sid == flag && fname == name && fpwd == pwd)
            {
                cout << "ְ��������֤�ɹ���" << endl;
                //1. �������������һ��ʼ��person��
                person = new teacher(sid,name, pwd);
                //2. ��������˵�
                tchrMenu(person);

                return;
            }
        }




    }
    else
    {
        string fname;
        string fpwd;

        //���ļ�ָ��ifs
        while (ifs >> fname && ifs >> fpwd)
        {
            if (fname == name && fpwd == pwd)
            {
                cout << "����Ա������֤�ɹ���" << endl;
                //1. �������������һ��ʼ��person��
                person = new Adm(name, pwd);
                //2. ��������˵�����
                manageMenu(person);

                return;
            }
        }
    }

    cout << "��֤ʧ�ܣ������������˵�" << endl;

    fflush(stdin);

    system("pause");
    system("cls");
    return;
}