#include <bits/stdc++.h>
using namespace std;

// Find the nth fibonacci number

int fibonacci(int n)
{

    // Base Case

    if (n <= 1)
    {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{

    int n;
    cout << "Enter the number :" << endl;
    cin >> n;
    cout << n << "th fibonacci number is: " << fibonacci(n - 1);

    return 0;
}
