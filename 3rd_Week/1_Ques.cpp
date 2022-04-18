/*
Given an unsorted Array of integers, design an algorithm and a program to sort the array using insertion sort. Your program should be able to find number of comparisons and shifts
(shifts - total number of times the array elements are shifted from their place)
required for sorting the array.
*/

#include<iostream>
using namespace std;

void printArray(int A[], int s)
{
    for(int i=0;i<s;i++)
    {
        cout<<" "<<A[i];
    }
    cout<<endl;
}

int main()
{
    int T, n, key, j, comp=0, shifts=0;
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

        for(int i=1;i<n;i++)
        {
            key=arr[i];
            j=i-1;
            while(j>=0 && arr[j]>key)
            {
                arr[j+1]=arr[j];
                j--;
                comp++;
                shifts++;
            }
            arr[j+1]=key;
            shifts++;
        }

        cout<<"Array after Sorting: ";
        printArray(arr, n);
        
        cout<<"Number of comparisons: "<<comp<<endl;
        cout<<"Number of shifts: "<<shifts<<endl;
    }
}