#include "orderFile.h"

mngFile::orderFile()
{
    ifstream ifs;
    ifs.open(Order_FILE, ios::in);
    this->m_clause = 0;

    string date;      //日期
	string interval;  //时间段
	string stuId;     //学生编号
	string stuName;   //学生姓名
	string roomId;    //机房编号
	string status;    //预约状态

    string key, val;
    int pos;
    map<string, string> mTmp;

    while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
    {
        //分段截取字符串中的数据
        ////date
        pos = date.find(":");
        if(pos!=-1)
        {
            key = date.substr(0, pos);
            val = date.substr(pos + 1, date.size() - pos - 1);
            //压入小map
            mTmp.insert(make_pair(key, val));
        }

        ////interval
        pos = interval.find(":");
        if(pos!=-1)
        {
            key = interval.substr(0, pos);
            val = interval.substr(pos + 1, interval.size() - pos - 1);
            //压入小map
            mTmp.insert(make_pair(key, val));
        }


        ////stuID
        pos = stuID.find(":");
        if(pos!=-1)
        {
            key = stuID.substr(0, pos);
            val = stuID.substr(pos + 1, stuID.size() - pos - 1);
            //压入小map
            mTmp.insert(make_pair(key, val));
        }
        

        ////stuName
        pos = stuName.find(":");
        if(pos!=-1)
        {
            key = stuName.substr(0, pos);
            val = stuName.substr(pos + 1, stuName.size() - pos - 1);
            //压入小map
            mTmp.insert(make_pair(key, val));
        }



        ////roomId
        pos = roomId.find(":");
        if(pos!=-1)
        {
            key = roomId.substr(0, pos);
            val = roomId.substr(pos + 1, roomId.size() - pos - 1);
            //压入小map
            mTmp.insert(make_pair(key, val));
        }



        ////status
        pos = status.find(":");
        if(pos!=-1)
        {
            key = status.substr(0, pos);
            val = status.substr(pos + 1, status.size() - pos - 1);
            //压入小map
            mTmp.insert(make_pair(key, val));
        }



        //一次申请已经全部录入完毕
        this->m_orderData.insert(make_pair(this->m_clause, mTmp));
        this->m_clause++;

        ifs.close();
    }
}

void mngFile::updateOrder()
{

}