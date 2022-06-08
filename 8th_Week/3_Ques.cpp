/*
Assume that same road construction project is given to another person. The amount he will earn from this project is directly proportional to the budget of the project. This person is greedy, so he decided to maximize the budget by constructing those roads who have highest construction cost. Design an algorithm and implement it using a program to find the maximum budget required for the project.
*/

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int parent[N],size[N];

void make(int v)
{
    parent[v]=v;
    size[v]=1;
}
int find(int v)
{
    if(parent[v]==v)
    return v;
    return parent[v]=find(parent[v]);
}
void Union(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
    {
        if(size[a]<size[b])
            swap(a,b);
            parent[b]=a;
            size[a]+=size[b];
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    // first is weight,then in next pair we have u and v
    vector<pair<int, pair<int,int>>>edges;
    for(int i=0;i<m;++i)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});

    }
    sort(edges.begin(),edges.end());
    reverse(edges.begin(),edges.end());
    for(int i=1;i<=n;++i)
    {
        make(i);
    }
    int total_cost=0;
    for(auto &edge:edges)
    {
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        //check  if u and v are formed a cycle
        if(find(u)==find(v))
        continue;
        Union(u,v);
        total_cost+=wt;
        cout<<u<<" "<<v<<endl;
    }
    cout<<total_cost<<endl;
}