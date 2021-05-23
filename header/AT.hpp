#pragma once
#include<iostream>
#include<string>
#define TEST 1
using namespace std;


template<class T>
class ArrTP
{
public:
    ArrTP(int maxsize)
    {
#ifdef TEST
        cout << "���캯������" << endl;
#endif
        this->max_size = maxsize;
        this->cur_size = 0;
        this->tp = new T[this->max_size];
    }

    //1.ǳ����ת��Ϊ���
    //���캯�����
    ArrTP(const ArrTP &p)
    {
        this->max_size = p.max_size;
        this->cur_size = p.cur_size;
        //��������ⴴ���µĶ�����ַ���Է�������ַ�ظ��ͷ�
        this->tp = new T[this->max_size];
        //��������
        for (int i = 0; i < p.cur_size; i++)
        {
            this->tp[i] = p.tp[i];
        }
    }


    //���ظ�ֵ��������
    ArrTP& operator=(const ArrTP &p)
    {
#ifdef TEST
        cout << "����=" << endl;
#endif
        //��������Ѿ������ݣ�������ն�������
        if(this->tp!=NULL)
        {
            delete[] this->tp;
            this->tp = NULL;
            //����������Ϊ֮��Ḵд�����Կ��Բ�����
        }

        this->max_size = p.max_size;
        this->cur_size = p.cur_size;
        //��������ⴴ���µĶ�����ַ���Է�������ַ�ظ��ͷ�
        this->tp = new T[this->max_size];
        //��������
        for (int i = 0; i < p.cur_size; i++)
        {
            this->tp[i] = p.tp[i];
        }

        return *this; //this��ָ�룬�����ú��Ϊ��ArrTP
    }

    //2. ������������Ԫ��
    void print()
    {
        if(this->cur_size!=0)
        {
            for (int i = 0; i < this->cur_size;i++)
            {
                cout << this->tp[i] << " ";
            }
            cout << endl;
        }
        else 
        {
            cout << "����Ϊ�գ�" << endl;
        }
    }
    //3. β�巨��������Ԫ��
    void insert(const T &num)
    {
        if(this->cur_size+1<=this->max_size)
        {
            this->tp[this->cur_size] = num;
            ++this->cur_size;
        }
        else
        {
            cout << "�ռ����������ʧ�ܣ�" << endl;
        }

    }
    //4. βɾ��ɾ������Ԫ��
    void pop()
    {
        if(this->cur_size>0)
        {
            --this->cur_size;
        }
        else
        {
            cout << "����Ϊ�գ�ɾ��ʧ�ܣ�" << endl;
        }
    }
    //5. ���������[]��ʹ�ÿ���ͨ�������±�ֱ�ӷ�����ģ������Ԫ��
    T& operator[](const int& index)//����������±�
    {
        return this->tp[index];
    }
    
    
    
    
    
    //��������
    ~ArrTP()            //���������ͷŶ����洢�ռ�
    {
#ifdef TEST
        cout << "������������" << endl;
#endif
        if(this->tp!=NULL)//��ȫ������ж�
        {
            delete[] this->tp;
            this->tp = NULL;
        }
    }



private:
    T *tp;              //ָ��ָ��������ٵ������ʵ�ʴ洢�ռ�
    int max_size;
    int cur_size;
};
