#include <bits/stdc++.h>
using namespace std;

// Brute Approach
/*
Approach:
1.Traverse the given array and check if any element is zero ,if the element is zero then make the entire row and entire col zero.
2.There is a catch over here instead of making entire row or col zero we will make the non-zero element as -1

Time Complexity:-O(N*M)*(N+M)+O(N*M)
1st O(N*M) is for traversing and check for the zero
2nd O(N+M) for making col and row non-zero to -1
3rd O(N*M) is for again all -1 into zero
*/

void markrow(vector<vector<int>> &matrix, int n, int m, int i)
{
    // set all non zero element as -1 in row i
    for (int j = 0; j < m; j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>> &matrix, int n, int m, int j)
{
    // set all non zero element as -1 in col j
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
    // set -1 for the rows and col having 0,don't mark 0 as -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                markrow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    // mark all the element in the matrix who is -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

/*
Better Approach:
The earlier Brute approach was taking near about O(n^3) complexity ,so we have think some What near about O(n^2).
So the main reason of getting O(n^3) as the solution is that we were again iterating over the entire row and entire col for marking it'-1'.
Instead of that we can take an row array of n size & a col array of m size to keep a track wether it contain zero or not ,but we have to initalized both the array to {0};

Time Complexity:-O(2*N*M)
space complexity:O(N)+O(M)

*/

vector<vector<int>> betterApproach(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    // Keeping the track whether if an element contain zero or not

    int row[n] = {0};
    int col[m] = {0};

    // Traversing the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                // mark ith index of the row 1;
                row[i] = 1;
                // mark jth index of the col 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j])
            {
                mat[i][j] = 0;
            }
        }
    }
    return mat;
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> ans = zeroMatrix(matrix, n, m);
    cout << "After making zero :" << endl;
    for (auto ele : ans)
    {
        for (auto it : ele)
        {
            cout << it << " ";
        }
        cout << "\n";
    }

    // Better Approach

    vector<vector<int>> mat = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 0, 1}};
    vector<vector<int>> ans1 = betterApproach(mat);
    cout << "The Final matrix is :" << endl;
    for (auto ele : ans1)
    {
        for (auto it : ele)
        {
            cout << it << " ";
        }
        cout << "\n";
    }

    return 0;
}