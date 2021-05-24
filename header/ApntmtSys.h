#pragma once
#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<fstream>
#define FILENAME "C:/Users/ASUS/Desktop/Maestera/out/speech.csv"
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

    void show_Outcome();

    void create_Spkr();

    void draw_Spch();

    void speechCommence();

    void quitSys();

    void start_speech();

    void save_file();

    ~ASys();

};

