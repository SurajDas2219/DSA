#include <bits/stdc++.h>
using namespace std;

int iterativeBinarySearch(vector<int> &arr, int n, int low, int high, int key)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{

    vector<int> arr = {10, 20, 30, 40, 80, 90, 99};
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int key = 99;

    int ans = iterativeBinarySearch(arr, n, low, high, key);
    if (ans == -1)
    {
        cout << "Key not present";
    }
    else
    {
        cout << "The given key Element is Present at index: " << ans << endl;
    }

    return 0;
}