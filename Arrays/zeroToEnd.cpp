#include <bits/stdc++.h>
using namespace std;

// Problem Statement:You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.

/*
    Example 1:
    Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
    Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
    Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order

    Example 2:
    Input: 1,2,0,1,0,4,0
    Output: 1,2,1,4,0,0,0
    Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order

*/

// Brute Approch:-
/*
    Approach
    --1. Store the all non zero element into a temp vector.
    --2. Then copy all the elements i.e non zero's into the original array.
    --3. Then fill remaining spaceses with zero's

    Time complexity =O(2*N);
    Space complexity=O(N);


 */

void moveZeroToEnd(vector<int> &arr)
{

    // Filling all the non-zero
    vector<int> temp;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }

    // copying back the non-zero element to  the front
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i] = temp[i];
    }

    // fill remaining spaceses with zero's

    for (int i = temp.size(); i < arr.size(); i++)
    {
        arr[i] = 0;
    }
}

int main()
{

    vector<int> arr = {1, 0, 2, 3, 0, 4, 0, 1};
    int n = arr.size();
    moveZeroToEnd(arr);
    cout << "After Moving Zeros to the end:" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}