# 3. 运算符使用

## 3.1 圆括号运算符

C++中对于圆括号新增加了一种运算：
```c++
int a=10;
double b=int(a);
```
`valueType(value)`被称为**类型构造符**，也就是构造一个valueType类型的(value)值。

# 5. 文件操作
**临时数据持久化：文件操作**

头文件：< fstream >

文件操作三大类：
1. ofstream 写操作
2. ifstream 读操作
3. fstream  读写


## 5.1 文本文件
### 5.1.1 写文件

写文件步骤：
``` c++
#include<fstream>   //包含文件操作头文件

ofstream ofs;       //创建文件流对象,fstream也可以

ofs.open("filePath",打开方式);             //打开文件，也可以在构造文件流对象时直接调用构造函数ofs("filePath",打开方式)

ofs<<"写入的数据";  //写入数据

ofs.close();        //关闭文件
```

打开方式分类：
|打开方式代码|解释|
|:--:|:--:|:--:|
|ios::in|读文件|
|ios::out|写文件|
|ios::app|在文件尾部续写文件|
|ios::trunc|若文件存在，删除并重新建立空文件|
|ios::ate|打开在文件尾部|
|ios::binar|以二进制方式打开文件|


### 5.1.2 读文件

读文件步骤:
``` c++
#include<fstream>   //包含文件操作头文件

ifstream ifs;       //创建文件流对象,fstream也可以


ifs.open("filePath",打开方式);
if(!ifs.is_open()){
    cout<<"打开失败";
    return 0;
}             //判断是否打开文件成功


//1.
char buf[1024]={0};
while(ifs>>buf){        //读完一行遇到换行符/n则中断输入，转为下一行
    cout<<buf<<endl;
}  //读取数据方法1；
//2.
while(ifs.getline(buf,sizeof(buf))){    //ifs的成员函数ifs.getline(const char*,const _INT max_size)
    cout<<buf<<endl; 
}   //读取数据方法2；
//3.string类读入
string buf;
while(getline(ifs,buf)){
    cout<<buf<<endl;
}
//4.单字符读入
char c;
while((c=ifs.get())!=EOF){
    cout<<c;
}




ifs.close();        //关闭文件
```


## 5.2 二进制文件
### 5.2.1 写文件

``` c++
#include<fstream>


ofstream ofs("filePath",ios::out|ios::binary);      //写文件，直接调用构造函数

Person P;
P->name=....             //创建临时的变量用来改写文件内的人物类数据


//ofs.write(const char*这里是地址,int len这里是目标长度)
ofs.write((const char*)&P,sizeof(Person));



ofs.close();
```


### 5.2.2 读文件

读文件步骤:
``` c++
#include<fstream>   //包含文件操作头文件

ifstream ifs;       //创建文件流对象,fstream也可以


ifs.open(filePath,ios::ifs|ios::binary)
{
    if(!ifs.is_open()){
        cout<<"打开失败";
        return 0;
    }             //判断是否打开文件成功

    Person P;       //将要读取的目标数据类型

    ifs.read((char*)&P,sizeof(Person));

    cout<<P.m_name.....<<endl;





    ifs.close();        //关闭文件
}
```

# 6. 模板
template\<typename T>   其中typename可以用class代替，变量名T可变化，但必须大写。

<>中的数据为**模板参数列表**

模板类定义后**紧跟函数或者类的定义**并且**模板必须确定T的数据类型才能正常编译使用**

- typename指的是函数模板，而class是类模板，后者适用范围更广一些

## 6.1 基本语法
``` c++
template<class T,class B,...>           //声明函数模板，使得变量T代表一个模板类
void mySwap(T &a,T &b)
{
    T tmp=a;
    a=b;
    b=tmp;
}                           //这样就能用一个函数应对不同的数据类型


int main()
{
    //1. 直接传参：自动类型推导
    //细节:传入的参数类型必须一致；无法隐式类型转换
    int a,b;
    mySwap(a,b);//正确！
    int c;char d;
    mySwap(c,d);//错误！
    //2. 显式指示数据类型：当模板函数中没有使用模板T时，直接声明其模板T数据类型为int
    //细节：可以进行自动类型转换，跟普通函数一样
    mySwap<int>(a,b);
    return 0;
}
```
## 6.2 函数模板
模板定义后紧跟函数定义
```c++
template<typename T,...>
void mySwap(T a)
{
    ...
}
```

### 6.2.1 普通函数与函数模板的调用规则

调用规则如下：

1. 普通函数优先级更高

2. 通过空模板参数列强制调用函数模板

    空模板函数列：`mySwap<>(a,b)`，即可强制调用函数模板

3. 函数模板可以重载

    不同参数类型

    不同参数个数 

4. 若传入参数在函数模板中拥有更高的匹配度，则优先调用函数模板

```c++
void mySwap(int &a,int &b)      //普通函数
{
    int tmp=a;
    a=b;
    b=tmp;
}

template<class T>
void mySwap(T &a,T &b)
{
    T tmp=a;
    a=b;
    b=tmp;
}

int main()
{
    char a,b;
    mySwap(a,b);        //此时优先调用函数模板，因为普通函数中参数类型为int，需要进行函数类型转换，匹配度较低
    return 0;
}
```

5. 函数模板的局限性
    使用自定义模板函数实现复杂参数的函数:

    类Person无法进行“==”的运算，可以**重载运算符**或者直接**自定义函数模板**

    `template<> void isEqual(Person a,Person b)`
    
## 6.3 类模板
```c++
template<class T,...>
class Person
{
    ...
    this->T=...;
    ...
}
```

模板在类中做**类的成员**

### 6.3.1 类模板与函数模板的区别

1. 类模板无法进行自动类型转换
   
   调用类模板时只能通过**显式方式**指明数据类型：
```c++
#include<iostream>
#include<string>
using namespace std;
template<class NameT,class AgeT>
class Person
{

public:
    Person(NameT name,AgeT age)
    {
        this->p_name=name;
        this->p_age=age;
    }

    void showInfo()
    {
        cout<<this->balabala
    }

private:
    NameT p_name;
    AgeT p_age;
}


int main()
{
    Person<string,int> P("田所浩二",24);
    //调用类模板时必须显式指明数据类型
    return 0;
}
```

2. 类模板在**模板参数列表**中可以有**默认参数**

    即在类模板定义时指明默认参数
    
    `template<class NameT=string,class AgeT=int>`

    **仅限类模板**

### 6.3.2 类模板中成员函数的创建时机

区别：

   1. 普通类成员函数在编译时就创建，即一开始就创建
   2. 类模板成员函数只有在调用时才创建

**类比类继承中的虚函数**


```c++
class Person1
{
    void show1()
    {
        cout<<"P1 Init"<<endl;
    }
}

class Person2
{
    void show2()
    {
        cout<<"P2 Init"<<endl;
    }
}

template<class T>
class Myclass
{
    T obj;
    void func1()
    {
        obj.show1();
    }
    void func2()
    {
        obj.show2();
    }
    //func1和func2只有调用时才创建，此时编译是可以通过的
}

int main()
{
    Myclass<Person1> M1;
    M1.fun1();
    M1.fun2();  //此时编译无法通过，因为调用时创建成员函数。
    return 0;
}
```


### 6.3.3 类模板对象做函数参数

1. 函数定义时**直接指定传入的类模板类型**
   
    ```c++
    void printPerson(Person<string,int>&p)
    {
        p.showInfo();
        cout<<"T1的类型名为："<<typeid(T1).name()<<endl;
        //显示类型名，返回值为string
    }
    ```

    **这也是最常用的方法**

2. 函数参数模板化
    ```c++
    template<class T1,class T2>
    void printPerson(Person<T1,T2>&p)
    {
        p.showInfo();
        cout<<"T1的类型名为："<<typeid(T1).name()<<endl;
        //显示类型名，返回值为string
    }
    ```

3. **整个类**也模板化
    ```c++
    template<class T1>
    void printPerson(T1 &p)
    {
        p.showInfo();
        cout<<"T1的类型名为："<<typeid(T1).name()<<endl;
        //显示类型名，返回值为string
    }
    ```



### 6.3.4 类模板的继承
类模板继承的细节：

父类是类模板时，子类**必须显式声明数据类型**
    
    
```c++
    //A.继承时显式声明数据类型
    class Son:public Person<string,int>
    {
        ...
    };
    //B.子类也作为类模板，灵活指定父类或者子类自身的数据类型
    template<class T1,class T2,class T3>
    class Father:public Person<T1,T2>
    {
        ...
        T3 obj;
        ...
    };
```

### 6.3.5 类模板的成员函数类外实现
```c++
//模板声明
//函数返回值(构造、析构函数没有返回值)类名<模板参数列表>::类内成员函数
//...

template<class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age)
{
    ...
}
```

### 6.3.6 类模板成员函数份文件编写

**主要问题**：
- 类模板中成员函数创建时机是在**调用**阶段（非编译时创建），因此分文件（比如声明在.h而实现在.cpp，而项目唯一入口main.cpp中只包含了.h文件）时**一旦调用成员函数**会链接不到，编译出错。

**解决办法**：
- 直接写在.cpp文件下；
- 声明（头文件.h）与实现（源文件.cpp）写在同一文件(.hpp)下。然后`#include<person.hpp>`



### 6.3.7 类模板与友元函数
全局函数做类模板的友元函数时，可以类外实现，也可以类内实现

```c++
template<class T1,class T2>
class Person
{
    //友元函数printInfo()
    friend void printInfo(Person<T1,T2>&P)
    //1. 友元函数内部实现
    {
        cout<<...<<endl;
        //注意：此处不能直接调用类模板的成员函数showInfo(),因为类模板成员函数编译时未创建，而全局函数编译时就已经创建，直接调用为空，会出现编译错误。
    }
    
public:
    Person(T1 name,T2 age)
    {
        this->m_name=name;
        this->m_age=age;
    }
    

    void showInfo()
    {
        cout<<...<<endl;
    }
private:
    T1 m_name;
    T2 m_age;
};//类模板定义

//2. 友元函数外部实现
template<class T1,class T2>
void printInfo<>(Person<T1,T2> &P)
{
    cout<<...<<endl;
}
//类中的声明函数为普通函数，而外部实现时因为参数有模板，则判定printInfo()为函数模板，此时需要加上空模板参数列表<>来避免编译错误。



template<class T1,class T2>
class Person;       //先声明类模板


template<class T1,class T2>
void printInfo(Person<T1,T2> &P)
{
    cout<<...<<endl;
}               //提前声明实现全局函数


//或者提前声明定义，在类的定义前先声明实现全局函数showInfo()，此时就不需要额外加上空参数列表<>



```


# 7. STL标准库的使用
`#include<bits/stdc++.h>`
## 7.1. vector容器
`#include<vector>`

vector容器和**数组**非常相似，被称为**单端数组**；

普通数组是**静态存储**，而vector可以**动态扩展**；（类比堆区、栈区存储）

**动态扩展**：
- 是指不直接在原有空间后开辟新空间，而是直接额外开辟一整块区域，复制原有数据（类似深拷贝）
- vector容器迭代器iterator支持**随机访问**（it+3;it+4;等操作跳跃访问）

原理上是属于**模板类**，类名是vector

### 7.1.1 迭代器的使用
vector的迭代器可以随机访问
```c++
//使用迭代器遍历vector容器
vector<int> v;
vector<int>::iterator itBegin = v.begin();      //*.begin()指向容器中第一个元素
vector<int>::iterator itEnd = v.end();          //*.end()指向容器最后一个元素的后一个位置

for(;itBegin!=itEnd;itBegin++)
{
    cout<<*itBegin<<" ";                        //迭代器本质为指针，取得其指向的数据需要解引用
}
```

### 7.1.2 构造函数
- vector\<T> v
  
  类模板初始化容器

- vector<...> v(int n,elem)

    n个val初始化容器，当elem缺失时自动赋值0

- vector<...> v(vc.begin(),vc.end())
  
  区间访问方式构造容器，左边闭区间右边开区间        [begin,end)

- vector<...> v(const vector<...>& vc)
  
  拷贝构造函数



### 7.1.3 vector赋值函数
两种方法：
1. 重载运算符=
   - vector& operator=(const vector& v)
2. 成员函数assign()
   - vector& assign(vc.begin(),vc.end())
    区间[beg,end)赋值
   - vector& assign(int n,ElemType val)
    n个val值



### 7.1.4 vector容量和大小操作
1. 返回容量空间：
  - capacity()

2. 返回大小空间：
  - size()

3. 重置容器大小：
  - vector& resize(int n,int val)
    容器vc大小重置为n，若变长则用新的val填充增加的长度；若变短则直接删除末尾的元素

    **不改变容量，只改变大小size**

### 7.1.5 vector插入删除操作
1. 尾部操作
   - push_back();
    
    尾插法
   
   - pop_back();

    尾删法

2. 一般操作
   - insert(const_iterator pos,elem)

    在迭代器指向的pos位置插入元素elem

   - insert(const_iterator pos,int cnt,elem)

    ->pos   插入cnt个元素elem

   - erase(const_iterator pos)

    删除->pos处的元素

   - erase(const_iterator begin,const_iterator end)

    删除->beg到->end闭开区间的元素

### 7.1.6 vector互换操作
- vector& swap(const vector& vc)
  
  v.swap(v1)

  将v和v1的元素、大小、容量等信息全部互换的操作

**用途：容器占用容量空间的收缩**

```c++
#include<iostream>
#include<vector>
using namespace std;

vector<int> v(10000);       //此时v.capacity()由系统分配且一定>=v.size()
v.resize(3);                //此时v.size()被重置，但容量capacity未被改变，占用大量闲置空间

vector<int>(v).swap(v)      //使用拷贝构造函数创建匿名对象x，之后交换容器
                            //语句执行完毕后匿名对象x即刻被系统回收，闲置空间被一起回收

```

### 7.1.7 vector预留操作
- vector& reserve(int num)
  
  预留num个连续空间，不初始化且无法访问，**减少增加元素时重新开辟堆区存储空间的次数**


## 7.2 string容器
`#include<string>`

原理上是属于**类**，类名string，类内部封装的数据是char*，一个指针

string类同时也封装了很多成员函数：
    
    .find()     .copy()     .delete()     .replace()     .insert()

不必担心数组越界，类内部自动处理

### 7.2.1 string初始化方式

|成员函数|格式|含义|
|:--:|:--:|:--:|
|string()|`string str`|初始化一个空的string类|
|string(const char* c)|`char *c;string s2(c);`|用字符指针初始化|
|string(const string& s)|`string s3;string s3(str)`|用另一个string类初始化|
|string(int n,char c)|`string s4(5,A)`|用n个字符c来初始化|


### 7.2.2 string赋值操作
两种方式：
1. 运算符重载  =
   - str=(char c);
   - str=(char* c);
   - str=(string& s);
    
    *可以用单个字符进行赋值*



2. 成员函数 assign()
   - str.assign(const char* c,int n);//////////字符数组c的**前n位**
   - str.assign(const string& S);
   - str.assign(const char*c);
   - str.assign(int n,char c);///////////n个字符c


### 7.2.3 string拼接操作
两种方式
1. 运算符重载   +=
    同赋值操作

2. 成员函数    append()
   - str.append(const string& S);
   - str.append(const string& S, int pos , int n);///////////字符串**从下标pos**开始的**后n位**字符
   - str.append(const char* c, int n)//////////字符数组c的**前n位**
   - str.append(const char* c)



### 7.2.4 string查找和替换

**查找**

两中成员函数find()和rfind()的区别

1. int find(const string& s1, int pos=0,int n) 

    str.find(s1)
   
   在str中下标pos处(默认从第一个位置开始)的**前n个字符**中查找是否存在s1字符串，若有则返回一个int型的数据，为下标index，**没找到返回-1**

2. int rfind(const string& s1, int pos=**str.length()-1**,int n)
   
   str.rfind(s1)

   在str中下标pos处(默认从后向前)的**前n个字符**中，返回str中字符串s1最后出现的位置下标index，**没找到返回-1**


**替换**
string& replace(int pos,int n,const string& S或者const char* C)

str.replace(1,3,"1111")

在str字符串中下标pos处**往后n**个字符全部替换为S或者C



### 7.2.5 string的插入和删除
1. 插入操作  insert()
   - string& insert(int pos,const string& s);
   - string& insert(int pos,const char* c);
   - string& insert(int pos,int n,char c);

    在str下标pos处插入字符串，**注意不能直接插入单个字符**
    
2. 删除操作  erase()
   - string& erase(int pos,int n=**str.length()-1**)

    从str下标为pos处开始删除**往后n个字符**


### 7.2.6 string的子串
- **string** substr(int pos,int n=**str.length()-1**) **const**
  
  从str下标为pos处往后截取n个字符，构成一个新的字符串

  **注意**：这个函数一般通过赋值操作，赋给其他的string字符串类：
  
  如同`string str1=str.substr(0,4)`






