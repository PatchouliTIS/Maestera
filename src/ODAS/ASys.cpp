#include "ApntmtSys.h"

ASys::ASys()
{
    this->initSpeech();

    this->create_Spkr();

    this->load_file();
}

void ASys::initSpeech()
{
    this->v_r1.clear();
    this->v_r2.clear();
    this->vVictory.clear();
    this->map_Spkr.clear();
    this->m_Record.clear();

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

    
    //�������в���ѡ��
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
        double avg = sum / 10;

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

    //���ù������������ݣ�ʹ����Խ�����һ�α���
    this->initSpeech();

    this->create_Spkr();

    this->load_file();

    

    cout << "*****************" << endl;
    cout << "��������ɹ����У�" << endl;


    system("pause");
    system("cls");
}

void ASys::save_file()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out | ios::app);

    for (vector<int>::iterator it = this->vVictory.begin(); it != this->vVictory.end();it++)
    {
        ofs << *it << ","
            << this->map_Spkr[*it].m_score[1] << ",";
    }
    ofs << endl;

    ofs.close();
    cout << "----------------------------" << endl;
    cout << "�ļ�����ɹ���" << endl;
    system("pause");
    system("cls");
    this->show_menu();
    this->isFileEmpty = false;
}

void ASys::load_file()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    
    if(!ifs.is_open())
    {
        cout << "--------------------------" << endl;
        cout << "�ļ������ڣ���ʼ���ļ��С���" << endl;
        this->isFileEmpty = true;
        system("pause");
        system("cls");
        return;
    }

    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        cout << "--------------------------" << endl;
        cout << "��ǰ�ļ�Ϊ�գ�" << endl;
        this->isFileEmpty = true;
        system("pause");
        system("cls");
        return;
    }

    //�ļ������ҷǿգ���ʼ¼������
    this->isFileEmpty = false;
    ifs.putback(ch);

    int index = 1;
    string tmp;

    vector<string> v;
    while (ifs >> tmp)          //��������ʱ��string¼��\nʱֹͣ��������һ��
    {
        


        v.clear();
        int start = 0;
        int pos;
        while(1)
        {
            pos = tmp.find(",", start);
            if (pos == -1)
            {
                break;
            }
            else
            {
                string vp = tmp.substr(start, pos-start);
                v.push_back(vp);
                start = pos + 1;
            }
        }

        this->m_Record.insert(make_pair(index, v));
        index++;
    }

    ifs.close();
}

void ASys::show_Record()
{
    if(this->isFileEmpty)
    {
        cout << "�ļ�Ϊ�գ�" << endl;
        return;
    }

    for (map<int, vector<string>>::iterator it = this->m_Record.begin(); it != this->m_Record.end();it++)
    {
        cout << "��" << it->first << "�������Ϊ:" << endl;
        cout << "�ھ���������"
             << "��ţ�" << it->second[0] << "   "
             << "������" << it->second[1] << endl;
        cout << "�Ǿ���������"
             << "��ţ�" << it->second[2] << "   "
             << "������" << it->second[3] << endl;             
        cout << "������������"
             << "��ţ�" << it->second[4] << "   "
             << "������" << it->second[5] << endl;
        cout << "----------------------------" << endl;
    }

    system("pause");
    system("cls");
}

void ASys::clr_Record()
{
    cout << "������ݣ���y/n��" << endl;
    while(1)
    {
        char ch;
        cin >> ch;
        fflush(stdin);
        if (ch == 'y'||ch=='Y')
        {
                ofstream ofs;
                ofs.open(FILENAME, ios::trunc);
                ofs.close();

                this->initSpeech();

                this->create_Spkr();

                this->load_file();

                cout << "��ճɹ���" << endl;
                break;
        }
        else if(ch=='n'||ch=='N')
        {
            cout << "����ȡ�����������˵�" << endl;
            break;
        }
        else
        {
            cout << "����������������룺" << endl;
        }
    }
    system("pause");
    system("cls");
}

ASys::~ASys()
{

}