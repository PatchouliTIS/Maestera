#pragma once
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class ID
{
public:
    ID();

    virtual void show_menu() = 0;       //����0���麯������������д�����еĳ�Ա����

    ~ID();

private:
    string m_name;
    string m_pswd;
};