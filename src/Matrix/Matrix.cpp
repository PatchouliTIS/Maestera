#include "Matrix.h"

Matrix::Matrix()
{
    (int *)ans[] = new int[1024][1024];
    this->isExist = false;
}

void Matrix::show_menu()
{
    cout<<"**********************************"<<endl;
    cout<<"*********欢迎使用矩阵计算器********"<<endl;
    cout<<"**********0.退出程序**************"<<endl;
    cout<<"**********1.录入矩阵**************"<<endl;
    cout<<"**********2.求转置矩阵*************"<<endl;
    cout<<"**********3.求逆矩阵**************"<<endl;
    cout<<"**********************************"<<endl;
    cout<<endl;
}

void Matrix::newM(int row,int clm)
{
    cout << "请输入矩阵行号：" << endl;
    cin >> row;
    cout << "请输入矩阵列号：" << endl;
    cin >> clm;

    cout << "请输入矩阵元素，从右至左，从上到下：" << endl;
    for (int i = 0; i < row * clm;i++)
    {
        int tmp;
        cin >> tmp;
        ans[i / row][i % row] = tmp;
    }

    cout << "录入完毕！返回主菜单" << endl;
    system("pause");
    system("cls");
}

~Matrix::~Matrix()
{
    delete[][] ans;
}