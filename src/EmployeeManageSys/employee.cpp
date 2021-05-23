#include "employee.h"

Employee::Employee(int id,string name,int Did)
{
    this->m_id=id;
    this->m_name=name;
    this->m_Did=Did;

}//构造时初始化


void Employee::showInfo()
{
    cout<<"职工编号："<<this->m_id
        <<"\t职工姓名："<<this->m_name
        <<"\t岗位："<<this->getDept()
        <<"\t岗位职责："<<this->getDuty()<<endl;


}


string Employee::getDept()
{
    return string("员工");
}

string Employee::getDuty()
{
    return string("完成经理的任务");
}