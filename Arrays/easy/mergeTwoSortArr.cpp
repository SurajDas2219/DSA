#include <bits/stdc++.h>
using namespace std;

// Problem Statement:Merge Two Sorted Array using an extra space

// Approach:Two Pointer Approach
/*
--1.create a 3rd arr of size of sumation of size of two given array
--2.Initialize two pointer say i & j  and also k for iterating over arr3.
--3.'i' will start from 1st index of arr1 i.e arr1[0].
--4.'j' will start from 1st index of arr2 i.e arr2[0].
--5.After that initialize a while loop and that will loop from i<=arr1.size() && j<=arr2.size().
--6.Check if arr1[i]<2arr[j],if it is true then put arr1[i] into arr3[k] and then do i++ &ck++
--7.Else do arr3[k++]=arr2[j++].

    Time Complexity:O(N+M)+O(N+M).
    Space Complexity:O(N+M).

*/

void mergeTwoSortedArr(int *arr1, int n, int *arr2, int m, int *arr3)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i <= n && j <= m) // O(N+m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }
    // This is for the remaining element from arr1.
    while (i <= n)
    {
        arr3[k++] = arr1[i++];
    }
    // This is for the remaining element from arr2.
    while (j <= m)
    {
        arr3[k++] = arr2[j++];
    }
    // Placing back all the elements to the original respected array
    for (int i = 0; i < n + m; i++) // O(N+M)
    {
        if (i < n)
        {
            arr1[i] = arr3[i];
        }
        else
        {
            arr2[i - n] = arr3[i];
        }
    }
}

int main()
{

    int arr1[] = {1, 3, 5, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {2, 4, 6, 8, 9, 10};
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int arr3[n + m] = {0};

    mergeTwoSortedArr(arr1, n, arr2, m, arr3);
    cout << "First array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }

    cout << endl;

    cout << "Second array: ";

    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    cout << "Final Merged Array:";
    for (int i = 0; i < n + m; i++)
    {
        cout << arr3[i] << " ";
    }

    return 0;
}

/*----------------------------------------------------------------

    Output:

    First array: 1 2 3 4
    Second array: 5 6 7 8 9 10
    Final Merged Array:1 2 3 4 5 6 7 8 9 10

*/