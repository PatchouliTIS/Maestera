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
while(ifs>>buf){
    cout<<buf<<endl;
}  //读取数据方法1；
//2.
while(ifs.getline(buf,sizeof(buf))){
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
    cout<<c<<endl;
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
