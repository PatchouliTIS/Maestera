#pragma once

#include <iostream>
#include <string>

using namespace std;


class Speaker
{
public:
    string m_name;      //选手姓名
    //int m_num;   编号通过在管理类添加一个哈希表来对应
    double m_score[2];  //两轮的得分
};
