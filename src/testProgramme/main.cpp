#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
private:
    queue<pair<int,int>> q;         //位置，步数
    unordered_set<int> se;      //位置
    bool bfs(int start,int end)
    {
        q.emplace(make_pair(start,0));
        while(!q.empty())
        {
            auto P = q.front();
            q.pop();
            int step = P.second;
            int pos = P.first;

            cout << "本次弹出：" << endl
                 << pos << ' ' << step << endl;

            if (pos == end)
                return true;
            for(int i =-1;i<=1;i++)
            {
                int next_st = step+i;
                int next_pos = next_st + pos;
                if(next_pos==end) return true;
                if(next_pos>=0&&se.count(next_pos)&&next_pos!=pos)
                {
                    q.emplace(make_pair(next_pos,next_st));
                    cout << "本次写入：" << endl
                        << next_pos << ' ' << next_st << endl;
                }
            }

        }
        return false;
    }


public:
    bool canCross(vector<int>& stones) {
        se.clear();
        int len = stones.size();
        for(int i = 0;i<len;i++)
        {
            se.insert(stones[i]);
        }
        int end = stones[len-1];
        bool ans = bfs(stones[0],end);
        return ans;
    }
};

int main()
{
    Solution S;
    vector<int> T(8);
    T[0] = 0;
    T[1] = 1;
    T[2] = 3;
    T[3] = 6;
    T[4] = 10;
    T[5] = 13;
    T[6] = 15;
    T[7] = 18;
    bool test = S.canCross(T);
    cout << test << endl;
    system("pause");
    return 0;
}