//预约类   在读入预约文件的同时初始化一个map映射表来映射预约序号和预约者的关系
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
    //一条记录中包括一个完整的关键字到关键值的映射表
    map<int, map<string, string>> m_orderData;

    //预约条数，即第几条开始记录
    int m_clause;
};