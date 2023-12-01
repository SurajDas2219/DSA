#include <bits/stdc++.h>
using namespace std;

// MergeSort Algo Means Divide and Merge

// Problem Statement :Given an unsorted array, sort the give array in non-decreasing order

// Intutution:Merge Sort  works with an  intution is that given an unsorted array
/*
    --1.first divide the entire array till there is only one element left and then merge the corresponding array
 */

/*
    In this we use two functions
    mergeSort:-to divide the array into two equal parts (not necessarily) hypothetically recursively using low mid and high
            where low is the left index and
             high is the right index
             mid=low+high/2
             Base case:When only one element left i.e (low>=high)

    Then merge function can be inmplemented

    Time complexity: O(nlogn)

    Reason: At each step, we divide the whole array, for that logn and we assume n steps are taken to get sorted array, so overall time complexity will be nlogn

    Space complexity: O(n)

    Reason: We are using a temporary array to store elements in sorted order.

    Auxiliary Space Complexity: O(n)

*/

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    // Base Case
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{

    vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    cout << "Before Merge sort:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr, low, high);
    cout << "After Merge sort:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
