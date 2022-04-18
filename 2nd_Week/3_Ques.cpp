/*
Given an array of non-negative integers, design an algorithm and a program to count the number of pairs of integers such that their difference is equal to a given key, K
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int T;
    cout<<"Enter the number of test cases: ";
    cin>>T;

    for (int i=0;i<T;i++)
    {
        cout<<"Enter the size of the Array: ";
        int n;
        cin>>n;
        int arr[n];

        cout<<"Enter the elements of the Array: ";
        for (int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int k;

        cout<<"Enter the key: ";
        cin>>k;

        int count=0;

        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if((arr[i]-arr[j])==k)
                {
                    count++;
                }
            }
        }
        cout<<"Number of Pairs: "<<count;
    }

    return 0;
}