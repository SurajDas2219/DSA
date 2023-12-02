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

// Optimal Appraoch

/*
    Approach
    first step
    --1.1st initialize j as -1 and find  where the 1st zero element lies
    --2.This can be done by simply iterating over an array an check if arr[i]==0.
    --3.if it is zero then state j=i and break

    second step
    --1.once we have the first zero element right after that we have to place i
    --2 Then simply check if a[i]!=0 swap arr[i] with arr[j] n increment i

    time complxity :O(N);
    Space Complexity:O(1);

*/

void moveZeroEnd(vector<int> &brr)
{

    // finding where 1st zero lies
    int j = -1;

    for (int i = 0; i < brr.size(); i++)
    {
        if (brr[i] == 0)
        {
            j = i;
            break;
        }
    }
    // placing i right after the j

    for (int i = j + 1; i < brr.size(); i++)
    {
        if (brr[i] != 0)
        {
            swap(brr[i], brr[j]);
            j++;
        }
    }
}
int main()
{

    vector<int> arr = {1, 0, 2, 3, 0, 4, 0, 1};
    int n = arr.size();
    // moveZeroToEnd(arr);
    // cout << "After Moving Zeros to the end:" << endl;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << " ";
    // }

    vector<int> brr = {1, 2, 0, 1, 0, 4, 0};
    int m = brr.size();
    moveZeroEnd(brr);
    cout << "After Moving Zeros to the end:" << endl;
    for (int i = 0; i < brr.size(); i++)
    {
        cout << brr[i] << " ";
    }
}