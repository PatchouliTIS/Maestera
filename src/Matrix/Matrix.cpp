#include "Matrix.h"

Matrix::Matrix()
{
    (int *)ans[] = new int[1024][1024];
    this->isExist = false;
}

void Matrix::show_menu()
{
    cout<<"**********************************"<<endl;
    cout<<"*********��ӭʹ�þ��������********"<<endl;
    cout<<"**********0.�˳�����**************"<<endl;
    cout<<"**********1.¼�����**************"<<endl;
    cout<<"**********2.��ת�þ���*************"<<endl;
    cout<<"**********3.�������**************"<<endl;
    cout<<"**********************************"<<endl;
    cout<<endl;
}

void Matrix::newM(int row,int clm)
{
    cout << "����������кţ�" << endl;
    cin >> row;
    cout << "����������кţ�" << endl;
    cin >> clm;

    cout << "���������Ԫ�أ��������󣬴��ϵ��£�" << endl;
    for (int i = 0; i < row * clm;i++)
    {
        int tmp;
        cin >> tmp;
        ans[i / row][i % row] = tmp;
    }

    cout << "¼����ϣ��������˵�" << endl;
    system("pause");
    system("cls");
}

~Matrix::~Matrix()
{
    delete[][] ans;
}