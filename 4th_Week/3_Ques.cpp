/*
Given an unsorted array of integers, design an algorithm and implement it using a program to find kth smallest or largest element in the array. (Worst case Time Complexity = O(n))
*/

#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}
int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int index = partition(arr, l, r);
        if (index - l == k - 1)
            return arr[index];
        if (index - l > k - 1)
            return kthSmallest(arr, l, index - 1, k);
        return kthSmallest(arr, index + 1, r, k - index + l - 1);
    }
    return INT_MAX;
}
int main()
{
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    while (T--)
    {
        int n, k;
        cout << "Enter the size of Array: ";
        cin >> n;
        int arr[n];
        cout << "Enter the elements of Array: ";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << "Enter the kth element: ";
        cin >> k;
        cout << "kth smallest element is " << kthSmallest(arr, 0, n - 1, k);
    }
    return 0;
}