/*
Given an unsorted array of integers, design an algorithm and implement it using a program to find whether two elements exist such that their sum is equal to the given key element.
(Time Complexity = O(n log n))
*/

#include<iostream>
#include<math.h>
using namespace std;

int inversions=0;

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

int MergeSort(int A[], int low, int high)
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

int binarySearch(int a[] , int l , int r , int x)
{
    while (l<=r)
    {
        int m=l+(r-l)/2;
 
        if (a[m]==x)
            return m;
        if (a[m]<x)
            l=m+1;
        else
            r=m-1;
    }
    return 0;
}

int main()
{
    int T, n, key, j;
    cout<<"Enter the number of test cases: ";
    cin>>T;                   // Number of test cases

    for (int i=0;i<T;i++)
    {
        cout<<"Enter the size of the Array: ";
        cin>>n;
        int arr[n], B[n];
        cout<<"Enter the elements of the Array: "<<endl;
        for (int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        cout<<"Array before Sorting: ";
        printArray(arr, n);

        int r=MergeSort(arr, 0, n-1);

        cout<<"Array after Sorting: ";
        printArray(arr, n);

        cout<<"Enter the key: ";
        cin>>key;

        int start=0;
        int end=n-1;
        bool flag=false;

        while(start<end)
        {
            if(arr[start]+arr[end]>key)
            {
                end--;
            }
            else if(arr[start]+arr[end]<key)
            {
                start++;
            }
            else
            {
                cout<<"Elements found."<<endl;
                cout<<"Elements are: "<<arr[start]<<" "<<arr[end]<<endl;
                start++;
                flag=true;
                break;
            }
        }
        if(flag==false)
            cout<<"No such Elements exist."<<endl;
    }
}