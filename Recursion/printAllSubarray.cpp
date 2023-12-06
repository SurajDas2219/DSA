#include <bits/stdc++.h>
using namespace std;

// Printing All SubArray Using Recursion

void printSubArray(vector<int> &arr, int start, int end)
{

    // Base Case
    if (end == arr.size())
    {
        return;
    }

    // ek case
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    printSubArray(arr, start, end + 1);
}

void printAll(vector<int> &arr)
{
    for (int start = 0; start < arr.size(); start++)
    {
        int end = start;
        printSubArray(arr, start, end);
    }
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    printAll(arr);

    return 0;
}

/*
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
2
2 3
2 3 4
2 3 4 5
3
3 4
3 4 5
4
4 5
5
*/