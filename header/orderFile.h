//ԤԼ��   �ڶ���ԤԼ�ļ���ͬʱ��ʼ��һ��mapӳ�����ӳ��ԤԼ��ź�ԤԼ�ߵĹ�ϵ
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
    //һ����¼�а���һ�������Ĺؼ��ֵ��ؼ�ֵ��ӳ���
    map<int, map<string, string>> m_orderData;

    //ԤԼ���������ڼ�����ʼ��¼
    int m_clause;
};