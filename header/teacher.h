#pragma once
#include<bits/stdc++.h>
#include "ID.h"
using namespace std;

class teacher
{
public:
    teacher();

    teacher(int id, string name, string psw);

    virtual void show_menu();

    void showAllOrder();

    void validOrder();

private:
    int m_Tid;
};