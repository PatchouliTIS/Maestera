#pragma once        //�ñ���ָʾ���µ��ļ�ֻ����һ��

#include<iostream>
#include<fstream>
#include<map>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#define FNAME "C:/Users/ASUS/Desktop/VMshare/out/empFile.txt"
using namespace std;
//����һ�������࣬���ڹ�����ʾְ����Ϣ
class workerManager
{
public:

    int emp_num;        //ְ��������

    Worker **ptr;       //�ö������鱣��ְ����
    
    bool m_isFileEmpty; //��ȡ�ļ�ʱ�����ж��ļ��Ƿ�Ϊ��

    map<int, int> disc;//���ڲ���������жϣ�ӳ��:ְ����ָ�������±�---->ְ�����

    workerManager();//���캯��

    void Show_menu();

    void Add_Emp();

    void save();//�����ļ�����

    void exitSystem();//�˳�����ϵͳ

    int get_empNum();//ͳ��Ŀ���ļ��е�ְ����¼��Ŀ����

    void init_EmpArr();//��ʼ��ְ����ָ������

    void show_Emp();//��ʾְ��

    void del_Emp();//ɾ��ְ����¼

    int isEmpExist(int num);//�ж���ְԱ���Ƿ����

    void mod_Emp();//�޸�ְ����¼

    void search_Emp();//����ְ����Ϣ

    void sort_Emp();//����

    void sortByName(int flag);

    void sortByID(int flag);

    void fileClear();//����ĵ�

    ~workerManager();//��������

};