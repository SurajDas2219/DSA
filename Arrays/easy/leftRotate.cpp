#include <bits/stdc++.h>
using namespace std;

// Left Rotate ElementBy K Places
/*
Problem statement:Given an array of integers, rotating array of elements by k elements left.

Example 1:
Input: N = 6, array[] = {3,7,8,9,10,11} , k=3 , left
Output: 9 10 11 3 7 8
Explanation: Array is rotated to right by 3 position.

*/

// Brute Approach:

// Approches:
/*
    --1.Create a temp vector and store the element for 1st element of n array till k-1th elememt
    --2.This can be done by take for loop which will run form i=0 till i< k.
    --3.the remaining element in an array must be left shifted by k places
    --4.replace back all the element from temp to arr.

    Time Complexity: O(n)

    Space Complexity: O(k) since k array element needs to be stored in temp array

 */

void leftRotate(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n == 0)
        return;
    k = k % n;
    if (k > n)
        return;
    int temp[k];
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = 0; i < n - k; i++)
    {
        arr[i] = arr[i + k];
    }
    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - n + k];
    }
}

// Optimal Approach: Using "Reversal Algorithm"
/*
Approach:
    For Rotating Elements to left
    Step 1: Reverse the first k elements of the array

    Step 2: Reverse the last n-k elements of the array.

    Step 3: Reverse the whole array.

    Time Complexity – O(N) where N is the number of elements in an array

    Space Complexity – O(1) since no extra space is required

 */

void Reverse(int brr[], int start, int end)
{
    while (start <= end)
    {
        int temp = brr[start];
        brr[start] = brr[end];
        brr[end] = temp;
        start++;
        end--;
    }
}

void Rotateeletoleft(int brr[], int n, int k)
{
    // Reverse first k elements
    Reverse(brr, 0, k - 1);
    // Reverse last n-k elements
    Reverse(brr, k, n - 1);
    // Reverse whole array
    Reverse(brr, 0, n - 1);
}

int main()
{

    vector<int> arr = {7, 5, 2, 11, 2, 43, 1, 1};
    int k = 2;
    // leftRotate(arr, k);
    //  for (int i = 0; i < arr.size(); i++)
    //  {
    //      cout << arr[i] << " ";
    //  }

    int brr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int m = 2;
    Rotateeletoleft(brr, n, m);
    cout << "After Rotating the k elements to left ";
    for (int i = 0; i < n; i++)
        cout << brr[i] << " ";
}

/*
    test cases

    5 6 7 8
    k=3


*/