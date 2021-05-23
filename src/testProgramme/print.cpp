#pragma once
#include<iostream>
using namespace std;

void print(int *a, int len)
{
    for (int i = 0; i < len;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
