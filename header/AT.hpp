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
        cout << "构造函数调用" << endl;
#endif
        this->max_size = maxsize;
        this->cur_size = 0;
        this->tp = new T[this->max_size];
    }

    //1.浅拷贝转化为深拷贝
    //构造函数深拷贝
    ArrTP(const ArrTP &p)
    {
        this->max_size = p.max_size;
        this->cur_size = p.cur_size;
        //深拷贝，额外创建新的堆区地址，以防堆区地址重复释放
        this->tp = new T[this->max_size];
        //拷贝数据
        for (int i = 0; i < p.cur_size; i++)
        {
            this->tp[i] = p.tp[i];
        }
    }


    //重载赋值运算符深拷贝
    ArrTP& operator=(const ArrTP &p)
    {
#ifdef TEST
        cout << "重载=" << endl;
#endif
        //如果自身已经有数据，则先清空堆区数据
        if(this->tp!=NULL)
        {
            delete[] this->tp;
            this->tp = NULL;
            //其他数据因为之后会复写，所以可以不重置
        }

        this->max_size = p.max_size;
        this->cur_size = p.cur_size;
        //深拷贝，额外创建新的堆区地址，以防堆区地址重复释放
        this->tp = new T[this->max_size];
        //拷贝数据
        for (int i = 0; i < p.cur_size; i++)
        {
            this->tp[i] = p.tp[i];
        }

        return *this; //this是指针，解引用后成为类ArrTP
    }

    //2. 输入所有数组元素
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
            cout << "数组为空！" << endl;
        }
    }
    //3. 尾插法插入数组元素
    void insert(const T &num)
    {
        if(this->cur_size+1<=this->max_size)
        {
            this->tp[this->cur_size] = num;
            ++this->cur_size;
        }
        else
        {
            cout << "空间已满，添加失败！" << endl;
        }

    }
    //4. 尾删法删除数组元素
    void pop()
    {
        if(this->cur_size>0)
        {
            --this->cur_size;
        }
        else
        {
            cout << "数组为空，删除失败！" << endl;
        }
    }
    //5. 重载运算符[]，使得可以通过数组下标直接访问类模板数组元素
    T& operator[](const int& index)//传入的数组下标
    {
        return this->tp[index];
    }
    
    
    
    
    
    //析构函数
    ~ArrTP()            //析构函数释放堆区存储空间
    {
#ifdef TEST
        cout << "析构函数调用" << endl;
#endif
        if(this->tp!=NULL)//安全起见先判断
        {
            delete[] this->tp;
            this->tp = NULL;
        }
    }



private:
    T *tp;              //指针指向堆区开辟的数组的实际存储空间
    int max_size;
    int cur_size;
};
