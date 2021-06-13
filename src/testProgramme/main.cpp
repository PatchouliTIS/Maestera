// #include <stdio.h>
// #include <stdlib.h>
// #include <bits/stdc++.h>

// using namespace std;
// typedef struct RCD
// {
//     string name;
//     string date;
//     string time;
//     string cost;

// } RCD;

// RCD cls[10005];

// void print(RCD *p,int num)
// {
//     for (int i = 0; i < num; i++)
//     {
//         printf("%s %s %s%15s\n", p[i].name, p[i].date, p[i].time, p[i].cost);
//         // cout << p[i].name << ' ' << p[i].date << ' ' << p[i].time << setw(15) << p[i].cost
//         //      << endl;
//     }
// }

// bool cmp(int a,int b)
// {
// 	if(a%2==b%2)
// 	{
// 		if(a%2==1)
// 			return a>b;
// 		else if(a%2==0)
// 			return a<b;
// 	}
// 	else
// 		return a%2>b%2;
// }

// int a[10]={0};




// int main()
// {
// 	while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9])
// 	{
// 		sort(a,a+10,cmp);
// 		for(int i=0;i<9;i++)
// 		{
// 			cout<<a[i]<<" ";
// 		}
// 		cout<<a[9]<<endl;
// 	}
//     system("pause");
//     return 0;
// }
    // while (scanf("%s %s %s %s", &cls[i].name, &cls[i].date, &cls[i].time, &cls[i].cost) != EOF)
    // while(cin>>cls[i].name>>cls[i].date>>cls[i].time>>cls[i].cost)
    // {
    //     i++;
    // }

    // printf("%s %s %s%15s\n", cls[0].name, cls[0].date, cls[0].time, cls[0].cost);
    // printf("%d,%d,%d,%d\n",i++,--i,++i,++i);
    // i = 9;
    // printf("%d\n", i++);
    // printf("%d\n", --i);
    // printf("%d\n", i++);


#include<bits/stdc++.h>

using namespace std;

typedef struct Tee
{
    string name;
    int score;
}Tee;

int addTees(int a[],int num)
{
    int sum=0;
    for(int i=0;i<num;i++){
        sum+=a[i];
    }
    return sum;
}

bool cmp(Tee a,Tee b)
{
    if(a.score==b.score)
        return a.name<b.name;
    else return a.score>b.score;
}

map<string,int> mTemp;
map<string,int> mPos;

vector<vector<Tee>> L;
vector<Tee> TL;

int main()
{
    int teeCnt=0;
    int position;
    cin>>position;
    int *lcl=new int[position];         //每场考试的人数
    for(int i=0;i<position;i++)
    {
        cin>>lcl[i];
        vector<Tee> tmp(lcl[i]);
        for(int j=0;j<lcl[i];j++)
        {
            cin>>tmp[j].name>>tmp[j].score;
            TL.push_back(tmp[j]);
            mPos[tmp[j].name]=i+1;
        }
        L.push_back(tmp);
        sort(L[i].begin(),L[i].end(),cmp);
        for(int k=0;k<lcl[i];k++)
        {
            if(k==0) mTemp[L[i][k].name]=1;
            else {
                if(L[i][k].score==L[i][k-1].score) mTemp[L[i][k].name]=mTemp[L[i][k-1].name];
                else mTemp[L[i][k].name]=k+1;
            }
        }
    }
    int TT=addTees(lcl,position);
    int *total_rank=new int[TT];
    sort(TL.begin(),TL.end(),cmp);
    for(int i=0;i<TT;i++)
    {
        if(i==0) total_rank[i]=1;
        else{
            if(TL[i].score==TL[i-1].score) total_rank[i]=total_rank[i-1];
            else total_rank[i]=i+1;
        }
    }
    
    cout<<TT<<endl;
    for(int i=0;i<TT-1;i++)
    {
        cout<<TL[i].name<<" "<<total_rank[i]<<" "<<mPos[TL[i].name]<<" "<<mTemp[TL[i].name]<<endl;
    }
    cout<<TL[TT-1].name<<" "<<total_rank[TT-1]<<" "<<mPos[TL[TT-1].name]<<" "<<mTemp[TL[TT-1].name]<<endl;
    system("pause");
    return 0;
}