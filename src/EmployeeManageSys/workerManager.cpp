#include "workerManager.h"

workerManager::workerManager()      //构造函数空实现
{
    
    //管理类通过打开文件的方式统计文件中的数据，进行相应的初始化
    //管理系统构造函数进行初始化工作，判断文件是否存在
    //1. 文件不存在
    //2. 文件存在但数据为空
    //3. 文件存在，继续进行添加操作
    //新建管理系统文件
    ifstream ifs;
    ifs.open(FNAME,ios::in);        //输入方式，读取文件

    //加入判断文件是否存在
    //1. 文件不存在
    if(!ifs.is_open())              //读取文件
    {
        cout<<"文件不存在，初始化文件中"<<endl;
        this->emp_num=0;
        this->ptr=NULL;
        this->m_isFileEmpty=true;   //文件存在且为空

        ifs.close();

        return;                     //因为文件不存在，此时只进行初始化操作，不进行其他操作

    }



    //2.文件存在但数据为空
    char ch;
    ifs >> ch;        //先进行一次文件读取，若文件为空则在读取完文件之后，ifs指针指向文件的结尾标志，即为EOF
    if(ifs.eof())
    {
        cout<<"文件为空，重新初始化文件中"<<endl;
        
        
        this->emp_num=0;
        this->ptr=NULL;
        this->m_isFileEmpty=true;   //文件存在且为空

        ifs.close();

        return;
    }

    //3.
    int num = this->get_empNum();
    cout << "职工人数为：" << num << endl;
    this->emp_num = num;            //通过读取目标文件记录个数初始化职工人数

    this->ptr = new Worker *[this->emp_num];//开辟空间
    this->init_EmpArr();            //通过读取文件初始化管理类维护的职工类指针数组
    
    this->sortByID(2);              //默认进行ID升序排序
    this->m_isFileEmpty = false;
}
//类外+派生类实现成员函数要加this（自身的指针


void workerManager::Show_menu()
{
    cout<<"**********************************"<<endl;
    cout<<"******欢迎使用职工管理系统********"<<endl;
    cout<<"**********0.退出管理程序**********"<<endl;
    cout<<"**********1.增加职工信息**********"<<endl;
    cout<<"**********2.显示职工信息**********"<<endl;
    cout<<"**********3.删除离职人员**********"<<endl;
    cout<<"**********4.修改职工信息**********"<<endl;
    cout<<"**********5.查找职工信息**********"<<endl;
    cout<<"**********6.按照编号排序**********"<<endl;
    cout<<"**********7.清空所有文档**********"<<endl;
    cout<<"**********************************"<<endl;
    cout<<endl;
}

void workerManager::Add_Emp()
{
    cout<<"请输入添加职工数量"<<endl;   //批量添加
    int addsz=0;
    cin>>addsz;
    while(1)
    {   
        if(addsz>0)
        {
            //添加职工人数
            int newsz=this->emp_num+addsz;  //每次调用类成员或成员函数都要用this指代
            //开辟新空间
            Worker **newptr=new Worker*[newsz]; //存储Worker类的指针的数组，使用指针访问派生类可以实现虚函数在多态继承上的功能
            
            
            if(newptr==NULL)
            {
                cout<<"堆区空间已满，添加失败"<<endl;
                exit(0);
            }
            //拷贝旧数据（因为是顺序表，推荐使用链表存储）
            if(this->ptr!=NULL)
            {
                for(int i=0;i<emp_num;i++)
                {
                    newptr[i]=this->ptr[i];
                }

            }

            //批量添加新数据
            for(int i=0;i<addsz;i++)
            {
                int id;
                string name;
                int Dselect;


                //交互界面
                cout<<"请输入第"<<i+1<<"个新职工的编号："<<endl;
                while (cin >> id)
                {
                    if(this->disc.count(id))
                    {
                        cout << "已存在该编号，请重新输入：" << endl;
                    }
                    else
                        break;
                }
                cout<<"请输入第"<<i+1<<"个新职工的姓名："<<endl;
                cin>>name;

                cout<<"请输入第"<<i+1<<"个新职工的岗位："<<endl;
                cout<<"1、普通职工"<<endl
                    <<"2、部门经理"<<endl
                    <<"3、老板"<<endl;
                cin>>Dselect;

                Worker* tmp=NULL;
                //保存新员工信息
                switch(Dselect)
                {
                    case 1:
                        tmp=new Employee(id,name,Dselect);
                        break;
                    case 2:
                        tmp=new Manager(id,name,Dselect);
                        break;
                    case 3:
                        tmp=new Boss(id,name,Dselect);
                        break;
                    default:break;
                }
                //将新员工类的指针存入指针数组
                newptr[this->emp_num+i]=tmp;
                this->disc[id] = this->emp_num + i;

            }//批量添加结束
            

            //释放原来空间
            delete [] this->ptr;
            //将原指针数组指向新空间
            this->ptr=newptr;
            //更改职工人数
            this->emp_num=newsz;
            
            

            //成功添加后通过文件操作保存文件
            this->save();

            //更新文件是否为空的标志
            this->m_isFileEmpty = false;

            //提示添加成功
            cout<<"成功添加"<<addsz<<"名新职工"<<endl;
            break;
        }
        else if(addsz==-1){
            cout<<"即将返回上级菜单"<<endl;
            break;
        }

        else{
            cout<<"输入数据有误,请重新输入"<<endl;
        }
    }
    system("pause");
    system("cls");
}


void workerManager::exitSystem()
{
    this->save();
    cout<<"欢迎下次使用"<<endl;
    exit(0);
}

void workerManager::save()
{
    ofstream ofs;
    ofs.open(FNAME,ios::out);   //以写(out 输出)的方式打开文件

    for(int i=0;i<this->emp_num;i++)
    {
        ofs<<this->ptr[i]->m_id<<" "
            <<this->ptr[i]->m_name<<" "
            <<this->ptr[i]->m_Did<<endl;
    }

    ofs.close();


}

int workerManager::get_empNum()     //通过读取文件的方式获得职工人数
{
    ifstream ifs;
    ifs.open(FNAME, ios::in);

    int id;
    string name;
    int Did;

    int num = 0;

    while(ifs>>id&&ifs>>name&&ifs>>Did)
    {
        //记录人数
        num++;
    }

    ifs.close();

    return num;
}

int workerManager::isEmpExist(int num)  //遍历一次职工类指针数组，查看是否存在这个编号
{
    for (int i = 0; i < this->emp_num;i++)
    {
        if(this->ptr[i]->m_id==num)
        {
            
            return i;
            break;
        }
            
        else
            continue;
    }
    return -1;
}

void workerManager::init_EmpArr()
{
    ifstream ifs;
    ifs.open(FNAME, ios::in);

    int id;
    string name;
    int Did;

    int index = 0;                  //职工类指针数组下标
    while(ifs >> id && ifs>>name && ifs>>Did)
    {
        Worker *tmp = NULL;
        if(Did==1)
        {
            tmp = new Employee(id, name, Did);
        }
        else if(Did==2)
        {
            tmp = new Manager(id, name, Did);
        }
        else
        {
            tmp = new Boss(id, name, Did);
        }

        this->ptr[index] = tmp;
        this->disc[id] = index;
        index++;
    }

    ifs.close();
}

void workerManager::show_Emp()
{
    if(this->m_isFileEmpty)         //文件记录为空
    {
        cout << "文件为空！" << endl;
    }
    else{
        for (int i = 0; i < this->emp_num;i++)
        {
            this->ptr[i]->showInfo();
        }
    }

    system("pause");
    system("cls");
}

void workerManager::del_Emp()
{
    if(this->m_isFileEmpty)
    {
        cout << "文件为空！" << endl;
    }
    else{
        cout << "请输入离职员工的员工编号" << endl;
        int num;
        cin >> num;
        int index = this->isEmpExist(num);
        if(index==-1)
        {
            cout << "该职工不存在！" << endl;
        }
        else{
            for (int i = index; i < this->emp_num - 1;i++)
            {
                this->ptr[i] = this->ptr[i + 1];
            }
            delete this->ptr[this->emp_num];
            this->ptr[this->emp_num] = NULL;

            --this->emp_num;

            this->save();               //更新文件
        }
    }
    system("pause");
    system("cls");
}

void workerManager::mod_Emp()
{
    if(this->m_isFileEmpty)
    {
        cout << "文件为空！" << endl;
    }
    else
    {
        cout << "请输入员工编号" << endl;
        int num;
        cin >> num;
        int index = this->isEmpExist(num);
        if(index!=-1)
        {
            delete this->ptr[index];

            int newID;
            string newName;
            int newDiv;

            cout << "已找到编号为" << num << "的员工，请输入新的员工编号：" << endl;
            cin >> newID;

            cout << "请输入新的员工姓名：" << endl;
            cin >> newName;

            cout << "请输入所在部门：" << endl
                 << "1.普通员工" << endl
                 << "2.部门经理" << endl
                 << "3.老板" << endl;
            cin >> newDiv;

            Worker *tmp = NULL;
            switch(newDiv)
            {
                case 1:
                    tmp = new Employee(newID, newName, newDiv);
                    break;
                case 2:
                    tmp = new Manager(newID, newName, newDiv);
                    break;
                case 3:
                    tmp = new Boss(newID, newName, newDiv);
                    break;
                default:
                    break;
            }

            this->ptr[index] = tmp;

            this->save();
        }
        else{
            cout << "修改失败，查无此人" << endl;
        }
    }
    system("pause");
    system("cls");
}

void workerManager::search_Emp()    //两种方法查找职工
{
    if(this->m_isFileEmpty)
    {
        cout << "文件为空！" << endl;
    }
    else {
        cout << "请确定查找方式：" << endl
             << "1.姓名查找" << endl
             << "2.编号查找" << endl;
        int mk;
        int cnt = 0;
        cin >> mk;
        while(1)
        {    
            if(mk==1)
            {
                cout << "请输入姓名：" << endl;
                string tName;
                cin >> tName;

                if(this->ptr!=NULL)
                {
                    for (int i = 0; i < this->emp_num;i++)
                    {
                        if(this->ptr[i]->m_name==tName)
                        {
                            ++cnt;
                            this->ptr[i]->showInfo();
                        }
                    }
                    cout << "共查找到" << cnt << "条记录" << endl;
                }
                break;
            }
            else if(mk==2)
            {
                cout << "请输入编号：" << endl;
                int tid;
                cin >> tid;
                if(this->ptr!=NULL)
                {
                    int index = this->isEmpExist(tid);
                    if(index!=-1)
                    {
                        this->ptr[index]->showInfo();
                        ++cnt;
                    }
                    cout << "共查找到" << cnt << "条记录" << endl;
                }
                break;
            }
            else
            {
                cout << "输入有误，请重新输入：" << endl;
            }
        }
    }
    system("pause");
    system("cls");
}                       

void workerManager::sortByName(int flag)
{
    if(flag==1)                     //降序
    {
        for (int i = 0; i < this->emp_num ; i++)
        {
            int index = i;
            for (int j = i+1; j < this->emp_num;j++)
            {
                if (this->ptr[index]->m_name > this->ptr[j]->m_name)     //字母表降序
                {
                    index = j;
                }
            }
            if(index!=i)
            {
                Worker *tmp = this->ptr[index];
                this->ptr[index] = this->ptr[i];
                this->ptr[i] = tmp;
                int tp = this->disc[index];
                this->disc[index] = this->disc[i];
                this->disc[i] = tp;
            }
        }
    }
    else
    {
        for (int i = 0; i < this->emp_num ; i++)
        {
            int index = i;
            for (int j = i+1; j < this->emp_num;j++)
            {
                if (this->ptr[index]->m_name < this->ptr[j]->m_name)     //字母表升序
                {
                    index = j;
                }
            }
            if(index!=i)
            {
                Worker *tmp = this->ptr[index];
                this->ptr[index] = this->ptr[i];
                this->ptr[i] = tmp;
                int tp = this->disc[index];
                this->disc[index] = this->disc[i];
                this->disc[i] = tp;
            }
        }
    }
}

void workerManager::sortByID(int flag)
{
    if(flag==1)
    {
        for (int i = 0; i < this->emp_num ; i++)
        {
            int index = i;
            for (int j = i+1; j < this->emp_num;j++)
            {
                if (this->ptr[index]->m_id < this->ptr[j]->m_id)     //字母表降序
                {
                    index = j;
                }
            }
            if(index!=i)
            {
                Worker* tmp = this->ptr[index];
                this->ptr[index] = this->ptr[i];
                this->ptr[i] = tmp;
                int tp = this->disc[index];
                this->disc[index] = this->disc[i];
                this->disc[i] = tp;
            }
        }
    }
    else
    {
        for (int i = 0; i < this->emp_num ; i++)
        {
            int index = i;
            for (int j = i+1; j < this->emp_num;j++)
            {
                if (this->ptr[index]->m_id > this->ptr[j]->m_id)     //字母表升序
                {
                    index = j;
                }
            }
            if(index!=i)
            {
                Worker *tmp = this->ptr[index];
                this->ptr[index] = this->ptr[i];
                this->ptr[i] = tmp;
                int tp = this->disc[index];
                this->disc[index] = this->disc[i];
                this->disc[i] = tp;
            }
        }
    }
}

void workerManager::sort_Emp()
{
    if(this->m_isFileEmpty)
    {
        cout << "文件为空！" << endl;
    }
    else
    {
        cout << "请输入排序方式：" << endl
             << "1.姓名排序" << endl
             << "2.编号排序" << endl;
        int mk;
        while(cin>>mk)
        {
            if(mk!=1&&mk!=2)
            {
                cout << "输入有误，请重新输入：" << endl;
            }
            else
                break;
        }


        cout << "请输入：" << endl
             << "1.降序" << endl
             << "2.升序" << endl;
        int fl;
        while(cin>>fl)
        {
            if(fl!=1&&fl!=2)
            {
                cout << "输入有误，请重新输入：" << endl;
            }
            else
                break;
        }

        if(this->ptr!=NULL)
        {
            if(mk==1)
            {
                this->sortByName(fl);
            }
            else 
            {
                this->sortByID(fl);
            }
            cout << "排序完成！" << endl;
        }
    }
    system("pause");
    system("cls");
}

void workerManager::fileClear()
{
    ofstream ofs;
    ofs.open(FNAME, ios::trunc);
    ofs.close();                    //文件清空

    if(this->ptr!=NULL)
    {
        for (int i = 0; i < this->emp_num;i++)
        {
            if(this->ptr[i]!=NULL)
            {
                delete this->ptr[i];
            }
        }

        this->emp_num = 0;
        delete[] this->ptr;
        this->ptr = NULL;
        this->m_isFileEmpty = true;
    }

    cout << "文件已清空！" << endl;
    system("pause");
    system("cls");
}

workerManager::~workerManager()     //析构函数空实现
{
    if(this->ptr!=NULL)
    {
        delete [] this->ptr;
        this->ptr=NULL;
    }
    //手动释放堆区数据


}