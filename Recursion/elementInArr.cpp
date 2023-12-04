#include <bits/stdc++.h>
using namespace std;

void recursivePrintEle(int arr[], int n)
{
    // without an iterator i=0
    // base case
    if (n <= 0)
    {
        return;
    }
    cout << arr[0] << " ";             // processing
    recursivePrintEle(arr + 1, n - 1); // recursive relation
}

void recursivePrintElement(int arr[], int n, int i)
{
    // using an iterator i=0
    // base case
    if (i >= n)
    {
        return;
    }
    cout << arr[i] << " ";
    return recursivePrintElement(arr, n, i + 1);
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    recursivePrintEle(arr, n);
}