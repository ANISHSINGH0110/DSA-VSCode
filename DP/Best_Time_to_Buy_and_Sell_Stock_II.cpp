#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <algorithm>
using namespace std;
int solve(vector<int>&prices,int i,bool buy)
{
    if(i >= prices.size())
        return 0;
    int profit = 0;
    if(buy)
    {
        int buyProfit = -prices[i] + solve(prices,i+1,0);
        int skipProfit = solve(prices,i+1,1);
        profit = max(buyProfit,skipProfit);
    }  
    else
    {
        int sellProfit = prices[i] + solve(prices,i+1,1);
        int skipProfit = solve(prices,i+1,0);
        profit = max(sellProfit,skipProfit);
    }
    return profit;
}
int solveMem(vector<int>&prices,int i,bool buy,vector<vector<int>>&dp)
{
    if(i >= prices.size())
        return 0;
    int profit = 0;
    if(dp[i][buy] != -1)
        return dp[i][buy];
    if(buy)
    {
        int buyProfit = -prices[i] + solveMem(prices,i+1,0,dp);
        int skipProfit = solveMem(prices,i+1,1,dp);
        profit = max(buyProfit,skipProfit);
    }  
    else
    {
        int sellProfit = prices[i] + solveMem(prices,i+1,1,dp);
        int skipProfit = solveMem(prices,i+1,0,dp);
        profit = max(sellProfit,skipProfit);
    }
    return dp[i][buy] = profit;
}
int solveTab(vector<int>&prices)
{
    vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
    for(int i=prices.size()-1;i>=0;i--)
    {
        for(int buy = 0;buy<2;buy++)
        {
            int profit = 0;
            if(buy)
            {
                int buyProfit = -prices[i] + dp[i+1][0];
                int skipProfit = dp[i+1][1];
                profit = max(buyProfit,skipProfit);
            }  
            else
            {
                int sellProfit = prices[i] + dp[i+1][1];
                int skipProfit = dp[i+1][0];
                profit = max(sellProfit,skipProfit);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}
int maxProfit(vector<int>& prices) {
    //return solve(prices,0,true);

    // vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
    // return solveMem(prices,0,true,dp);

    return solveTab(prices);
}
int main()
{
    vector<int>prices = {1,2,3,4,5};
    cout << "the maximum profit you can achieve : " << maxProfit(prices) << endl;

    return 0;
}