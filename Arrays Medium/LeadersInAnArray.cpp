#include <bits/stdc++.h>
using namespace std;

// Leaders in an arrays
/*Problem statement:-Given an array find the leaders in an array.
Leader ia an element who is greater than all the element presents on its right of the array

for Expample No:1
i/p: a[]={10,12,3,1,0}
o/p:leaders={12,3,1,0}
*/

// Naive Approach:
/*
1.we going to use nested loop ,the outer loops picks an element n the inner loop check for the element greater then the current element
2.if there is an element greater than current element then the current element cant be consider as the leader.
3.We have to store all the leader in seperate vector

Time Complexity:O(N^2);
space Complextiy:O(N);
*/
vector<int> leadersInAnArray(vector<int> &element)
{
    int n = element.size();
    vector<int> leaders;
    for (int i = 0; i < n; i++)
    {
        bool leader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (element[j] > element[i])
            {
                leader = false;
                break;
            }
        }
        if (leader == true)
        {
            leaders.push_back(element[i]);
        }
    }
    return leaders;
}

// Optimal Appoach:
/*
1.if we carefully observe that the right most element i.e the last element is always a part of leader
2.So let do back iteration
3.intialize maxi=INT_MIN

Time Complexity:O(N);
space Complextiy:O(N);

*/

vector<int> optimal(vector<int> &element)
{
    int n = element.size();
    vector<int> ans;
    int maxi = INT_MIN;
    // back iteration
    for (int i = n - 1; i >= 0; i--)
    {
        if (element[i] > maxi)
        {
            maxi = element[i];
            ans.push_back(element[i]);
        }
    }
    return ans;
}

int main()
{

    vector<int> element = {10, 12, 3, 1, 0};
    int size = element.size();
    // vector<int>ans=leadersInAnArray(element);
    vector<int> ans = optimal(element);
    cout << "The Leader in an array are {";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << "}";

    return 0;
}