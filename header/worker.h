#pragma once
#include<iostream>
#include<string>
using namespace std;


class Worker
{
public:

    virtual void showInfo() = 0;

    virtual string getDept() = 0;

    virtual string getDuty() = 0;

    int m_id;
    int m_Did;
    
    string m_name;


};