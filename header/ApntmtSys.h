#pragma once
#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<fstream>
#include<stdlib.h>
#define FILENAME "C:/Users/ASUS/Desktop/Maestera/out/speech.csv"
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

    bool isFileEmpty;           //文件是否为空

    map<int, vector<string>> m_Record; //记录文件数据

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

    void load_file();

    void show_Record();

    void clr_Record();

    ~ASys();

};

