/*
Given a sequence of matrices, write an algorithm to find most efficient way to multiply these
matrices together. To find the optimal solution, you need to find the order in which these
matrices should be multiplied.
*/

#include<bits/stdc++.h>
using namespace std;
int static dp[1001][1001];
int solve(int arr[],int i,int j)
{
    int mn=INT_MAX;
    if(i>=j)
    return 0;
    if(dp[i][j]!=-1)
       return dp[i][j];
    for(int k=i;k<=j-1;k++)
    {
        int tempans=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if(tempans<mn)
         mn=tempans;
    }
    return dp[i][j]=mn;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      {   
          cin>>arr[i];
      }
   cout<<solve(arr,1,n-1);
   return 0;
}