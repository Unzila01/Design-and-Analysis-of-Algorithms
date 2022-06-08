/*
Given a graph, Design an algorithm and implement it using a program to implement Floyd-Warshall all pair shortest path algorithm.
*/

#include<bits/stdc++.h>
using namespace std;
const int N=150;
const int INF=1e9;
int dist[N][N];
int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i==j)
              dist[i][j]=0;
            else
              dist[i][j]=INF;
        }
    }
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
       int x,y,wt;
       cin>>x>>y>>wt;
       dist[x][y]=wt;

    }
for(int k=1;k<=n;k++)
  {
     for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(dist[i][k]!=INF && dist[k][j]!=INF)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
 }
 for(int i=1;i<=n;i++)
  {
     for(int j=1;j<n;j++)
    {
        if(dist[i][j]==INF)
           cout<<"INF";
        else
          cout<<dist[i][j]<<" ";
    }
    cout<<endl;
 }
 return 0;
}