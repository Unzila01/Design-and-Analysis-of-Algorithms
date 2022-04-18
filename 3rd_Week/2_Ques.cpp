/*
Given an unsorted Array of integers, design an algorithm and implement a program to sort this array using Selection sort. Your program should also find the number of comparisons and number of swaps required.
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
    int T, n, key, j, swaps=0;
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

        for(int i=0;i<=n-2;i++)
        {
            int min=i;
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]<arr[min])
                {
                    min=j;
                }
            }
            
            swaps++;
            if(i!=min)
            {
                int temp=arr[min];
                arr[min]=arr[i];
                arr[i]=temp;
            }
        }

        cout<<"Array after Sorting: ";
        printArray(arr, n);
        cout<<"Number of comparisons: "<<n*(n-1)/2<<endl;
        cout<<"Number of swaps: "<<swaps<<endl;
    }
}