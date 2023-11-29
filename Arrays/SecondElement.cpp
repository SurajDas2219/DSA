#include <bits/stdc++.h>
using namespace std;

// Promblem Statement: Given an array we have to find the second smallest or second largest element in an array

// Brute force:Sort the array
//  Imp!!!!:-This will only work if the array contain unique Element

/*
Approach:
--1.Sort the given array;
--2.for Second smallest return arr[1];
--3. for Second largest return arr[n-2];
Time Complexity:-O(NlogN)
space Complexity:-O(1);
*/

int secondElement(vector<int> &arr1)
{
    int n = arr1.size();
    sort(arr1.begin(), arr1.end());
    int secondSmallest = arr1[1];
    int secondLargest = arr1[n - 2];
    // return secondSmallest;
    return secondLargest;
}

// Better Approach:This can handled Duplicate as well
/*
    --1.On optimizing the brute one we can do following step:
    --2.1st Traverse the entire array and find the smallest or the largest element in an array.
    --3.After getting the  largest or the smallest element in the entire array check for the condition
    --4.For second small:arr[i]<secondSmall and arr[i]!=smallest
    --5.for second large:arr[i]>secondLarge and arr[i]!=largest

    Time complexity:O(N)+O(N)=O(2N); 1st for the largest n second for the second large elementor smallest element
    Space complextiy:O(1);
*/

int secondEle(vector<int> &arr2)
{
    int largest = INT_MIN;
    int secondLarge = INT_MIN;
    int n = arr2.size();
    for (int i = 0; i < n; i++)
    {
        largest = max(largest, arr2[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (arr2[i] > secondLarge && arr2[i] != largest)
        {
            secondLarge = arr2[i];
        }
    }
    return secondLarge;
}

// Optimal Approach:

/*
 Two condition:
 if arr[i]>large
 slarge=large
 arr[i]=large

 Time complexity:O(N), Single-pass solution

Space Complexity: O(1)
 */

int getlargest(int n, vector<int> &a)
{
    int large = INT_MIN;
    int slarge = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > large)
        {
            slarge = large;
            large = a[i];
        }
        if (a[i] > slarge && a[i] != large)
        {
            slarge = a[i];
        }
    }
    return slarge;
}

int main()
{

    vector<int> arr1 = {9, 8, 7, 4, 2, 0};
    int n = arr1.size();

    vector<int> arr2 = {9, 9, 7, 4, 2, 0};
    int m = arr2.size();

    vector<int> a = {1, 2, 3, 4, 5, 6, 6, 6};
    int b = a.size();

    // cout << "The second Largest Element is:" << secondElement(arr1) << endl;
    // cout << "The second Largest Element is:" << secondEle(arr2) << endl;

    cout << "The SecondLargest Ele:" << getlargest(b, a);
    return 0;
}

/*
    Test Cases Added
    3 4 5 2
    4 5 3 6 7
    1 2 3 4 5 6 7 8 9 10
    1 2 3 4 5 6 6 6

*/
