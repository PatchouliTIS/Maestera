#pragma once
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Matrix
{
public:
    Matrix();
    void setExist(bool i)
    {
        this->m_isExist = i;
    }
    bool isMExist()
    {
        return this->m_isExist;
    }

    void show_menu();

    void newM(int row, int clm);

    

    void Reverse();

    ~Matrix();

private:
    bool m_isExist;
};