/*
Given an already sorted array of positive integers, design an algorithm and implement it using a 
program to find whether given key element is present in the array or not. Also, find total number 
of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input).
*/

#include<iostream>
using namespace std;

int comparisons=0;

int BinarySearch(int arr[], int left, int right, int key)
{
    if(left<=right)
    {
        int mid = left+(right-left)/2;
        comparisons++;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
        return BinarySearch(arr, mid+1, right, key);
        else
        return BinarySearch(arr, left, mid-1, key);
    }
    return -1;
}


int main()
{
    int T, n, key;
    cout<<"Enter the number of test cases: ";
    cin>>T;                   // Number of test cases

    for (int i=0;i<T;i++)
    {
        cout<<"Enter the size of the Array: ";
        cin>>n;
        int arr[n];

        cout<<"Enter the Elements: ";
        for (int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        cout<<"Enter the Key: ";
        cin>>key;

        if(BinarySearch(arr, 0, n-1, key))
        {
            cout<<"Key is Present."<<endl;
        }
        else{
            cout<<"Key is not Present."<<endl;
        }
        cout<<"Number of comparisons: "<<comparisons<<endl;
    }
}