

#include <iostream>

using namespace std;

// class D
// {
// public:
//     D(){cout<<"D()"<<endl;}
//     ~D(){cout<<"~D()"<<endl;}
// protected:
//     int d;
// };

// class B:virtual public D
// {
// public:
//     B(){cout<<"B()"<<endl;}
//     ~B(){cout<<"~B()"<<endl;}
// protected:
//     int b;
// };

// class A:virtual public D
// {
// public:
//     A(){cout<<"A()"<<endl;}
//     ~A(){cout<<"~A()"<<endl;}
// protected:
//     int a;
// };

// class C:public B, public A
// {
// public:
//     C(){cout<<"C()"<<endl;}
//     ~C(){cout<<"~C()"<<endl;}
// protected:
//     int c;
// };

// class Base
// {
// public:
//     Base() { cout << "Base_ctor" << endl; }
//     ~Base() { cout << "Base_dtor" << endl; }
// };

// class

// typedef struct{
//     int ans;
//     char *c;
//     double b;

// } SRU;

class CA
{
public:
virtual void f1()
{
    cout << "CA::f1" << endl;
    f2();
}
virtual void f2()
{
cout << "CA::f2" << endl;
}
};


class CB: public CA
{
public:
void f1()
{
cout << "CB::f1" << endl;
f2();
}
void f2()
{
cout << "CB::f2" << endl;
}
};

class CC:public CB
{
public:
    void f2()
    {
        cout << "CC:f2" << endl;
    }
};

struct 
{
    char a;
    int b;
    char c;
} tru;

struct
{
    int a : 1;
    int b : 2;
    int c : 5;
} asu;

#define N 2008



int main()
{
    double r = 1234.1254125;
    int a, b, c;
    int arr[N];
    // printf("%6.5e\n%.5e\n%6e\n%.6e", r, r, r, r);
    // scanf("%d%*d%d", &a, &b, &c);
    printf("%d,  %d", sizeof(tru), sizeof(asu));
    system("pause");

    return 0;
}