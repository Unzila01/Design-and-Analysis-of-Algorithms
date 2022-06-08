/*
Given a graph, design an algorithm and implement it using a program to find if a graph is bipartite or not. (Hint: use BFS)
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std; 
bool bipartite(int node , vector<vector<int>>&adj , vector<int>&color){
     queue<int>q;
     q.push(node);
     color[node]=1;
     while(!q.empty()){
         int t=q.front();
         q.pop();

         for(int i=1;i<adj[t].size();i++){
             if(adj[t][i]==1 && color[i]==-1){
                 color[i]=1-color[t];
                 q.push(i);
             }
             else if(adj[t][i]==1 && color[i]==color[t]){
                 return false;
             }
         }
     }
     return true;
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
 vector<int>color(n+1,-1);
 for(int i=1;i<n+1;i++)
 {
     if(color[i]==-1){
     if(bipartite(i,adj,color)){
         cout<<"Bipertite";
         return 0;
     }
     }
 }
     cout<<"Not a Bipartite";
    return 0;
}