/*
Given a list of activities with their starting time and finishing time. Your goal is to select maximum number of activities that can be performed by a single person such that selected activities must be non-conflicting. Any activity is said to be non-conflicting if starting time of an activity is greater than or equal to the finishing time of the other activity. Assume that a person can only work on a single activity at a time.
*/

#include<bits/stdc++.h>
using namespace std;

struct Activity
{
    int start, finish;
};

bool compare(Activity A1, Activity A2)
{
    return A1.finish < A2.finish;
}

int main()
{
    int n;
    cout<<"Enter the number of Activities: ";
    cin>>n;
    struct Activity arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].start;
        cin>>arr[i].finish;
    }
    
    sort(arr, arr+n, compare);

    int i=0;
    int count=1;
    for(int k=1;k<n;k++)
    {
        if(arr[k].start>=arr[i].finish)
        {
            count++;
            i=k;
        }
    }   
    cout<<"Number of non-conflicting activities: "<<count<<endl; 

}