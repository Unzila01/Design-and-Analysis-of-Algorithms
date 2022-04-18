/*
Given a sorted array of positive integers containing few duplicate elements, design an algorithm and implement it using a program to find whether the given key element is present in the array or not.
if present, then also find the number of copies of given key. (Time Complexity = O(log n))
*/

#include <iostream>
using namespace std;

int BinarySearch(int A[], int s, int key, bool firstOccurence)
{
    int low=0, high=s-1, result=-1;

    while(low<=high)
    {
        int mid=(low+high)/2;
        if(A[mid]==key)
        {
            result=mid;
            if(firstOccurence)
            {
                high=mid-1;               // Searching in left side
            }
            else{
                low=mid+1;               // Searching in right side
            }

        }
        else if(A[mid]>key)
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return result;
}

int main()
{
    int T, n, key;
    cout<<"Enter the number of test cases: ";
    cin>>T;                   // Number of test cases

    for (int i=0;i<T;i++)
    {
        cout<<"Ente rthe size of the Array: ";
        cin>>n;
        int arr[n];

        cout<<"Enter the elements of the Array: ";
        for (int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<"Enter the key: ";
        cin>>key;

        int firstOccurence = BinarySearch(arr, n, key, true);

        if(firstOccurence==-1)
        {
            cout<<"Key is not present."<<endl;
        }
        else{
            int lastOccurence = BinarySearch(arr, n, key, false);
            cout<<"Key is Present."<<endl;
            cout<<"Number of Copies: "<<lastOccurence-firstOccurence+1<<endl;
        }    
    }

    return 0;
}
