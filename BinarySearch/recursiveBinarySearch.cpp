#include <bits/stdc++.h>
using namespace std;

int recursiveBinarySearch(vector<int> &arr, int n, int low, int high, int key)
{

    // Base case-1
    // if it is invalvid array or if key is not found
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;

    // Base case-2
    // if arr[mid]==key key found
    if (arr[mid] == key)
    {
        return mid;
    }

    // if given index of mid <key that means element is present on the right side
    if (arr[mid] < key)
    {
        return recursiveBinarySearch(arr, n, mid + 1, high, key);
    }
    // if given index of mid >key that means element is present on the left side
    else
    {
        return recursiveBinarySearch(arr, n, low, mid - 1, key);
    }
}

int main()
{

    vector<int> arr = {10, 20, 30, 40, 80, 90, 99};
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int key = 9;

    int ans = recursiveBinarySearch(arr, n, low, high, key);
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