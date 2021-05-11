#include "manager.h"

Manager::Manager(int id,string name,int Did)
{
    this->m_id=id;
    this->m_Did=Did;
    this->m_name=name;
}


void Manager::showInfo()
{
    cout<<"职工编号："<<this->m_id
        <<"\t职工姓名："<<this->m_name
        <<"\t岗位："<<this->getDept()
        <<"\t岗位职责："<<this->getDuty()<<endl;


}


string Manager::getDept()
{
    return string("经理");
}

string Manager::getDuty()
{
    return string("完成老板的任务，管理下属员工");
}

