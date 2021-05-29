#pragma once
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class ID
{
public:

    virtual void show_menu() = 0;       //等于0的虚函数用于子类重写父类中的成员函数

    string m_name;
    string m_pwd;
};