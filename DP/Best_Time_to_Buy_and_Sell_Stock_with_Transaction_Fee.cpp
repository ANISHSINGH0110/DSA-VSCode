#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <algorithm>
using namespace std;

int solve(vector<int>&prices,int i,bool buy,int fee)
    {
        if(i >= prices.size())
          return 0;
        int profit = 0;
        if(buy)
        {
            int buyProfit = -prices[i] + solve(prices,i+1,0,fee);
            int skipProfit = solve(prices,i+1,1,fee);
            profit = max(buyProfit,skipProfit);
        }  
        else
        {
            int sellProfit = prices[i]-fee + solve(prices,i+1,1,fee);
            int skipProfit = solve(prices,i+1,0,fee);
            profit = max(sellProfit,skipProfit);
        }
        return profit;
    }
    int solveMem(vector<int>&prices,int i,bool buy,int fee,vector<vector<int>>&dp)
    {
        if(i >= prices.size())
          return 0;
        if(dp[i][buy] != -1)
          return dp[i][buy];  
        int profit = 0;
        if(buy)
        {
            int buyProfit = -prices[i] + solveMem(prices,i+1,0,fee,dp);
            int skipProfit = solveMem(prices,i+1,1,fee,dp);
            profit = max(buyProfit,skipProfit);
        }  
        else
        {
            int sellProfit = prices[i]-fee + solveMem(prices,i+1,1,fee,dp);
            int skipProfit = solveMem(prices,i+1,0,fee,dp);
            profit = max(sellProfit,skipProfit);
        }
        return dp[i][buy] = profit;
    }
    int solveTab(vector<int>&prices,int fee)
    {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        for(int i=prices.size()-1;i>=0;i--)
        {
            for(int buy=0;buy < 2;buy++)
            {
                int profit = 0;
                if(buy)
                {
                    int buyProfit = -prices[i] + solveMem(prices,i+1,0,fee,dp);
                    int skipProfit = solveMem(prices,i+1,1,fee,dp);
                    profit = max(buyProfit,skipProfit);
                }  
                else
                {
                    int sellProfit = prices[i]-fee + solveMem(prices,i+1,1,fee,dp);
                    int skipProfit = solveMem(prices,i+1,0,fee,dp);
                    profit = max(sellProfit,skipProfit);
                }
               dp[i][buy] = profit;
            }
        }
        return dp[0][1];

    }
    int maxProfit(vector<int>& prices, int fee) {
         //return solve(prices,0,true,fee);
        
        // vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        // return solveMem(prices,0,true,fee,dp);

        return solveTab(prices,fee);
        
    }
    int main()
    {
        vector<int>prices = {1,3,7,5,10,3};
        int k = 3;
        cout << "the maximum profit you can achieve. With fee K : " << maxProfit(prices,k) << endl;
    
        return 0;
    }