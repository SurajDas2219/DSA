#include <bits/stdc++.h>
using namespace std;

// Rearrange element by sign
// array must start with the positive element
// Approach 1:Brute
void naiveAppRearrange(vector<int> &element, int n)
{
    vector<int> pos, neg;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    { // O(n)
        if (element[i] < 0)
        {
            neg.push_back(element[i]);
        }
        else
        {
            pos.push_back(element[i]);
        }
    }
    // cout<<"Positive array :";
    // for(int i=0;i<pos.size();i++){
    //   cout<<pos[i]<<" ";
    // }

    //   cout<<endl;
    //   cout<<"Negative array :";
    //   for(int i=0;i<neg.size();i++){
    //     cout<<neg[i]<<" ";
    //   }

    //   cout<<endl;

    for (int i = 0; i < (n / 2); i++)
    { // O(n/2)
        element[i * 2] = pos[i];
        element[i * 2 + 1] = neg[i];
    }
}

// Approach 2:
void betterAppForRearrange(vector<int> &element, int n)
{
    vector<int> ans(n, 0);
    int posIndex = 0;
    int negIndex = 1;

    for (int i = 0; i < n; i++)
    { // O(N)
        if (element[i] > 0)
        {
            ans[posIndex] = element[i];
            posIndex += 2;
        }
        else
        {
            ans[negIndex] = element[i];
            negIndex += 2;
        }
    }
}

int main()
{

    vector<int> element = {1, -4, 2, -3, -1, 4, -2, 3};
    int n = element.size();
    // naiveAppRearrange(element, n);
    betterAppForRearrange(element, n);
    cout << "Element after rearranging aternative by sign:";
    for (int i = 0; i < n; i++)
    {
        cout << element[i] << " ";
    }

    return 0;
}