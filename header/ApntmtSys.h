#pragma once
#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include "Speaker.h"

using namespace std;

class ASys
{
public:
    vector<int> v_r1;           //��һ�ֱ���ѡ�ֵı��

    vector<int> v_r2;            //�ڶ��ֱ���ѡ�ֵı��

    vector<int> vVictory;        //ʤ���ߵı��
    //ͨ��vector��push_back()����ʵ�����

    map<int, Speaker> map_Spkr;  //��ź�ѡ�����ӳ���ϵ

    int m_Round;                //��ǰ�����ִ�



    

    ASys();

    void initSpeech();

    void show_menu();

    void create_Spkr();

    void start_Spch();

    void quitSys();

    ~ASys();

};

