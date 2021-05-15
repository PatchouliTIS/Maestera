#pragma once        //该编译指示器下的文件只被打开一次

#include<iostream>
#include<fstream>
#include<map>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#define FNAME "C:/Users/ASUS/Desktop/VMshare/out/empFile.txt"
using namespace std;
//声明一个管理类，用于管理、显示职工信息
class workerManager
{
public:

    int emp_num;        //职工总人数

    Worker **ptr;       //用堆区数组保存职工类
    
    bool m_isFileEmpty; //读取文件时用于判断文件是否为空

    map<int, int> disc;//用于插入数组的判断，映射:职工类指针数组下标---->职工编号

    workerManager();//构造函数

    void Show_menu();

    void Add_Emp();

    void save();//保存文件函数

    void exitSystem();//退出管理系统

    int get_empNum();//统计目标文件中的职工记录条目个数

    void init_EmpArr();//初始化职工类指针数组

    void show_Emp();//显示职工

    void del_Emp();//删除职工记录

    int isEmpExist(int num);//判断离职员工是否存在

    void mod_Emp();//修改职工记录

    void search_Emp();//查找职工信息

    void sort_Emp();//排序

    void sortByName(int flag);

    void sortByID(int flag);

    void fileClear();//清空文档

    ~workerManager();//析构函数

};