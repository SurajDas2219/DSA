#include <bits/stdc++.h>
using namespace std;

// Longest Succesive sequence in an array
/*Problem statemenet:You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

Example 1:
Input: [100, 200, 1, 3, 2, 4]
Output: 4
Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.

*/

// Naive Approach
/*
1.Select an element find the next successive element .
2.FOr a given x the next successive element will be x+1.
3.Therefore to check whether the next successive element is presnt or not we have to do a linear search
4.we have to initialize cnt=1
*/

bool linearSearch(vector<int> &a, int num)
{
    int n = a.size(); // size of array
    for (int i = 0; i < n; i++)
    {
        if (a[i] == num)
            return true;
    }
    return false;
}
int longestSuccessiveElements(vector<int> &a)
{
    int n = a.size(); // size of array
    int longest = 1;
    // pick a element and search for its
    // consecutive numbers:
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int cnt = 1;
        // search for consecutive numbers
        // using linear search:
        while (linearSearch(a, x + 1) == true)
        {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}
