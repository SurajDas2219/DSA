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

// Better Approach
// Time Complexity =O(nLogn)+O(n);
// Space complexity=O(1);

int longestSuccessiveELement2(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
    {
        return 0;
    }
    // Step 1:Sort the Given array
    sort(arr.begin(), arr.end()); // O(N*logN)
    // create 3 variable
    int longest = 1;
    int cnt = 0;
    int lastNum = INT_MIN;

    // Loop from 1->n
    for (int i = 0; i < n; i++) // O(N)
    {
        // if the lastNum is equal to the (element -1) then increment the count and set the last element as the cuttent element
        if (arr[i] - 1 == lastNum)
        {
            lastNum = arr[i];
            cnt += 1;
        }
        // if arr[i]!=lastNum that means we have found another range of consecutiveness
        else if (arr[i] != lastNum)
        {
            cnt = 1;
            lastNum = arr[i];
        }
        longest = max(cnt, longest);
    }
    return longest;
}

// Optimal Approoach
/*
Time complexity:O(N):-for inserting element in an unordered set(for the worst case if collision occur otherwise its O(1))
and O(2N)for the taversal over the loop since we are not looking for element whose "X-1" element do exist in the set,therefore the no of iteration that we made for checkinhg for consecutiveness is2*N

space complexity :O(N); if all element are unique
*/

int optimalApproach(vector<int> &arr1)
{
    int n = arr1.size();
    int longest = 1;
    // step 1:insert all the element in unordered set
    unordered_set<int> st; // Store only unique elements
    for (int i = 0; i < n; i++)
    {
        st.insert(arr1[i]);
    }
    // step 2:traverse the arr and check if x is the element then
    // 1.if "x-1" element is present in the set then its not the start of the consecutive element so do check further
    // 2.if "x-1" element is not present in the set then the given element x is the starting point of consecutive element;

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            // that means "x-1 " element is not present in the set,its a starting point
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                cnt += 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main()
{
    // Brute
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    // Better
    vector<int> arr = {102, 100, 102, 101, 100, 4, 3, 2, 1, 2, 1, 2, 1, 3, 4};
    int n = arr.size();
    cout << "The Length of the LongestConsecutiveElement is:" << longestSuccessiveELement2(arr);

    cout << endl;
    // Optimal :You can comment out the other function to execute the given function
    vector<int> arr1 = {6, 3, 14, 18, 8, 18, 4, 3, 12, 1, 14, 7, 9, 22, 11, 28, 24, 22, 30, 13, 2, 19, 8, 8, 18, 14, 11, 13, 1};

    cout << "The Length of the LongestConsecutiveElement is:" << optimalApproach(arr1);
    return 0;
}
