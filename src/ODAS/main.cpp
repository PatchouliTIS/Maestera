#include "ApntmtSys.h"

int main()
{
    ASys as;
    int flag;
    while(true)
    {
        as.show_menu();
        cout << "请输入您的选择：" << endl;
        cin >> flag;
        switch(flag)
        {
            case 0:
                as.quitSys();
                break;
            default:
                break;
        }
    }
    return 0;
}
