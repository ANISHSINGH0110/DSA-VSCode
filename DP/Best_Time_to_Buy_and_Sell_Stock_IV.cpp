#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <algorithm>
using namespace std;

int solve(vector<int>&prices,int i,bool buy,int limit)
    {
        if(i >= prices.size() || limit == 0)
          return 0;
        int profit = 0;
        if(buy)
        {
            int buyProfit = -prices[i] + solve(prices,i+1,0,limit);
            int skipProfit = solve(prices,i+1,1,limit);
            profit = max(buyProfit,skipProfit);
        }  
        else
        {
            int sellProfit = prices[i] + solve(prices,i+1,1,limit-1);
            int skipProfit = solve(prices,i+1,0,limit);
            profit = max(sellProfit,skipProfit);
        }
        return profit;
    }
    int solveMem(vector<int>&prices,int i,bool buy,int limit,vector<vector<vector<int>>>&dp)
    {
        if(i >= prices.size() || limit == 0)
          return 0;
        int profit = 0;
        if(dp[i][buy][limit] != -1)
          return dp[i][buy][limit];
        if(buy)
        {
            int buyProfit = -prices[i] + solveMem(prices,i+1,0,limit,dp);
            int skipProfit = solveMem(prices,i+1,1,limit,dp);
            profit = max(buyProfit,skipProfit);
        }  
        else
        {
            int sellProfit = prices[i] + solveMem(prices,i+1,1,limit-1,dp);
            int skipProfit = solveMem(prices,i+1,0,limit,dp);
            profit = max(sellProfit,skipProfit);
        }
        return dp[i][buy][limit] = profit;
    }
    int solveTab(vector<int>&prices,int k)
    {
      vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,0)));

        for(int i=prices.size()-1;i>=0;i--)
        {
            for(int buy = 0;buy<2;buy++)
            {
                for(int limit = 1;limit<=k;limit++){
                    int profit = 0;
                    if(buy)
                    {
                        int buyProfit = -prices[i] + dp[i+1][0][limit];
                        int skipProfit = dp[i+1][1][limit];
                        profit = max(buyProfit,skipProfit);
                    }  
                    else
                    {
                        int sellProfit = prices[i] + dp[i+1][1][limit-1];
                        int skipProfit = dp[i+1][0][limit];
                        profit = max(sellProfit,skipProfit);
                    }
                    dp[i][buy][limit] = profit;
                }    
            }
        }
        return dp[0][1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        //return solve(prices,0,true,k);

        // vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return solveMem(prices,0,true,k,dp);

        return solveTab(prices,k);
    }
    int main()
{
    vector<int>prices = {3,2,6,5,0,3};
    int k = 2;
    cout << "the maximum profit you can achieve. You may complete at most k transactions : " << maxProfit(k,prices) << endl;

    return 0;
}