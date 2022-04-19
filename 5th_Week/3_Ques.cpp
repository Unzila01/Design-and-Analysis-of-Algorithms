/*
You have been given two sorted integer arrays of size m and n. Design an algorithm and implement it using a program to find list of elements which are common to both.
Time Complexity = O(m+n)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;

    cout<<"Enter the size of 1st Array: ";
    cin>>m;
    int array1[m];
    cout<<"Enter the Elements of the 1st Array: "<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>array1[i];
    }
    sort(array1, array1+m);

    cout<<"Enter the size of 2nd Array: ";
    cin>>n;
    int array2[n];
    cout<<"Enter the Elements of the 2nd Array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>array2[i];
    }
    sort(array2, array2+n);

    int maximum = max(m, n);
    int ptr1=0, ptr2=0;

    for(int i=0;i<maximum;i++)
    {
        if(array1[ptr1]==array2[ptr2])
        {
            cout<<array1[ptr1]<<" ";
            ptr1++;
            ptr2++;
        }
        else if(array1[ptr1]<array2[ptr2])
        {
            ptr1++;
        }
        else
        {
            ptr2++;
        }
    }

}