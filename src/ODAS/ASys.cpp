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

void ASys::draw_Spch()
{
    cout << "-------------------------------------" << endl;
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
    system("cls");
    this->show_menu();
}

void ASys::quitSys()
{
    cout << "��ӭ�´�ʹ�ã�" << endl;
    system("pause");
    exit(0);
}

void ASys::speechCommence()
{
    cout << "-----------------------------------------" << endl;
    cout << "��" << this->m_Round << "�ֱ�����ʽ��ʼ��" << endl;
    multimap<double, int, greater<double>> scr_Index;             //�ظ�Ԫ��map�����洢ÿ�α�������Ա�÷�

    int cnt = 0;
    vector<int> tmp;         //�洢�÷֣��ڴ��֮��Ҫ�ڷ����ϲ���
    if (this->m_Round == 1)
    {
        tmp = this->v_r1;
    }
    else
    {    
        tmp = this->v_r2;
    }

    
    
    for (vector<int>::iterator it = tmp.begin(); it != tmp.end();it++)
    {
        cnt++;      //ͳ������
        //ʮ����ί���
        deque<double> scrTp;
        for (int i = 0; i < 10;i++)
        {    
            double score = (rand() % 401 + 600) / (double)10;
            scrTp.push_back(score);
        }
        
    
        //�Է�����������ȥ����߷ֺ���ͷֲ��Ҽ������
        sort(scrTp.begin(), scrTp.end(), greater<double>());        //greater<double>() ģ�庯��
        scrTp.pop_back();         //ȥ����߷�
        scrTp.pop_front();        //ȥ����ͷ�

        double sum = accumulate(scrTp.begin(), scrTp.end(), 0.0f);
        double avg = sum / (double)10;

        //��ǰѡ�ֵ�ƽ����
        this->map_Spkr[*it].m_score[this->m_Round - 1] = avg;

        //����ź͵÷�װ������scr_Index��
        scr_Index.insert(make_pair(avg, (*it)));

        if (cnt % 6 == 0)
        {
            cout << "----------------------------------" << endl;
            cout << "��" << cnt / 6 << "С�����������£�" << endl;
            cout << "----------------------------------" << endl;
            //������
            int i = 1;
            for (multimap<double, int, greater<double>>::iterator it = scr_Index.begin(); it != scr_Index.end(); i++,it++)
            {
                cout << "��" << cnt/6 << "���ڵ�" << i << "��"
                     << "   "
                     << "��ţ�" << it->second << "   "
                     << "������" << this->map_Spkr[it->second].m_name << "   "
                     << "�÷֣�" << this->map_Spkr[it->second].m_score[this->m_Round - 1] << endl;
            }

            int j = 0;          //ȡǰ����
            for (multimap<double, int, greater<double>>::iterator it = scr_Index.begin(); it != scr_Index.end() && j < 3; j++, it++)
            {
                if(this->m_Round==1)
                {
                    this->v_r2.push_back((*it).second);
                }
                else
                {
                    this->vVictory.push_back((*it).second);
                }
            }

            scr_Index.clear();      //���ø���map��Ϊ��һ��6�˱Ƚ���׼��
            cout << endl;
        }
    }
    cout << "----------------------------------------" << endl;
    cout << "��" << this->m_Round << "�ֱ����Ѿ�������" << endl;
    cout << "----------------------------------------" << endl;
    system("pause");
    system("cls");
    this->show_menu();
}

void ASys::show_Outcome()
{
    vector<int> v;
    if(this->m_Round==1)
    {
        v = this->v_r2;
    }
    else
    {
        v = this->vVictory;
    }
    
    cout << "��ǰΪ��" << this->m_Round << "�ֱ������������Ϊ��" << endl;
    
    int i = 0;
    for (vector<int>::iterator it = v.begin(); it != v.end(); i++,it++)
    {
        cout << "��" << i+1 << "��ѡ�֣�"
             << "   "
             << "������" << this->map_Spkr[*it].m_name << "   "
             << "���:" << *it << "   "
             << "�÷֣�" << this->map_Spkr[*it].m_score[this->m_Round-1] << endl;
    }

    system("pause");
    system("cls");
    this->show_menu();
}

void ASys::start_speech()
{
    //��һ�ֱ�����ʼ
    //��ǩ
    this->draw_Spch();

    //������
    this->speechCommence();

    //��ʾ���
    this->show_Outcome();

    //�ڶ��ֿ�ʼ
    (this->m_Round)++;

    //��ǩ
    this->draw_Spch();

    //������
    this->speechCommence();

    //��ʾ���
    this->show_Outcome();


    //����ʤ���߽��
    this->save_file();
}

void ASys::save_file()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out | ios::app);

    for (vector<int>::iterator it = this->vVictory.begin(); it != this->vVictory.end();it++)
    {
        ofs << *it << ","
            << this->map_Spkr[*it].m_name << ",";
    }
    ofs << endl;

    ofs.close();
    cout << "----------------------------" << endl;
    cout << "�ļ�����ɹ���" << endl;
    system("pause");
    system("cls");
    this->show_menu();
}

ASys::~ASys()
{

}