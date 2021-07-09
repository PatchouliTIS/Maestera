#include <bits/stdc++.h>
using namespace std;


map<int,unordered_set<int>> mck;
unordered_map<int,int> tar;


int main()
{
    mck.clear();
    tar.clear();
    vector<int> n(5,1);
    vector<int> a(2);
    a[0] = 2;
    a[1] = 3;

    for(int i : n)
    {
        tar[i]++;
    }
    
    for(auto [i , times] : tar)
    {
        mck[times].insert(i);
    }

    cout << "before manu size: " << mck.size() << endl;
    


    auto it = mck.lower_bound(a[0]);
    int now = it->first;
    cout << "before manu SET_size: " << (it->second).size() << endl;
    auto target = (*it).second.begin();
    cout << "target " << (*target) << endl;
    (*it).second.erase(target);
    cout << "after manu SET_size: " << (it->second).size() << endl;
    cout << "after manu target: " << (*target) << endl;

    mck.erase(it);

    cout << "after manu size: " << mck.size() << endl;

    
    mck[now - a[0]].insert(a[0]);

    cout << "after manu size: " << mck.size() << endl;


    //2
    it = mck.lower_bound(a[1]);
    cout << "before manu SET_size: " << (it->second).size() << endl;

    target = (*it).second.begin();
    cout << "target " << (*target) << endl;

    (*it).second.erase(target);
    cout << "after manu SET_size: " << (it->second).size() << endl;

    mck.erase(it);

    cout << "after manu size: " << mck.size() << endl;

    now = it->first;

    mck[now - a[1]].insert(a[1]);

    cout << "after manu size: " << mck.size() << endl;


    system("pause");
    return 0;
}


class Solution {
private:
    map<int,unordered_set<int>> mck;
    unordered_map<int,int> tar;
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        tar.clear();
        mck.clear();
        int len = nums.size();
        for(int i : nums)
        {
            tar[i]++;
        }
        
        for(auto [i , times] : tar)
        {
            mck[times].insert(i);
        }


        for(auto need : quantity)
        {
            auto it = mck.lower_bound(need);
            if(it!=mck.end())
            {
                int remains = (*it).first-need;
                auto target = (*it).second.begin();
                cout<<"remains: "<<remains<<endl;
                if(remains!=0)
                {
                    (*it).second.erase(target);
                    if(!(*it).second.size())
                    {
                        mck.erase(it);
                    }
                    mck[remains].insert(*target);
                }
                else
                {
                    (*it).second.erase(target);
                    if(!(*it).second.size())
                    {
                        mck.erase(it);
                    }
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};