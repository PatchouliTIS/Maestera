#include "ApntmtSys.h"
#define TEST 1

int main()
{
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
                as.start_Spch();
                break;
            case 2:         //查看记录
                break;
            case 3:        //清空记录
                break;

                default:
                system("cls");
                break;
        }
    }
    return 0;
}