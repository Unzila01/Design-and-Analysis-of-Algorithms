/*
Given a directed graph, design an algorithm and implement it using a program to find whether cycle exists in the graph or not.
*/

#include<iostream>
#include<vector>

using namespace std; 
bool cheak_cycle(int node , vector<vector<int>>&adj , vector<int>&vis, vector<int>&dfsvis){
    vis[node]=1;
    dfsvis[node]=1;

    for(int i=1;i<adj[node].size();i++)
     {
         if(adj[node][i]==1 && vis[i]==0)
         {
          if(cheak_cycle(adj[node][i],adj,vis,dfsvis))
            return true;
            
         }  
         else if(adj[node][i]==1 && vis[i]==1 && dfsvis[i]==1){
             return true;
         }
     }
     dfsvis[node]=0;
     return false;
}

int main(){
int n;
cout<<"Enter the number of Nodes: ";
cin>>n;
vector<vector<int>>adj(n+1,vector<int>(n+1,0));

 for(int i=1;i<n+1;i++)
 {
     for(int j=1;j<n+1;j++)
     cin>>adj[i][j];
 }
 vector<int>vis(n+1,0);
 vector<int>dfsvis(n+1,0);
 for(int i=1;i<n+1;i++)
 {
     if(!vis[i]){
     if(cheak_cycle(i,adj,vis,dfsvis)){
         cout<<"Cycle Found";
         return 0;
     }
     }
 }
     cout<<"No cycle found!!";
    return 0;
}