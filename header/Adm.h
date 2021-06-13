#pragma once
#include<bits/stdc++.h>
#include "login_File.h"
#include "ID.h"
#include "CPT.h"
#include "student.h"
#include "teacher.h"
using namespace std;

class Adm:public ID
{
public:
    Adm();

    Adm(string name,string psw);

    virtual void show_menu();

    void addID();

    void showID();

    void showPC();

    void showRcrd();

    void clearRcrd();

    void initVector();

    bool checkRepeat(int id, int type);

    vector<student> vStu;
    vector<teacher> vTchr;
    vector<CPT> vCPT;
};
