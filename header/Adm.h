#pragma once
#include<bits/stdc++.h>
#include "ID.h"
using namespace std;

class Adm
{
public:
    Adm();

    Adm(string name,string psw);

    virtual void show_menu();

    void addID();

    void showID();

    void showPC();

    void clearRcrd();

};
