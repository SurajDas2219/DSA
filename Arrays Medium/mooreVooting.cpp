#include <bits/stdc++.h>
using namespace std;

// Marjority Element In an Array:
/*
    Given an array find the element that appear more than n/2 times
*/

/*
Approach 1:Brute approach
1.pick one element traverse the entire array and keep the count of the track
2.if the element appears to me >=n/2 then return the element
    Time complexity :O(n^2)
    space complexity:O(1)
*/
int naiveAppForMarjorityElement(vector<int> &arr, int n)
{

    // Intialized a count variable to 0
    int count = 0;
    for (int i = 0; i < n; i++) //->O(N)
    {                           // this loop is to pick one element
        int currentNum = arr[i];
        // this loop run by iterating every elemnt and incrementing the count if it ==current num
        for (int j = 0; j < n; j++) //->O(N)
        {
            if (currentNum == arr[j])
            {
                count++;
            }
        }
        if (count > (n / 2))
        {
            return arr[i];
        }
    }
    return -1;
}

// Approach 2:Better Approach{hashing}
/*
1.create a hash map either ordered or unordered map.
2.As Map store value as {key ,value} pairs,here key is the element and value is the count of the element
*/

int betterAppForMajorityELement(vector<int> &arr, int n)
{
    unordered_map<int, int> count;
    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i]]++;
    }
    for (auto it : count)
    {
        if (it.second > (n / 2))
        {
            return it.first;
        }
    }
    return -1;
}

// Approach 3:-Moore vooting algo
/*
Initialize 2 variables:
Count –  for tracking the count of element
Element – for which element we are counting
Traverse through the given array.
If Count is 0 then store the current element of the array as Element.
If the current element and Element are the same increase the Count by 1.
If they are different decrease the Count by 1.
The integer present in Element should be the result we are expecting

*/

int optimalAppFOrMajorityElement(vector<int> &arr, int n)
{
    int element;
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (count == 0)
        {
            element = arr[i];
            count = 1;
        }
        if (element == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (element == arr[i])
        {
            count1++;
        }
    }
    if (count1 > (n / 2))
    {
        return element;
    }

    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 2, 1, 2, 1, 2, 1, 1, 1};
    int n = arr.size();

    // int ans = naiveAppForMarjorityElement(arr, n);
    // int ans2 = betterAppForMajorityELement(arr, n);
    int ans3 = optimalAppFOrMajorityElement(arr, n);
    if (ans3 == -1)
    {
        cout << "No element found to be the majority element in the given vector." << endl;
    }
    else
    {
        cout << "The element that appears more than n/2 times is:" << ans3;
    }

    return 0;
}