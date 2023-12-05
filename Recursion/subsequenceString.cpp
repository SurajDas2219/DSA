#include <bits/stdc++.h>
using namespace std;

// Print the subsequence of string
/*
    Given a string s, a subsequence of s is any string that can be obtained by deleting zero or more characters from s without changing the order of the remaining characters.

 */
/*
    In general, for a string of length n, there are 2^N possible subsequences, including the empty string and the original string.

    It's important to note that a substring is different from a subsequence. A substring is a contiguous sequence of characters from the original string, while a subsequence can have gaps between selected characters.
*/

void printAllSubsequence(string &str, string output, int i, vector<string> &ans)
{

    // Base Case
    if (i >= str.length())
    {
        // cout << output << endl;
        ans.push_back(output);
        return;
    }

    // including
    printAllSubsequence(str, output + str[i], i + 1, ans);

    // excluding
    printAllSubsequence(str, output, i + 1, ans);
}

int main()
{

    string str = "abc";
    string output = " ";
    int i = 0;
    vector<string> ans;
    cout << "All subsequence of the " << str << " are" << endl;
    printAllSubsequence(str, output, i, ans);

    // storing an subsequence in a vector
    for (auto sub : ans)
    {
        cout << sub << " ";
    }

    cout << endl
         << "The no of subsequence stored in an vector are: " << ans.size() << endl;

    return 0;
}

/*
    Output:
    All subsequence of the abc are
    abc
    ab
    ac
    a
    bc
    b
    c

    storing an subsequence in a vector
    All subsequence of the abc are
    abc  ab  ac  a  bc  b  c
    The no of subsequence stored in an vector are: 8


*/