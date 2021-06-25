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











class Solution {
public:
    int n;
    int min=INT_MIN;
    int mod=1000000007;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();

        int *score=new int[n*n];
        int *path=new int[n*n];

        char **bd=new char* [n];

        for(int i=0;i<n;i++)
        {
            bd[i]=new char[n];
            for(int j=0;j<n;j++)
            {
                bd[i][j]=board[i][j];
            }
        }



        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int TAR=getID(i,j);
                
                if(i==n-1&&j==n-1)
                {
                    //score[TAR]=0;
                    path[TAR]=1;
                    continue;
                }

                if(bd[i][j]=='X')
                {
                    score[TAR]=min;
                    //path[TAR]=0;
                    continue;
                }


                int val;
                if(i==0&&j==0)
                {
                    val=0;
                }
                else
                {
                    val=bd[i][j]-'0';
                }

                int s=min,p=0;

                if(i+1<n)
                {
                    int curS=score[getID(i+1,j)]+val;
                    int cnt=path[getID(i+1,j)];
                    int* res=updateANS(curS,cnt,s,p);
                    s=res[0];
                    p=res[1];
                }

                if(j+1<n)
                {
                    int curS=score[getID(i,j+1)]+val;
                    int cnt=path[getID(i,j+1)];
                    int* res=updateANS(curS,cnt,s,p);
                    s=res[0];
                    p=res[1];
                }

                if(i+1<n&&j+1<n)
                {
                    int curS=score[getID(i+1,j+1)]+val;
                    int cnt=path[getID(i+1,j+1)];
                    int* res=updateANS(curS,cnt,s,p);
                    s=res[0];
                    p=res[1];
                }


                score[TAR]=s<0?min:s;
                path[TAR]=p;
                
            }
        }

        vector<int> ans(2);

        ans[0]=score[0]==min?0:score[0];
        ans[1]=score[0]==min?0:path[0];

        return ans;

    }

    int* updateANS(int cur,int cnt,int s,int p)
    {
        int *ans=new int[2];
        ans[0]=s;
        ans[1]=p;
        if(cur==s&&cur!=min)
        {
            ans[0]=cur;
            ans[1]+=cnt;
        }
        else if(cur>s)
        {
            ans[0]=cur;
            ans[1]=cnt;
        }

        ans[1]%=mod;

        return ans;
    }

    int getID(int x,int y)
    {
        return x*n+y;
    }
};




class Solution {
private:
    unordered_map<string, map<string, int>> targets;
    
    bool backtracking(int ticketNum, vector<string>& result)
    {
        if (result.size() == ticketNum + 1)
        {
            return true;
        }

        for (pair<const string, int>& target : targets[result[result.size() - 1]])
        {
            if (target.second > 0 )
            {
                result.push_back(target.first);
                target.second--;
                if (backtracking(ticketNum, result)) return true;
                result.pop_back();
                target.second++;
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        targets.clear();
        vector<string> result;
        for (const vector<string>& vec : tickets){
            targets[vec[0]][vec[1]]++; 
        }
        result.push_back("JKF");
        backtracking(tickets.size(),result);
        return result;
    }
};

class Solution {
private:
    // unordered_map<出发机场, map<到达机场, 航班次数>> targets
    unordered_map<string, map<string, int>> targets;
    bool backtracking(int ticketNum, vector<string>& result) {
        if (result.size() == ticketNum + 1) {
        return true;
        }
        for (pair<const string, int>& target : targets[result[result.size() - 1]])
        {
            if (target.second > 0 ) { // 记录到达机场是否?过了
                result.push_back(target.first);
                target.second--;
                if (backtracking(ticketNum, result)) return true;
                result.pop_back();
                target.second++;
            }
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        targets.clear();
        vector<string> result;
        for (const vector<string>& vec : tickets) {
            targets[vec[0]][vec[1]]++; // 记录映射关系
        }
        result.push_back("JFK"); // 起始机场
        backtracking(tickets.size(), result);
        return result;
    }
};