#pragma once
#include <bits/stdc++.h>
#include "login_File.h"

using namespace std;

class orderFile
{
public:
    orderFile();

    //更新数据文件管理类
    void updateOrder();

    //文件映射数据结构
    map<int, map<string, string>> m_orderData;

    //预约条数，即第几条开始记录
    int m_clause;
};