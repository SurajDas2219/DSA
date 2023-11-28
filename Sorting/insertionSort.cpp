// Problem Statement :Sort the given array by using insertion sort
// Intution:This algorithm pic every single element of an array and place it to its correct poisiton
#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

int main()
{
    int arr[] = {2, 13, 4, 1, 3, 6, 28};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before insertion sort:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // 2 13 4 1 3 6 28
    }
    cout << "\n";
    insertion_sort(arr, n);
    cout << "After insertion sort:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // 1 2 3 4 6 13 28
    }

    return 0;
}

/*
Time complexity: O(N^2), (where N = size of the array), for the worst, and average cases.
Reason: If we carefully observe, we can notice that the outer loop, say i, is running from 0 to n-1 i.e. n times, and for each i, the inner loop j runs from i to 1 i.e. i times. For, i = 1, the inner loop runs 1 time, for i = 2, the inner loop runs 2 times, and so on. So, the total steps will be approximately the following: 1 + 2 + 3 +……+ (n-2) + (n-1). The summation is approximately the sum of the first n natural numbers i.e. (n*(n+1))/2. The precise time complexity will be O(n2/2 + n/2). Previously, we have learned that we can ignore the lower values as well as the constant coefficients. So, the time complexity is O(n2). Here the value of n is N i.e. the size of the array.

Space Complexity: O(1)

*/