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
    // wk=new Employee(1,"田所浩二",1);
    // wk->showInfo();


    // Worker* bs=NULL;
    // bs=new Boss(2,"张三",1);
    // bs->showInfo();
    
    int mk=0;   //用户选择选项
    while(true){        //死循环，当选择0时才退出exit(0)
        wm.Show_menu();
        cout<<"请输入您的选择："<<endl;
        cin>>mk;
        switch(mk)
        {
        case 0:
            wm.exitSystem();
            break;
        case 1://添加新职工
            wm.Add_Emp();
            break;
        case 2://显示职工信息
            wm.show_Emp();
            break;
        case 3://删除离职人员
            wm.del_Emp();
            break;
        case 4://修改职工信息
            wm.mod_Emp();
            break;
        case 5://查找职工信息
            wm.search_Emp();
            break;
        case 6://按照编号排序
            wm.sort_Emp();
            break;
        case 7://清空所有文档
            wm.fileClear();
            break;
        default:
            system("cls");      //清空屏幕
            break;
        }
    }
    system("pause");
    return 0;
}

