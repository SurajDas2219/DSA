#include <bits/stdc++.h>
using namespace std;
/*

    Problem Statement:Given an array ranges from 1 to N both inclusively find the number that appear twice and the number that is missing in an array

*/
// Naive Approach
// Time complexity:O(N^2).
// Space complexity:O(1).

vector<int> findMissingNrepeating(vector<int> &arr, int n)
{
    int missingNumber = -1;
    int repeatingNumber = -1;

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                cnt++;
            }
        }
        if (cnt == 2)
        {
            repeatingNumber = i;
        }
        if (cnt == 0)
        {
            missingNumber = i;
        }
        if (repeatingNumber != -1 && missingNumber != -1)
        {
            break;
        }
    }
    return {missingNumber, repeatingNumber};
}

int main()
{

    vector<int> a = {3, 1, 2, 5, 3};
    int n = a.size();
    vector<int> ans = findMissingNrepeating(a, n);
    cout << "The missing and repeating number in an array are " << ans[0] << " & " << ans[1] << " respectively" << endl;
    return 0;
}