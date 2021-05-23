#pragma once
#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include "Speaker.h"

using namespace std;

class ASys
{
public:
    vector<int> v_r1;           //第一轮比赛选手的编号

    vector<int> v_r2;            //第二轮比赛选手的编号

    vector<int> vVictory;        //胜利者的编号
    //通过vector的push_back()函数实现添加

    map<int, Speaker> map_Spkr;  //编号和选手类的映射关系

    int m_Round;                //当前比赛轮次



    

    ASys();

    void initSpeech();

    void show_menu();

    void create_Spkr();

    void start_Spch();

    void quitSys();

    ~ASys();

};

