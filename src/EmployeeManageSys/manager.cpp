#include "manager.h"

Manager::Manager(int id,string name,int Did)
{
    this->m_id=id;
    this->m_Did=Did;
    this->m_name=name;
}


void Manager::showInfo()
{
    cout<<"ְ����ţ�"<<this->m_id
        <<"\tְ��������"<<this->m_name
        <<"\t��λ��"<<this->getDept()
        <<"\t��λְ��"<<this->getDuty()<<endl;


}


string Manager::getDept()
{
    return string("����");
}

string Manager::getDuty()
{
    return string("����ϰ�����񣬹�������Ա��");
}

