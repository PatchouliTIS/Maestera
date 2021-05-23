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

    this->m_Round = 1;      //���ñ���Ϊ��һ��
}

void ASys::create_Spkr()
{
    string name_seed = {"ABCDEFGHIJKL"};
    for (int i = 0; i < 12; i++)
    {
        Speaker sp;
        string name = "ѡ��";
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
    cout<<"******��ӭʹ�ñ���������ϵͳ******"<<endl;
    cout<<"**********0.�˳���������**********"<<endl;
    cout<<"**********1.��ʼ�ݽ�����**********"<<endl;
    cout<<"**********2.�鿴�����¼**********"<<endl;
    cout<<"**********3.����ݽ�����**********"<<endl;
    cout<<"**********************************"<<endl;
    cout<<endl;
}

void ASys::start_Spch()
{
    cout << "��" << this->m_Round << "��С�������Ա���ڳ�ǩ:" << endl;
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
    cout << "��ǩ��ϣ�׼��������" << endl;
    system("pause");
}

void ASys::quitSys()
{
    cout << "��ӭ�´�ʹ�ã�" << endl;
    exit(0);
}


ASys::~ASys()
{

}