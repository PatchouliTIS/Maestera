#include "ApntmtSys.h"
#include<ctime>
// #define TEST 1

int main()
{

    srand((unsigned int)time(NULL));
    ASys as;
#ifdef TEST
    for (map<int, Speaker>::iterator it = as.map_Spkr.begin(); it != as.map_Spkr.end();it++)
    {
        cout << it->first << ' ' << it->second.m_name << ' ' << it->second.m_score[0] << endl;
    }
#endif
    int flag = 0;
    while(true)
    {
        as.show_menu();
        cout << "请输入您的选择：" << endl;
        cin >> flag;
        switch(flag)
        {
            case 0:         //退出程序
                as.quitSys();
                break;
            case 1:         //开始比赛
                as.start_speech();
                break;
            case 2:         //查看记录
                as.show_Record();
                break;
            case 3:        //清空记录
                as.clr_Record();
                break;
            default:
                cout << "输入错误！请重新输入：" << endl;
                system("pause");
                break;
        }
        system("cls");
    }
    return 0;
}
