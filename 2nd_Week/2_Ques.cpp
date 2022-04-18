/*
Given a sorted array of positive integers, design an algorithm and implement it using a program to find three indices i, j, k such that arr[i]+arr[j]=arr[k].
*/

#include<iostream>
using namespace std;

int main()
{
    int T, flag=0;
    cout<<"Enter the number of test cases: ";
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cout<<"Enter the size of the Array: ";
        int n;
        cin>>n;
        int arr[n];

        cout<<"Enter the elements of the Array: ";
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                int sum = arr[i] + arr[j];
                for(int k=1;k<n;k++)
                {
                    if (arr[i]+arr[j]==arr[k])
                    {
                        cout<<"Three indices are: "<<i+1<<", "<< j+1<<", "<< k+1<<endl;
                        return 0;
                    }
                }
            }
        }
        if(flag==0)
        {
            cout<<"No sequence found."<<endl;
        }
    }

    return 0;
}