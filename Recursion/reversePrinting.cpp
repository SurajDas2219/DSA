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
    recursivePrintEle(arr + 1, n - 1); // recursive relation
    cout << arr[0] << " ";             // processing
}

void recursivePrintElement(int arr[], int n, int i)
{
    // using an iterator i=0
    // base case
    if (i >= n)
    {
        return;
    }
    recursivePrintElement(arr, n, i + 1);
    cout << arr[i] << " ";
}
int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    cout << "With iterator:" << endl;
    recursivePrintElement(arr, n, i);
    cout << endl;
    cout << "Without iterator:" << endl;
    recursivePrintEle(arr, n);
}