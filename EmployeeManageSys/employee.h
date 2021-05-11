#pragma once
#include "worker.h"
using namespace std;

class Employee :public Worker
{
public:
    Employee(int id,string name,int Did);

    //显示个人信息
    void showInfo();

    //显示岗位信息
    string getDept();

    string getDuty();

    

};