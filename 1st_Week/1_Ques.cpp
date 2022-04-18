/*
Given an array of non-negative integers, design a linear algorithm and implement it using a 
program to find whether given key element is present in the array or not. Also, find total number 
of comparisons for each input case. (Time Complexity = O(n), where n is the size of input)
*/


// Linear Search

#include<iostream>
using namespace std;

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

        int flag;                    // Key is present or not
        int count=0;                // Total number of comparisons
        for(int i=0;i<n;i++)
        {
            count++;
            flag=0;
            if(key==arr[i])
            {
                flag=1;
                break;
            }
            else{
                flag=0;
            }
        }
        if(flag==1)
        {
            cout<<"Key is Present."<<endl;
            cout<<"Number of Comparisons = "<<count<<endl;
        }
        else{
            cout<<"Key is not Present."<<endl;
            cout<<"Number of Comparisons = "<<count<<endl;
        }
    }
}