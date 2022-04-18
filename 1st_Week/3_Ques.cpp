/*
Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether a given key element is present in the sorted array or not. For an array
arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2^k] and so on.
Once the interval (arr[2^k] < key < arr[ 2^k+1] ) is found, perform a linear search operation from the index 2^k to find the element key.
(Complexity < O(n), where n is the number of elements need to be scanned for searching)
*/

// Jump Search, Time Complexity-O(sqrt(n))

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int cmp=0;

int jumpSearch(int arr[], int n, int key)
{
    int jumpBlock = sqrt(n);
    int i=0, j=jumpBlock;

    while(j<n && arr[j]<key)
    {
        i=jumpBlock;
        j+=jumpBlock;
        if(i>=n)
        {
            return 0;
        }
    }
    for(int k=i;k<=j;k++)
    {
        if(arr[k]==key)
        {
            return k;
        }
        cmp++;
    }
    return 0;
}

int main()
{
    int T, n, key;
    cout << "Enter the number of test cases: ";
    cin >> T; // Number of test cases

    for (int i = 0; i < T; i++)
    {
        cout << "Enter the size of the Array: ";
        cin >> n;
        int arr[n];

        cout << "Enter the Elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << "Enter the Key: ";
        cin >> key;

        int res = jumpSearch(arr, n, key);

        if(jumpSearch(arr, n, key))
        {
            cout<<"Key is found at index "<<res<<endl;
        }
        else if(!jumpSearch(arr, n, key))
        {
            cout<<"Key not found."<<endl;
        }
        cout<<"Number of Comparisons: "<<cmp<<endl;
    }
    return 0;
}
