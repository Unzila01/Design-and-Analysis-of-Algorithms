/*
Given an unsorted array of integers, design an algorithm and implement it using a program to sort an array of elements by partitioning the array into two subarrays based on a pivot element such that one of the sub array holds values smaller than the pivot element while another sub array holds values greater than the pivot element. Pivot element should be selected randomly from the array. Your program should also find number of comparisons and swaps required for sorting the array.
*/

#include<iostream>
using namespace std;

static int comparisons=0;
static int swaps=0;

void printArray(int A[], int s)
{
    for(int i=0;i<s;i++)
    {
        cout<<" "<<A[i];
    }
    cout<<endl;
}

void swap(int *a,int *b){
    swaps++;
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int A[], int low, int high)
{
    int pivot=A[high];
    int i=low-1;
    for(int j=i+1;j<high;j++)
    {
        comparisons++;
        if(A[j]<pivot)
        {
            i++;
            swap(&A[i], &A[j]);
        }
    }
        swap(&A[i+1], &A[high]);
    return i+1;
}

void QuickSort(int A[], int low, int high)
{
   int index;  // Index of pivot
   if(low<high)
   {
        index = partition(A, low, high);
        QuickSort(A, low, index-1);         // sort left subarray
        QuickSort(A, index+1, high);        // sort right subarray
   }
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
        int arr[n];
        cout<<"Enter the elements of the Array: "<<endl;
        for (int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        cout<<"Array before Sorting: ";
        printArray(arr, n);

        QuickSort(arr, 0, n-1);

        cout<<"Array after Sorting: ";
        printArray(arr, n);


        cout<<"Number of comparisons: "<<comparisons<<endl;
        cout<<"Number of swaps: "<<swaps<<endl;
    }
}