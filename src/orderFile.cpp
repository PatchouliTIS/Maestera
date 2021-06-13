#include "orderFile.h"

mngFile::orderFile()
{
    ifstream ifs;
    ifs.open(Order_FILE, ios::in);
    this->m_clause = 0;

    string date;      //����
	string interval;  //ʱ���
	string stuId;     //ѧ�����
	string stuName;   //ѧ������
	string roomId;    //�������
	string status;    //ԤԼ״̬

    string key, val;
    int pos;
    map<string, string> mTmp;

    while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
    {
        //�ֶν�ȡ�ַ����е�����
        ////date
        pos = date.find(":");
        if(pos!=-1)
        {
            key = date.substr(0, pos);
            val = date.substr(pos + 1, date.size() - pos - 1);
            //ѹ��Сmap
            mTmp.insert(make_pair(key, val));
        }

        ////interval
        pos = interval.find(":");
        if(pos!=-1)
        {
            key = interval.substr(0, pos);
            val = interval.substr(pos + 1, interval.size() - pos - 1);
            //ѹ��Сmap
            mTmp.insert(make_pair(key, val));
        }


        ////stuID
        pos = stuID.find(":");
        if(pos!=-1)
        {
            key = stuID.substr(0, pos);
            val = stuID.substr(pos + 1, stuID.size() - pos - 1);
            //ѹ��Сmap
            mTmp.insert(make_pair(key, val));
        }
        

        ////stuName
        pos = stuName.find(":");
        if(pos!=-1)
        {
            key = stuName.substr(0, pos);
            val = stuName.substr(pos + 1, stuName.size() - pos - 1);
            //ѹ��Сmap
            mTmp.insert(make_pair(key, val));
        }



        ////roomId
        pos = roomId.find(":");
        if(pos!=-1)
        {
            key = roomId.substr(0, pos);
            val = roomId.substr(pos + 1, roomId.size() - pos - 1);
            //ѹ��Сmap
            mTmp.insert(make_pair(key, val));
        }



        ////status
        pos = status.find(":");
        if(pos!=-1)
        {
            key = status.substr(0, pos);
            val = status.substr(pos + 1, status.size() - pos - 1);
            //ѹ��Сmap
            mTmp.insert(make_pair(key, val));
        }



        //һ�������Ѿ�ȫ��¼�����
        this->m_orderData.insert(make_pair(this->m_clause, mTmp));
        this->m_clause++;

        ifs.close();
    }
}

void mngFile::updateOrder()
{

}