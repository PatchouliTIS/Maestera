#pragma once
#include "worker.h"
using namespace std;

class Employee :public Worker
{
public:
    Employee(int id,string name,int Did);

    //��ʾ������Ϣ
    void showInfo();

    //��ʾ��λ��Ϣ
    string getDept();

    string getDuty();

    

};