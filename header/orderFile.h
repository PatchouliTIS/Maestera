#pragma once
#include <bits/stdc++.h>
#include "login_File.h"

using namespace std;

class orderFile
{
public:
    orderFile();

    //���������ļ�������
    void updateOrder();

    //�ļ�ӳ�����ݽṹ
    map<int, map<string, string>> m_orderData;

    //ԤԼ���������ڼ�����ʼ��¼
    int m_clause;
};