#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <iostream>
#define TEST 1

using namespace std;

class Solution {
private:
    unordered_map <int,int> tarvisited;          //站台，步数
    queue<pair<int,int>> tarq;                  //位置，站台

    unordered_map<int,unordered_set<int>> mk;    //位置，站台

    unordered_map <int,int> srcvisited;           //站台，步数
    queue<pair<int,int>> srcq;                    //位置，站台

    int bfs(vector<vector<int>> routes,queue<pair<int,int>>& cur, queue<pair<int,int>>& other, unordered_map <int,int>& curvsted ,unordered_map <int,int>& othervsted)
    {
        int all = cur.size();
        int temp = -1;
        while(all--)
        {
            auto [pos,stat] = cur.front();
            cur.pop();

            int len = routes[stat].size();
            if(othervsted.count(stat)) {
                int endGame1 = othervsted[stat] + curvsted[stat] -1 ;
                temp = temp>0?(temp>=endGame1?endGame1:temp):endGame1;
                }
            for(int i = 0 ; i < len ; ++i)
            {
                
                int next_pos = routes[stat][i];
                if(next_pos==pos) continue;
                for(auto next_stat : mk[next_pos])
                {
                    if(next_stat==stat) {continue;}

                    if(othervsted.count(next_stat)) 
                    {
                        int endGame2 = othervsted[next_stat] + curvsted[stat];
                        temp = temp>0?(temp>=endGame2?endGame2:temp):endGame2;
                    }
                    if(!curvsted.count(next_stat))
                    {
                        cur.emplace(make_pair(next_pos,next_stat));
                        curvsted[next_stat]=curvsted[stat]+1;
                    }
                }
            }
        }

        return temp;
    }

public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int bus = routes.size();
        if(source==target) return 0;
        for(int i =0 ;  i<bus;++i)
        {
            for(auto tar : routes[i])
            {
                mk[tar].insert(i);
                if(tar==target)
                {
                    tarq.emplace(make_pair(tar,i));
                    tarvisited[i]=1;
                }
                if(tar==source)
                {
                    srcq.emplace(make_pair(tar,i));
                    srcvisited[i]=1;
                }
            }
        }
        int ans = -1;
        while(!tarq.empty()&&!srcq.empty())
        {
            int tarlen = tarq.size();
            int srclen = srcq.size();
            if(tarlen>=srclen)
            {
                ans = bfs(routes,tarq,srcq,tarvisited,srcvisited);
            }
            else
            {
                ans = bfs(routes,srcq,tarq,srcvisited,tarvisited);
            }
            if(ans!=-1) return ans;
        }
        return -1;
    }
};
int main()
{
    Solution S;
    // vector<int> a(2);
    // a = {7, 12};
    // vector<int> b(3);
    // b = {4, 5, 15};
    // vector<int> c(1);
    // c = {6};
    // vector<int> d(2);
    // d = {15, 19};
    // vector<int> e(3);
    // e = {9, 12, 13};

    // vector<vector<int>> T(5);
    // T[0] = a;
    // T[1] = b;
    // T[2] = c;
    // T[3] = d;
    // T[4] = e;

    vector<int> a(3);
    a = {1, 2, 7};
    vector<int> b(3);
    b = {3, 6, 7};
    vector<vector<int>> T(2);
    T[0] = a;
    T[1] = b;

    int test = S.numBusesToDestination(T, 1, 6);
    cout << test << endl;
    system("pause");
    return 0;
}


