/*
Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and implement it using a program to find which alphabet has maximum number of occurences and print it.
(Time Complexity = O(n))  (Hint: Use Counting Sort)
*/

#include <iostream>
using namespace std;

int main()
{
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t--)
    {
        int n, i;
        cout << "Enter the size of Array: ";
        cin >> n;
        char ch[n];
        int temp[200] = {0};
        cout << "Enter the alphabets in the Array: "<<endl;
        for (i=0;i<n;i++)
        {
            cin >> ch[i];
            temp[ch[i]]++;
        }
        int index = -1, max = 0;
        for (i=0;i<200;i++)
        {
            if (temp[i] > max)
            {
                index = i;
                max = temp[i];
            }
        }
        if (max>1)
            cout << (char)index << " - " << max << endl;
        else
            cout << "No Duplicates Present"
                 << "\n";
    }
}