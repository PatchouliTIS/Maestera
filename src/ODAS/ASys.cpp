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

void ASys::draw_Spch()
{
    cout << "-------------------------------------" << endl;
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
    system("cls");
    this->show_menu();
}

void ASys::quitSys()
{
    cout << "欢迎下次使用！" << endl;
    system("pause");
    exit(0);
}

void ASys::speechCommence()
{
    cout << "-----------------------------------------" << endl;
    cout << "第" << this->m_Round << "轮比赛正式开始！" << endl;
    multimap<double, int, greater<double>> scr_Index;             //重复元素map用来存储每次比赛的人员得分

    int cnt = 0;
    vector<int> tmp;         //存储得分，在打分之后还要在分数上操作
    if (this->m_Round == 1)
    {
        tmp = this->v_r1;
    }
    else
    {    
        tmp = this->v_r2;
    }

    
    //遍历所有参赛选手
    for (vector<int>::iterator it = tmp.begin(); it != tmp.end();it++)
    {
        cnt++;      //统计人数
        //十个评委打分
        deque<double> scrTp;
        for (int i = 0; i < 10;i++)
        {    
            double score = (rand() % 401 + 600) / (double)10;
            scrTp.push_back(score);
        }
        
    
        //对分数进行排序，去掉最高分和最低分并且计算分数
        sort(scrTp.begin(), scrTp.end(), greater<double>());        //greater<double>() 模板函数
        scrTp.pop_back();         //去掉最高分
        scrTp.pop_front();        //去掉最低分

        double sum = accumulate(scrTp.begin(), scrTp.end(), 0.0f);
        double avg = sum / 10;

        //当前选手的平均分
        this->map_Spkr[*it].m_score[this->m_Round - 1] = avg;

        //将编号和得分装入容器scr_Index中
        scr_Index.insert(make_pair(avg, (*it)));

        if (cnt % 6 == 0)
        {
            cout << "----------------------------------" << endl;
            cout << "第" << cnt / 6 << "小组比赛结果如下：" << endl;
            cout << "----------------------------------" << endl;
            //输出结果
            int i = 1;
            for (multimap<double, int, greater<double>>::iterator it = scr_Index.begin(); it != scr_Index.end(); i++,it++)
            {
                cout << "第" << cnt/6 << "组内第" << i << "名"
                     << "   "
                     << "编号：" << it->second << "   "
                     << "姓名：" << this->map_Spkr[it->second].m_name << "   "
                     << "得分：" << this->map_Spkr[it->second].m_score[this->m_Round - 1] << endl;
            }

            int j = 0;          //取前三名
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

            scr_Index.clear();      //重置辅助map，为下一轮6人比较做准备
            
            cout << endl;
        }
    }
    cout << "----------------------------------------" << endl;
    cout << "第" << this->m_Round << "轮比赛已经结束。" << endl;
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
    
    cout << "当前为第" << this->m_Round << "轮比赛，比赛结果为：" << endl;
    
    int i = 0;
    for (vector<int>::iterator it = v.begin(); it != v.end(); i++,it++)
    {
        cout << "第" << i+1 << "名选手："
             << "   "
             << "姓名：" << this->map_Spkr[*it].m_name << "   "
             << "编号:" << *it << "   "
             << "得分：" << this->map_Spkr[*it].m_score[this->m_Round-1] << endl;
    }

    system("pause");
    system("cls");
    this->show_menu();
}

void ASys::start_speech()
{
    //第一轮比赛开始
    //抽签
    this->draw_Spch();

    //打分算分
    this->speechCommence();

    //显示结果
    this->show_Outcome();

    //第二轮开始
    (this->m_Round)++;

    //抽签
    this->draw_Spch();

    //打分算分
    this->speechCommence();

    //显示结果
    this->show_Outcome();


    //保存胜利者结果
    this->save_file();

    //重置管理类容器内容，使其可以进行下一次比赛
    this->initSpeech();

    this->create_Spkr();

    this->load_file();

    

    cout << "*****************" << endl;
    cout << "本届比赛成功举行！" << endl;


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
    cout << "文件保存成功！" << endl;
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
        cout << "文件不存在，初始化文件中……" << endl;
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
        cout << "当前文件为空！" << endl;
        this->isFileEmpty = true;
        system("pause");
        system("cls");
        return;
    }

    //文件存在且非空，开始录入数据
    this->isFileEmpty = false;
    ifs.putback(ch);

    int index = 1;
    string tmp;

    vector<string> v;
    while (ifs >> tmp)          //读入数据时，string录到\n时停止，跳到下一行
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
        cout << "文件为空！" << endl;
        return;
    }

    for (map<int, vector<string>>::iterator it = this->m_Record.begin(); it != this->m_Record.end();it++)
    {
        cout << "第" << it->first << "届获奖名单为:" << endl;
        cout << "冠军————"
             << "编号：" << it->second[0] << "   "
             << "分数：" << it->second[1] << endl;
        cout << "亚军————"
             << "编号：" << it->second[2] << "   "
             << "分数：" << it->second[3] << endl;             
        cout << "季军————"
             << "编号：" << it->second[4] << "   "
             << "分数：" << it->second[5] << endl;
        cout << "----------------------------" << endl;
    }

    system("pause");
    system("cls");
}

void ASys::clr_Record()
{
    cout << "清空数据？（y/n）" << endl;
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

                cout << "清空成功！" << endl;
                break;
        }
        else if(ch=='n'||ch=='N')
        {
            cout << "操作取消，返回主菜单" << endl;
            break;
        }
        else
        {
            cout << "输入错误！请重新输入：" << endl;
        }
    }
    system("pause");
    system("cls");
}

ASys::~ASys()
{

}