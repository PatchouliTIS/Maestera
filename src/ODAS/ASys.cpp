#include "ApntmtSys.h"

ASys::ASys()
{
    this->initSpeech();

    this->create_Spkr();
}

void ASys::initSpeech()
{
    this->v_r1.clear();
    this->v_r2.clear();
    this->vVictory.clear();
    this->map_Spkr.clear();

    this->m_Round = 1;      //重置比赛为第一轮
}

void ASys::create_Spkr()
{
    string name_seed = {"ABCDEFGHIJKL"};
    for (int i = 0; i < 12; i++)
    {
        Speaker sp;
        string name = "选手";
        name += name_seed[i];
        sp.m_name = name;

        for (int j = 0; j < 2; j++)
        {
            sp.m_score[j] = 0;
        }

        this->v_r1.push_back(i + 810);
        this->map_Spkr.insert(make_pair(i + 810, sp));
    }
}

void ASys::show_menu()
{  
    cout<<"**********************************"<<endl;
    cout<<"******欢迎使用辩论赛管理系统******"<<endl;
    cout<<"**********0.退出比赛程序**********"<<endl;
    cout<<"**********1.开始演讲比赛**********"<<endl;
    cout<<"**********2.查看往届记录**********"<<endl;
    cout<<"**********3.清空演讲比赛**********"<<endl;
    cout<<"**********************************"<<endl;
    cout<<endl;
}

void ASys::start_Spch()
{
    cout << "第" << this->m_Round << "轮小组比赛成员正在抽签:" << endl;
    cout << "-------------------------------------" << endl;
    if(this->m_Round==1)
    {
        random_shuffle(this->v_r1.begin(), this->v_r1.end());
        for (vector<int>::iterator it = this->v_r1.begin(); it != this->v_r1.end();it++)
        {
            cout << *it << "  ";
            cout << endl;
        }
    
    }
    else
    {
        random_shuffle(this->v_r2.begin(), this->v_r2.end());
        for (vector<int>::iterator it = this->v_r2.begin(); it != this->v_r2.end();it++)
        {
            cout << *it << "  ";
            cout << endl;
        }
    }
    cout << "----------------------------------" << endl;
    cout << "抽签完毕，准备比赛！" << endl;
    system("pause");
}

void ASys::quitSys()
{
    cout << "欢迎下次使用！" << endl;
    exit(0);
}


ASys::~ASys()
{

}