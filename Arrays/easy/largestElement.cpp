// Problem Statement: Given an array, we have to find the largest element in the array.

// Intution 1:By iterating over entire array and checking each element.
/*
Approach:
--1.create a variable largest n initialize it minimum value as INT_MIN or arr[0].
--2.After that we have to iterate over entire array using for loop.
--3.Check for the condition if(max<arr[i]).
--4.If the condition appears to be true then:do Max=arr[i];
*/

// Time Complexity:O(N),where N is the size of an array
// Space Complexity:O(1).
#include <bits/stdc++.h>
using namespace std;
int findLargestElement(vector<int> &arr) // Intution 1
{
    int n = arr.size();
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (largest < arr[i])
        {
            largest = arr[i];
        }
    }
    return largest;
}

// Intution 2:By sorting the entire array and returning n-1 element;
// Approach:
/*
 --1.Using sort algo ,sort the entire array
 --2.return arr[n-1]->largest element.
 */

int findLargestElement1(vector<int> &arr) // Intution 2
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int largest = arr[n - 1];
    return largest;
}

int main()
{

    vector<int> arr = {8, 10, 5, 7, 9};
    int n = arr.size();
    int max = findLargestElement(arr);
    cout << "The largest element in the array is: " << max << endl;
    cout << "The largest element in the array is: " << findLargestElement1(arr) << endl;
    return 0;
}

/*

Test Cases

7 3 8 8 4 3 10 6
4 7 8 6 7 6
5 9 3 4 8 4 3 10
3 9 4 3 8 10 6 5
3 6 4 1 7 5



*/