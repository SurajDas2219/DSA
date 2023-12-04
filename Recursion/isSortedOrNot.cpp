#include <bits/stdc++.h>
using namespace std;

int checkSorted(int arr[], int n, int i)
{

    // base condition
    if (i == n - 1)
    {
        return true;
    }
    if (arr[i + 1] < arr[i])
    {
        return false;
    }
    return checkSorted(arr, n, i + 1);
}

int main()
{

    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    bool isSorted = checkSorted(arr, n, i);
    if (isSorted)
    {
        cout << "The Given array is Sorted" << endl;
    }
    else
    {
        cout << "The Given array is Not Sorted" << endl;
    }

    return 0;
}