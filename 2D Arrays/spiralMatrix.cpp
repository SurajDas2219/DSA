#include <bits/stdc++.h>
using namespace std;

// Problem Statement:Print matrix in spiral order
/*
{1  2  3  4       {1 2 3 4 8 12 11 10 9 5 6 7}
 5  6  7  8
 9 10 11 12
 }
pattern->right->bottom->left->top


*/

vector<int> spiralMatrix(vector<vector<int>> &matrix)
{

    vector<int> ans;
    int n = matrix.size();
    int m = matrix[0].size();
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    while (top <= bottom && left <= right)
    {
        // right
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;
        // bottom
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            // left
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            // top
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> res = spiralMatrix(matrix);
    for (auto it : res)
    {
        cout << it << " ";
    }

    return 0;
}