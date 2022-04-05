#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<cstring>

using namespace std;

class CA
{
public:
    CA();
    virtual ~CA();
private:
    int m_iTime;
public:
    int GetTime();
    int SetTime(int iTime);
};


int
main()
{
    char tt[10] = "12345";
    cout << tt << endl;
    cout << sizeof(tt) << " " << strlen(tt) << endl;
    int *ptr = nullptr;
    cout << sizeof(CA) << sizeof(ptr) << endl;
    system("pause");
    return 0;
}