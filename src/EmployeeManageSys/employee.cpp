#include "employee.h"

Employee::Employee(int id,string name,int Did)
{
    this->m_id=id;
    this->m_name=name;
    this->m_Did=Did;

}//����ʱ��ʼ��


void Employee::showInfo()
{
    cout<<"ְ����ţ�"<<this->m_id
        <<"\tְ��������"<<this->m_name
        <<"\t��λ��"<<this->getDept()
        <<"\t��λְ��"<<this->getDuty()<<endl;


}


string Employee::getDept()
{
    return string("Ա��");
}

string Employee::getDuty()
{
    return string("��ɾ��������");
}