#include "workerManager.h"

workerManager::workerManager()      //���캯����ʵ��
{
    
    //������ͨ�����ļ��ķ�ʽͳ���ļ��е����ݣ�������Ӧ�ĳ�ʼ��
    //����ϵͳ���캯�����г�ʼ���������ж��ļ��Ƿ����
    //1. �ļ�������
    //2. �ļ����ڵ�����Ϊ��
    //3. �ļ����ڣ�����������Ӳ���
    //�½�����ϵͳ�ļ�
    ifstream ifs;
    ifs.open(FNAME,ios::in);        //���뷽ʽ����ȡ�ļ�

    //�����ж��ļ��Ƿ����
    //1. �ļ�������
    if(!ifs.is_open())              //��ȡ�ļ�
    {
        cout<<"�ļ������ڣ���ʼ���ļ���"<<endl;
        this->emp_num=0;
        this->ptr=NULL;
        this->m_isFileEmpty=true;   //�ļ�������Ϊ��

        ifs.close();

        return;                     //��Ϊ�ļ������ڣ���ʱֻ���г�ʼ����������������������

    }



    //2.�ļ����ڵ�����Ϊ��
    char ch;
    ifs >> ch;        //�Ƚ���һ���ļ���ȡ�����ļ�Ϊ�����ڶ�ȡ���ļ�֮��ifsָ��ָ���ļ��Ľ�β��־����ΪEOF
    if(ifs.eof())
    {
        cout<<"�ļ�Ϊ�գ����³�ʼ���ļ���"<<endl;
        
        
        this->emp_num=0;
        this->ptr=NULL;
        this->m_isFileEmpty=true;   //�ļ�������Ϊ��

        ifs.close();

        return;
    }

    //3.
    int num = this->get_empNum();
    cout << "ְ������Ϊ��" << num << endl;
    this->emp_num = num;            //ͨ����ȡĿ���ļ���¼������ʼ��ְ������

    this->ptr = new Worker *[this->emp_num];//���ٿռ�
    this->init_EmpArr();            //ͨ����ȡ�ļ���ʼ��������ά����ְ����ָ������
    
    this->sortByID(2);              //Ĭ�Ͻ���ID��������
    this->m_isFileEmpty = false;
}
//����+������ʵ�ֳ�Ա����Ҫ��this�������ָ��


void workerManager::Show_menu()
{
    cout<<"**********************************"<<endl;
    cout<<"******��ӭʹ��ְ������ϵͳ********"<<endl;
    cout<<"**********0.�˳��������**********"<<endl;
    cout<<"**********1.����ְ����Ϣ**********"<<endl;
    cout<<"**********2.��ʾְ����Ϣ**********"<<endl;
    cout<<"**********3.ɾ����ְ��Ա**********"<<endl;
    cout<<"**********4.�޸�ְ����Ϣ**********"<<endl;
    cout<<"**********5.����ְ����Ϣ**********"<<endl;
    cout<<"**********6.���ձ������**********"<<endl;
    cout<<"**********7.��������ĵ�**********"<<endl;
    cout<<"**********************************"<<endl;
    cout<<endl;
}

void workerManager::Add_Emp()
{
    cout<<"���������ְ������"<<endl;   //�������
    int addsz=0;
    cin>>addsz;
    while(1)
    {   
        if(addsz>0)
        {
            //���ְ������
            int newsz=this->emp_num+addsz;  //ÿ�ε������Ա���Ա������Ҫ��thisָ��
            //�����¿ռ�
            Worker **newptr=new Worker*[newsz]; //�洢Worker���ָ������飬ʹ��ָ��������������ʵ���麯���ڶ�̬�̳��ϵĹ���
            
            
            if(newptr==NULL)
            {
                cout<<"�����ռ����������ʧ��"<<endl;
                exit(0);
            }
            //���������ݣ���Ϊ��˳����Ƽ�ʹ������洢��
            if(this->ptr!=NULL)
            {
                for(int i=0;i<emp_num;i++)
                {
                    newptr[i]=this->ptr[i];
                }

            }

            //�������������
            for(int i=0;i<addsz;i++)
            {
                int id;
                string name;
                int Dselect;


                //��������
                cout<<"�������"<<i+1<<"����ְ���ı�ţ�"<<endl;
                while (cin >> id)
                {
                    if(this->disc.count(id))
                    {
                        cout << "�Ѵ��ڸñ�ţ����������룺" << endl;
                    }
                    else
                        break;
                }
                cout<<"�������"<<i+1<<"����ְ����������"<<endl;
                cin>>name;

                cout<<"�������"<<i+1<<"����ְ���ĸ�λ��"<<endl;
                cout<<"1����ְͨ��"<<endl
                    <<"2�����ž���"<<endl
                    <<"3���ϰ�"<<endl;
                cin>>Dselect;

                Worker* tmp=NULL;
                //������Ա����Ϣ
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
                //����Ա�����ָ�����ָ������
                newptr[this->emp_num+i]=tmp;
                this->disc[id] = this->emp_num + i;

            }//������ӽ���
            

            //�ͷ�ԭ���ռ�
            delete [] this->ptr;
            //��ԭָ������ָ���¿ռ�
            this->ptr=newptr;
            //����ְ������
            this->emp_num=newsz;
            
            

            //�ɹ���Ӻ�ͨ���ļ����������ļ�
            this->save();

            //�����ļ��Ƿ�Ϊ�յı�־
            this->m_isFileEmpty = false;

            //��ʾ��ӳɹ�
            cout<<"�ɹ����"<<addsz<<"����ְ��"<<endl;
            break;
        }
        else if(addsz==-1){
            cout<<"���������ϼ��˵�"<<endl;
            break;
        }

        else{
            cout<<"������������,����������"<<endl;
        }
    }
    system("pause");
    system("cls");
}


void workerManager::exitSystem()
{
    this->save();
    cout<<"��ӭ�´�ʹ��"<<endl;
    exit(0);
}

void workerManager::save()
{
    ofstream ofs;
    ofs.open(FNAME,ios::out);   //��д(out ���)�ķ�ʽ���ļ�

    for(int i=0;i<this->emp_num;i++)
    {
        ofs<<this->ptr[i]->m_id<<" "
            <<this->ptr[i]->m_name<<" "
            <<this->ptr[i]->m_Did<<endl;
    }

    ofs.close();


}

int workerManager::get_empNum()     //ͨ����ȡ�ļ��ķ�ʽ���ְ������
{
    ifstream ifs;
    ifs.open(FNAME, ios::in);

    int id;
    string name;
    int Did;

    int num = 0;

    while(ifs>>id&&ifs>>name&&ifs>>Did)
    {
        //��¼����
        num++;
    }

    ifs.close();

    return num;
}

int workerManager::isEmpExist(int num)  //����һ��ְ����ָ�����飬�鿴�Ƿ����������
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

    int index = 0;                  //ְ����ָ�������±�
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
    if(this->m_isFileEmpty)         //�ļ���¼Ϊ��
    {
        cout << "�ļ�Ϊ�գ�" << endl;
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
        cout << "�ļ�Ϊ�գ�" << endl;
    }
    else{
        cout << "��������ְԱ����Ա�����" << endl;
        int num;
        cin >> num;
        int index = this->isEmpExist(num);
        if(index==-1)
        {
            cout << "��ְ�������ڣ�" << endl;
        }
        else{
            for (int i = index; i < this->emp_num - 1;i++)
            {
                this->ptr[i] = this->ptr[i + 1];
            }
            delete this->ptr[this->emp_num];
            this->ptr[this->emp_num] = NULL;

            --this->emp_num;

            this->save();               //�����ļ�
        }
    }
    system("pause");
    system("cls");
}

void workerManager::mod_Emp()
{
    if(this->m_isFileEmpty)
    {
        cout << "�ļ�Ϊ�գ�" << endl;
    }
    else
    {
        cout << "������Ա�����" << endl;
        int num;
        cin >> num;
        int index = this->isEmpExist(num);
        if(index!=-1)
        {
            delete this->ptr[index];

            int newID;
            string newName;
            int newDiv;

            cout << "���ҵ����Ϊ" << num << "��Ա�����������µ�Ա����ţ�" << endl;
            cin >> newID;

            cout << "�������µ�Ա��������" << endl;
            cin >> newName;

            cout << "���������ڲ��ţ�" << endl
                 << "1.��ͨԱ��" << endl
                 << "2.���ž���" << endl
                 << "3.�ϰ�" << endl;
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
            cout << "�޸�ʧ�ܣ����޴���" << endl;
        }
    }
    system("pause");
    system("cls");
}

void workerManager::search_Emp()    //���ַ�������ְ��
{
    if(this->m_isFileEmpty)
    {
        cout << "�ļ�Ϊ�գ�" << endl;
    }
    else {
        cout << "��ȷ�����ҷ�ʽ��" << endl
             << "1.��������" << endl
             << "2.��Ų���" << endl;
        int mk;
        int cnt = 0;
        cin >> mk;
        while(1)
        {    
            if(mk==1)
            {
                cout << "������������" << endl;
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
                    cout << "�����ҵ�" << cnt << "����¼" << endl;
                }
                break;
            }
            else if(mk==2)
            {
                cout << "�������ţ�" << endl;
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
                    cout << "�����ҵ�" << cnt << "����¼" << endl;
                }
                break;
            }
            else
            {
                cout << "�����������������룺" << endl;
            }
        }
    }
    system("pause");
    system("cls");
}                       

void workerManager::sortByName(int flag)
{
    if(flag==1)                     //����
    {
        for (int i = 0; i < this->emp_num ; i++)
        {
            int index = i;
            for (int j = i+1; j < this->emp_num;j++)
            {
                if (this->ptr[index]->m_name > this->ptr[j]->m_name)     //��ĸ����
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
                if (this->ptr[index]->m_name < this->ptr[j]->m_name)     //��ĸ������
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
                if (this->ptr[index]->m_id < this->ptr[j]->m_id)     //��ĸ����
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
                if (this->ptr[index]->m_id > this->ptr[j]->m_id)     //��ĸ������
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
        cout << "�ļ�Ϊ�գ�" << endl;
    }
    else
    {
        cout << "����������ʽ��" << endl
             << "1.��������" << endl
             << "2.�������" << endl;
        int mk;
        while(cin>>mk)
        {
            if(mk!=1&&mk!=2)
            {
                cout << "�����������������룺" << endl;
            }
            else
                break;
        }


        cout << "�����룺" << endl
             << "1.����" << endl
             << "2.����" << endl;
        int fl;
        while(cin>>fl)
        {
            if(fl!=1&&fl!=2)
            {
                cout << "�����������������룺" << endl;
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
            cout << "������ɣ�" << endl;
        }
    }
    system("pause");
    system("cls");
}

void workerManager::fileClear()
{
    ofstream ofs;
    ofs.open(FNAME, ios::trunc);
    ofs.close();                    //�ļ����

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

    cout << "�ļ�����գ�" << endl;
    system("pause");
    system("cls");
}

workerManager::~workerManager()     //����������ʵ��
{
    if(this->ptr!=NULL)
    {
        delete [] this->ptr;
        this->ptr=NULL;
    }
    //�ֶ��ͷŶ�������


}