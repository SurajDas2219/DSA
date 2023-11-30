#include <bits/stdc++.h>
using namespace std;

// Remove Duplicates in-place from Sorted Array
// Problem statement :Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.
// If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.

// Note: Return k after placing the final result in the first k slots of the array.

// Brute Approach:
/*
    UNIQUE ELEMENT:Set data structure!!!!!!!!
    --1. initialize a set data structure
    --2.Iterate over entire array and store the unique elements.
    --3.After storing element in the set replace it into the original array
    --4 return the size i.e K

    Time complexity:O(N*logN)+O(N);
    space complexity :O(N);  what if all element were unique we have to insert all N element


The time complexity for storing elements from an array into a set depends on the underlying implementation of the set. In the case of std::set in C++, it is typically implemented as a self-balancing binary search tree, such as a red-black tree.

Here are the time complexities for common set operations in C++:

Insertion:

Average Case: O(log n)
Worst Case: O(log n)
The average case time complexity is O(log n) because, in a balanced tree, the height is logarithmic with respect to the number of elements. However, due to the self-balancing property, the worst-case time complexity is also O(log n).
*/

int removeDuplicate(vector<int> &arr)
{

    set<int> uniqueContainers;
    for (int i = 0; i < arr.size(); i++) // O(N)
    {
        uniqueContainers.insert(arr[i]); // O(log N)
    }

    // Total time complexity of above loop is O(N*logN);

    int k = uniqueContainers.size();
    int j = 0;
    for (int x : uniqueContainers) // O(N);
    {
        arr[j++] = x;
    }

    return k;
}

// Optimal approach:Two pointer approach

// Approach:
/*
    --1.first element will always be unique so i=0;
    --2.the iterate for j=1 till Nth element in an array n check
    --3.if(arr[j]!=arr[i]) then arr[i+1]=arr[j]; and then increment i;
    --4.then ater iterating return i+1 becouse we have this many of unique element

    time complexity:O(N);
    space complexity:O(1);
 */

int removeDupTwoPointer(vector<int> &brr)
{
    int i = 0;
    for (int j = 1; j < brr.size(); j++)
    {
        if (brr[j] != brr[i])
        {
            brr[i + 1] = brr[j];
            i++;
        }
    }
    return i + 1;
}

int main()
{
    vector<int> arr = {1, 3, 3, 3, 4, 5};
    vector<int> brr = {1, 3, 3, 3, 4, 5};
    int n = arr.size();

    // int k = removeDuplicate(arr);    //For brute
    // for (int i = 0; i < k; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // printing the array ->optimal one
    int k = removeDupTwoPointer(brr);
    for (int i = 0; i < k; i++)
    {
        cout << brr[i] << " ";
    }

    return 0;
}

/*
    Test cases:
    1 2 2 3 3 3 4 4 5 5
    1 1 2 3 3 4 5 5 5
    1 1 1 1 1 2 2 2 4 4
    2 2 2 2 2 3 5 5
    1 3 3 3 4 5



*/