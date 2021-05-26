#pragma once
#include<bits/stdc++.h>
#include "ID.h"
using namespace std;
class student:public ID
{
public:
    student();

    student(int id, string name, string psw);

    virtual void show_menu();

    void apllyOrder();

    void showMyOrder();

    void showAllOrder();

    void cancelOrder();

private:
    int m_Sid;
};

