/*
Given a set of elements, you have to partition the set into two subsets such that the sum of
elements in both subsets is same. Design an algorithm and implement it using a program to solve
this problem.
*/

#include<bits/stdc++.h>
using namespace std;

bool subset(vector<int> &arr,int n,int sum)
    {
        int t[n+1][sum+1];
        for (int i=0;i<sum+1;i++)
           t[0][i]=false;
        for (int i=0;i<n+1;i++)
           t[i][0]=true;
        for (int i=1;i<n+1;i++)
        {
            for (int j=1;j<sum+1;j++)
            {
                if (arr[i-1]<=j)
                 t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
                else
                 t[i][j]=t[i-1][j]; 
            }
        }
        return t[n][sum];
    }
int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Enter the n number in array: "<<endl;
    vector<int> arr(n,0);
    for (int i=0;i<n;i++)
       cin>>arr[i];

    int sum=accumulate(arr.begin(),arr.end(),0);
    if (sum%2==0)
    {
       if (subset(arr,n,sum/2))
        cout<<"Yes";
       else
        cout<<"No";
    }
    else
     cout<<"No";
}