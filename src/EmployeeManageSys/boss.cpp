#include "boss.h"

Boss::Boss(int id,string name,int Did)
{
    this->m_id=id;
    this->m_name=name;
    this->m_Did=Did;

}//����ʱ��ʼ��


void Boss::showInfo()
{
    cout<<"ְ����ţ�"<<this->m_id
        <<"\tְ��������"<<this->m_name
        <<"\t��λ��"<<this->getDept()
        <<"\t��λְ��"<<this->getDuty()<<endl;


}


string Boss::getDept()
{
    return string("�ϰ�");
}

string Boss::getDuty()
{
    return string("������ָ������");
}