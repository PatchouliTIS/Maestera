#pragma once
#include<bits/stdc++.h>
#include "ID.h"
#include "login_File.h"
using namespace std;
class student:public ID
{
public:
    student();

    student(int id, string name, string pwd);

    virtual void show_menu();

    void apllyOrder();

    void showMyOrder();

    void showAllOrder();

    void cancelOrder();

private:
    int m_Sid;
};

