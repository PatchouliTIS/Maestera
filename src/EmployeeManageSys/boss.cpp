#include "boss.h"

Boss::Boss(int id,string name,int Did)
{
    this->m_id=id;
    this->m_name=name;
    this->m_Did=Did;

}//构造时初始化


void Boss::showInfo()
{
    cout<<"职工编号："<<this->m_id
        <<"\t职工姓名："<<this->m_name
        <<"\t岗位："<<this->getDept()
        <<"\t岗位职责："<<this->getDuty()<<endl;


}


string Boss::getDept()
{
    return string("老板");
}

string Boss::getDuty()
{
    return string("给经理指派任务");
}