#include<iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;



int main(){
    workerManager wm;

    // Worker* wk=NULL;
    // wk=new Employee(1,"�����ƶ�",1);
    // wk->showInfo();


    // Worker* bs=NULL;
    // bs=new Boss(2,"����",1);
    // bs->showInfo();
    
    int mk=0;   //�û�ѡ��ѡ��
    while(true){        //��ѭ������ѡ��0ʱ���˳�exit(0)
        wm.Show_menu();
        cout<<"����������ѡ��"<<endl;
        cin>>mk;
        switch(mk)
        {
        case 0:
            wm.exitSystem();
            break;
        case 1://�����ְ��
            wm.Add_Emp();
            break;
        case 2://��ʾְ����Ϣ
            wm.show_Emp();
            break;
        case 3://ɾ����ְ��Ա
            wm.del_Emp();
            break;
        case 4://�޸�ְ����Ϣ
            wm.mod_Emp();
            break;
        case 5://����ְ����Ϣ
            wm.search_Emp();
            break;
        case 6://���ձ������
            wm.sort_Emp();
            break;
        case 7://��������ĵ�
            wm.fileClear();
            break;
        default:
            system("cls");      //�����Ļ
            break;
        }
    }
    system("pause");
    return 0;
}

