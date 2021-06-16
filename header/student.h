#pragma once
#include<bits/stdc++.h>
#include "ID.h"
#include "CPT.h"
#include "login_File.h"
#include "orderFile.h"
using namespace std;
class student:public ID
{
public:
    student();

    student(int id, string name, string pwd);

    virtual void show_menu();

    void applyOrder();

    void showMyOrder();

    void showAllOrder();

    void cancelOrder();

    void initVector();


    int m_Sid;

    vector<CPT> vCPT;
};

