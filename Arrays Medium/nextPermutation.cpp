#include <bits/stdc++.h>
using namespace std;
// Find the lexicographically next permutation
/* Problem Statement:Given an array,rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).

for Example No 1:
i/p:arr[]=[1,2,3]
o/p:arr[]=[1,3,2];
Explanation:the permutation of 1,2,3 are
(1,2,3);(1,3,2);(2,1,3);(2,3,1);(3,1,2);(3,2,1)
Therefore the next greater permuttion of number(1,2,3) is (1,3,2)

Example No 2:
i/p:arr[]={3,2,1};
o/p:arr[]={1,2,3};
Explanation:Since (3,2,1) is the last permutation of no (1,2,3) therefore the next lexicographically greater permutation is the sorted arr itself.
*/

// Naive Approach:
/*
1.Generating all permutation that probably  done recusion recursion.
2.Then doing the linear search on all permutation.
3.Printing the next permutation after that number.

Time complexity:O(N!*N),that probably generating all permutation of size N will take time of N! and O(N) for finding the number

Space complxity:O(1) we are using the stack space for the recursion call
*/

// Better approach:By using c++ stl

// next_permutation(arr.begin(),arr.end());

// Optimal Approach:By implementing the std:
vector<int> nextPermutation(vector<int> &arr)
{
    int n = arr.size();
    int ind = -1;
    // Finding the break point
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            ind = i;
            break;
        }
    }

    // If we didnt find the break point that means its the last permutation n we have to return it in sorted order
    if (ind == -1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    // if found the break-point swap the element present at the ind with the someone who is the greatest but the smallest one
    for (int i = n - 1; i > ind; i--)
    {
        if (arr[i] > arr[ind])
        {
            swap(arr[i], arr[ind]);
            break;
        }
    }
    // for(int i=0;i<n;i++){
    //   cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    // now then reverse the part after the swapping element
    reverse(arr.begin() + ind + 1, arr.end());
    return arr;
}

// Time complexity :
/*
The first loop iterates through the array once, which has a time complexity of O(n), where n is the size of the input array.
The second loop also iterates through the array once, but it starts from the end and iterates until it finds the first element greater than the element at the breakpoint. In the worst case, it could also iterate through the entire array, leading to O(n) time complexity.
Reversing the elements after the breakpoint can also be done in O(n) time.
Overall, the time complexity is O(n).
*/
// space complexity:O(1);

int main()
{

    vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
    int size = arr.size();
    vector<int> ans = nextPermutation(arr);
    cout << "The Next Permutation is { ";
    for (auto it : ans)
    {
        cout << it << ",";
    }
    cout << " }";

    return 0;
}