#include <bits/stdc++.h>
using namespace std;

bool LinearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 40;

    bool ans = LinearSearch(arr, n, target);
    if (ans)
    {
        cout << "Target present" << endl;
    }
    else
    {
        cout << "Target not present";
    }

    return 0;
}