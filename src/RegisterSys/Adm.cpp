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
    cout << "===============��ӭ������Ա===============" << endl;
    cout << "\t\t\tR L T W\n"
        << "\t\t --------------------------- \n"
        << "\t\t|        1. ����˺�        |\n"
        << "\t\t|                          |\n"
        << "\t\t|        2. �鿴�˺�        |\n"
        << "\t\t|                          |\n"
        << "\t\t|        3. �鿴����        |\n"
        << "\t\t|                          |\n"
        << "\t\t|        4. �鿴ԤԼ        |\n"
        << "\t\t|                          |\n"
        << "\t\t|        5. ���ԤԼ        |\n"
        << "\t\t|                          |\n"
        << "\t\t|        0. ע����¼        |\n"
        << "\t\t --------------------------- \n";
}

void Adm::addID()
{
    string filename;
    string tip;
    string errortip;
    while(1)
    {
        cout << "��ѡ����Ӷ���" << endl;
        cout << "1.���ѧ���˺�" << endl;
        cout << "2.���ְ���˺�" << endl;

        int flag,mk=1;
        while(mk)
        {
            cin >> flag;        //ѡ����ӵ��˺�����
            switch(flag)
            {
                case 1:         //��ʦ
                    filename = Std_FILE;
                    tip = "������ѧ�ţ�";
                    errortip = "ѧ���ظ������������룺";
                    mk = 0;
                    break;
                case 2:         //ѧ��
                    filename = Tch_FILE;
                    tip = "������ְ���ţ�";
                    errortip = "ְ�����ظ������������룺";
                    mk = 0;
                    break;
                default:
                    cout << "�����������������" << endl;
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
            cout << "�ļ������ڣ��޷�ִ�С������ϼ��˵�" << endl;
            return;
        }

        cout << tip << endl;
        cin >> id;              //�����˺�����
        //ȥ�ز���
        while(!this->checkRepeat(id,flag))      //˳���������
        {
            cout << errortip << endl;
            cin >> id;
        }

        cout << "�������˺ţ�" << endl;
        cin >> name;

        cout << "���������룺" << endl;
        cin >> pwd;

        ofs << id << " " << name << " " << pwd << " " << endl;

        cout << "��ӳɹ���" << endl;
        ofs.close();

        //////////////////////////
        //ÿ��ͨ���������˺�֮�����ļ�����������д�ؼ�¼�ļ�
        //�Դ˽������ӵļ�¼�޷����ص�����
        this->initVector();

        cout << "�Ƿ������ӣ�" << endl
            << "(Y/N)" << endl;
        char ch;
        fflush(stdin);
        while(cin>>ch)
        {
            if(ch=='N'||ch=='n')
            {
                cout << "��ӳɹ��������ϼ��˵�" << endl;
                system("pause");
                system("cls");
                return;
            }
            else if(ch!='Y'||ch!='y')
            {
                system("cls");
                fflush(stdin);
                break;
            }
            else
            {   
                cout << "����������������룺" << endl;
                system("pause");
            }
            fflush(stdin);
        }
    }
}


//��ʦ
void printTchr(teacher & t)
{
    cout << "ְ����ţ�" << t.m_Tid << "      "
         << "ְ���˺ţ�" << t.m_name << "      "
         << "ְ�����룺" << t.m_pwd << endl;
}

//ѧ��
void printStu(student & s)
{
    cout << "ѧ����ţ�" << s.m_Sid << "      "
         << "ѧ���˺ţ�" << s.m_name << "      "
         << "ѧ�����룺" << s.m_pwd << endl;
}


void Adm::showID()
{
    //ȫ�ֺ���,�������
    cout << "��ѡ��鿴����" << endl
         << "1. �鿴ѧ���˺�" << endl
         << "2. �鿴��ʦ�˺�" << endl;

    int select,mk=1;
    cin >> select;
    while(mk)
    {
        switch(select)
        {
            case 1:
                cout << "����ѧ����Ϣ���£�" << endl;
                for_each(vStu.begin(), vStu.end(), printStu);
                mk = 0;
                break;
            case 2:
                cout << "������ʦ��Ϣ���£�" << endl;
                for_each(vTchr.begin(), vTchr.end(), printTchr);
                mk = 0;
                break;
            default:
                cout << "����������������룺" << endl;
                break;
        }
    }

    system("pause");
    system("cls");
    return;
}

void Adm::showPC()
{
    //����ͷ�ļ��ﴴ��CPT.h  �����ṹ��ͷ�ļ�

    //��Adm��ʼ���ļ��г�ʼ��vCPT������������������ļ�
    cout << "���л�����Ϣ���£�" << endl;
    for (vector<CPT>::iterator it = this->vCPT.begin(); it != this->vCPT.end(); it++)
    {
        cout << "��" << it->m_Num << "�Ż���Ŀǰ����" << it->m_count << "̨�����ɹ�ʹ��" << endl;
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
    //1. ��ѧ����¼�ļ�
    ifs.open(Std_FILE, ios::in);
    if(!ifs.is_open())
    {
        cout << "�ļ������ڣ������ϼ��˵�" << endl;
        return;
    }

    while (ifs >> tmpS.m_Sid && ifs >> tmpS.m_name && ifs >> tmpS.m_pwd)
    {
        vStu.push_back(tmpS);
    }
    cout << "ϵͳ�й���" << vStu.size() << "��ѧ���˺�" << endl;
    ifs.close();

    cout << "===================================" << endl;

    //2. ����ʦ��¼�ļ�
    teacher tmpT;
    ifs.open(Tch_FILE, ios::in);
    if(!ifs.is_open())
    {
        cout << "�ļ������ڣ������ϼ��˵�" << endl;
        return;
    }

    while (ifs >> tmpT.m_Tid && ifs >> tmpT.m_name && ifs >> tmpT.m_pwd)
    {
        vTchr.push_back(tmpT);
    }
    cout << "ϵͳ�й���" << vTchr.size() << "��ְ���˺�" << endl;
    ifs.close();

    //3. �򿪻�����¼�ļ�
    CPT tmpC;
    ifs.open(PC_FILE, ios::in);
    if(!ifs.is_open())
    {
        cout << "�ļ������ڣ������ϼ��˵�" << endl;
        return;
    }

    while (ifs >> tmpC.m_Num && ifs >> tmpC.m_count)
    {
        vCPT.push_back(tmpC);
    }
    cout << "Ŀǰ����" << vCPT.size() << "�������ɹ�ʹ��" << endl;
    ifs.close();


    return;
}

void Adm::clearRcrd()
{
    ofstream ofs;
    ofs.open(Order_FILE, ios::trunc);
    ofs.close();

    cout << "ɾ���ɹ�����������������˵�" << endl;
    system("pause");
    system("cls");
}


bool Adm::checkRepeat(int id,int type)
{
    if (type == 1)      //ѧ��
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