/*
Given an unsorted Array of positive integers, design an algorithm and implement it using a program to find whether there are any duplicate elements in the array or not.(use sorting)
(Time Complexity = O(nlogn))
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printArray(int A[], int s)
{
    for(int i=0;i<s;i++)
    {
        cout<<" "<<A[i];
    }
    cout<<endl;
}

void Merge(int A[], int low, int mid, int high)
{
    int i, j, k;
    i=low, j=mid+1, k=low;
    int C[100];
    while(i<=mid && j<=high)
    {
        if(A[i]<A[j])
        {
            C[k]=A[i];
            i++;
            k++;
        }
        else{
            C[k]=A[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        C[k]=A[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        C[k]=A[j];
        k++;
        j++;
    }
    for(int i=low;i<=high;i++)
    {
        A[i]=C[i];
     }

}

void MergeSort(int A[], int low, int high)
{
    int mid;
    if(low<high)
    {
        mid = (low+high)/2;
        MergeSort(A, low, mid);
        MergeSort(A, mid+1, high);
        Merge(A, low, mid, high);
    }

}

int main()
{
    int T, n, key, j;
    cout<<"Enter the number of test cases: ";
    cin>>T;                   

    for (int i=0;i<T;i++)
    {
        cout<<"Enter the size of the Array: ";
        cin>>n;
        int arr[n];
        cout<<"Enter the elements of the Array: "<<endl;
        for (int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        // cout<<"Array before Sorting: ";
        // printArray(arr, n);

        MergeSort(arr, 0, n-1);

        // sort(arr, arr+n);

        int flag=0;

        for(int i=0;i<=n;i++)
        {
            if(arr[i]==arr[i+1])
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            cout<<"Duplicate Element."<<endl;
        }
        else{
            cout<<"No Duplicate Element."<<endl;
        }

        // cout<<"Array after Sorting: ";
        // printArray(arr, n);
    }
}