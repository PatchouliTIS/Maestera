#pragma once
#include<bits/stdc++.h>
#include "ID.h"
#include "CPT.h"
#include "login_File.h"
using namespace std;

class teacher:public ID
{
public:
    teacher();

    teacher(int id, string name, string pwd);

    virtual void show_menu();

    void showAllOrder();

    void validOrder();

    vector<CPT> vCPT;

    int m_Tid;
};