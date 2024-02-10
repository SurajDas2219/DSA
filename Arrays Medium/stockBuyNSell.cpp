#include <bits/stdc++.h>
using namespace std;

// STOCK BUY AND SELL

/*
buying a stock at mini price and selling it such that u gain maxi profit
Note**:-1st we have to buy the stock then only we can sell it


*/

// Approach 1:-Naive Approach

/*
1st gonna buy the stock and check if there is the rise in stock price such that the difference at which i am going to sell should br maximium
    Time complexity=O(n^2);
    Space complexity=O(1);
*/

int naiveAppSell_BuyStock(vector<int> price, int n)
{
    int maxProfit = 0;
    for (int i = 0; i < n; i++) // O(n)
    {
        for (int j = i + 1; j < n; j++) // O(n)
        {
            if (price[j] > price[i])
            {
                maxProfit = max(maxProfit, price[j] - price[i]);
            }
        }
    }
    return maxProfit;
}

// Approach 2:Better Approach
/*
Maintain two variable
mini=INT_MAX
MaxPro=0
traverse entire array n 1st buy it and sell it one same day check if it gives me maximum profit
*/

int betterAppForSellNBuyStock(vector<int> price, int n)
{
    int mini = INT_MAX;
    int maxPro = 0;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, price[i]);
        maxPro = max(maxPro, price[i] - mini);
    }
    return maxPro;
}
int main()
{

    vector<int> price = {7, 1, 5, 3, 6, 4};
    int n = price.size();
    int ans = naiveAppSell_BuyStock(price, n);
    int ans1 = betterAppForSellNBuyStock(price, n);

    if (ans1 == 0)
    {
        cout << "I wont buy my stock,Since there is no profit on selling it on any give days" << endl;
    }
    else
    {
        cout << "You have achieve a MaximumProfit of:" << ans1 << endl;
    }

    return 0;
}