/*
Given a knapsack of maximum capacity w. N items are provided, each having its own value and weight. You have to Design an algorithm and implement it using a program to find the list of the selected items such that the final selected content has weight w and has maximum value. You can
take fractions of items,i.e. the items can be broken into smaller pieces so that you have to carry  only a fraction xi, of item i, where 0<=xi<=1.
*/

#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>a,pair<int,int>b)
    {
        double i1=a.first/a.second;
        double i2=b.first/b.second;
        return i1>i2;
    }
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>item;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        item.push_back({x,y});
    }
    int k;
    cin>>k;
    sort(item.begin(),item.end(),compare);
    double profit =0.0;
    for(int i=0;i<n;i++)
    {
        if(k>=item[i].second)
        {
            k-=item[i].second;
            profit+=item[i].first;

        }
        else
        {
            profit+=double(item[i].first)/(item[i].second*k);
            break;
        }
    }
    cout<<profit;
    return 0;
}