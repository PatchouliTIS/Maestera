#include<iostream>
#include "AT.hpp"
using namespace std;

int main()
{

    ArrTP<int> m1(10);            //传入最大容量

    ArrTP<int> m2(m1);

    ArrTP<int> m3(100);
    m3 = m1;

    m1.insert(4);
    m1.print();

    return 0;
}