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
        cout << "����������ѡ��" << endl;
        cin >> flag;
        switch(flag)
        {
            case 0:         //�˳�����
                as.quitSys();
                break;
            case 1:         //��ʼ����
                as.start_Spch();
                break;
            case 2:         //�鿴��¼
                break;
            case 3:        //��ռ�¼
                break;

                default:
                system("cls");
                break;
        }
    }
    return 0;
}