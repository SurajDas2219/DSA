#include <bits/stdc++.h>
using namespace std;

int findFactorial(int n)
{
    // Base Case
    if (n == 1)
    {
        return 1;
    }
    // Rcursive Relation
    return n * findFactorial(n - 1);
}

int main()
{

    int n;
    cout << "Enter the number whose factorial is to be found:" << endl;
    cin >> n;

    int ans = findFactorial(n);
    cout << "The Factorial of " << n << " is " << ans;

    return 0;
}