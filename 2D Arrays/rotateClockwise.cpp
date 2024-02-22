#include <bits/stdc++.h>
using namespace std;

// Problem Statement :Given an N*M matrix ,rotate it 90 degree clockwise.
/*
Example:
Input: [[1,2,3],[4,5,6],[7,8,9]]

Output: [[7,4,1],[8,5,2],[9,6,3]]

Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix.
*/

// Brute Approach:
/*
## Oberservation:
i/p={1 2 3        /   o/p={7 4 1
     4 5 6        /        8 5 2
     7 8 9 }      /        9 6 3}

->The 1st row of i/p has become the last col of the o/p.
->An so on the rotation is been done .
So we have take an dummy array of n*n size and fill the last col of dummy array by 1st row of the i/p.
Similarly ,DO it for the 2nd lat col and so on

Time Complexity:-O(N*N);
space complexity:-O(N*N);

*/

vector<vector<int>> bruteApp(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    vector<vector<int>> rotate(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rotate[j][n - i - 1] = matrix[i][j];
        }
    }
    return rotate;
}

// Optimal Approach:
/*

1st DO the tanspose of the matrix.
2nd Reverse each row of the matrix.

Time Complexity:-O(2*N*N);
space complexity:-O(1);

*/

void optimalApp(vector<vector<int>> &mat)
{
    int n = mat.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> ans1 = bruteApp(matrix);
    cout << "After Rotating matrix at 90 degree ClockWise:" << endl;
    for (auto ele : ans1)
    {
        for (auto it : ele)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    cout << endl;
    // Optimal Approach
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = mat.size();
    int m = mat[0].size();
    optimalApp(mat);
    cout << "After Rotating matrix at 90 degree ClockWise:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}