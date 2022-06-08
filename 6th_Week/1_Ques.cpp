/*
Given a (directed/undirected) graph, design an algorithm and implement it using a program to find if a path exists between two given vertices or not. (Hint: use DFS)
*/

#include<iostream>
#include<vector>

using namespace std; 

bool dfs(int src,vector<int>&vis,vector<vector<int>>&v,int n,int dest)
{
     vis[src]=1;
     if(src==dest){
         return true;
     }
     for(int i=1;i<n+1;i++)
     {
         if(vis[i]!=1 && v[src][i]!=0)
         {
             return dfs(i,vis,v,n,dest);
         }
     }
         return false;
}
int main(){
int n;
cout<<"Enter the number of Nodes: ";
cin>>n;
vector<vector<int>>v(n+1,vector<int>(n+1,0));

 for(int i=1;i<n+1;i++)
 {
     for(int j=1;j<n+1;j++)
     cin>>v[i][j];
 }
 vector<int>vis(n+1);
 int src,dest;
 cout<<"Enter two vertex to find path: ";
 cin>>src>>dest;
     bool flag=dfs(src,vis,v,n,dest);
if(flag==true){
    cout<<"Path exist";
}
else{
    cout<<"Path does not exist";   
}
return 0;
}