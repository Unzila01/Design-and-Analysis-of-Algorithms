/*
Given an unsorted array of integers, design an algorithm and implement it using a program to sort an array of elements by dividing the array into two subarrays and combinig these two subarrays after sorting each one of them. Your program should also find the number of comparisons and inversions during sorting the array.
Inversions - Two elements A[i] and A[j] forms an Inversion if A[i]>A[j] && i<j
*/

#include<iostream>
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

int Merge(int A[], int low, int mid, int high)
{
    int count=0;
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
            inversions++;
        }
        count++;
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
    return count;
}

int MergeSort(int A[], int low, int high)
{
    int mid, count=0;
    if(low<high)
    {
        mid = (low+high)/2;
        count += MergeSort(A, low, mid);
        count += MergeSort(A, mid+1, high);
        count += Merge(A, low, mid, high);
    }
    return count;
}

int main()
{
    int T, n, key, j, comp=0;
    cout<<"Enter the number of test cases: ";
    cin>>T;                   // Number of test cases

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

        cout<<"Array before Sorting: ";
        printArray(arr, n);

        // for(int i=0;i<n;i++)
        // {
        //     for(int j=1;j<n;j++)
        //     {
        //         if(arr[i]>arr[j] && i<j)
        //         {
        //             inversions++;
        //         }
        //     }
        // }
        
        int r=MergeSort(arr, 0, n-1);

        cout<<"Array after Sorting: ";
        printArray(arr, n);


        cout<<"Number of comparisons: "<<r<<endl;
        cout<<"Number of inversions: "<<inversions<<endl;
    }
}