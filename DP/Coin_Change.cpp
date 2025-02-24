#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solve(vector<int>&coins,int amount)
{
    if(amount == 0)
      return 0;
    int minCoin = INT_MAX;
    for(int i=0;i<coins.size();i++)
    {
        int coin = coins[i];
        if(coin <= amount)
        {
            int recAns = solve(coins,amount-coin);
            if(recAns != INT_MAX)
            {
                int coinUsed = 1+recAns;
                minCoin = min(minCoin,coinUsed);
            }
        }
    }  
    return minCoin;
}
int solveMem(vector<int>&coins,int amount,vector<int>&dp)
{
    if(amount == 0)
      return 0;
    if(dp[amount] != -1)
      return dp[amount];
    int minCoin = INT_MAX;
    for(int i=0;i<coins.size();i++)
    {
        int coin = coins[i];
        if(coin <= amount)
        {
            int recAns = solveMem(coins,amount-coin,dp);
            if(recAns != INT_MAX)
            {
                int coinUsed = 1+recAns;
                minCoin = min(minCoin,coinUsed);
            }
        }
    }  
    dp[amount] = minCoin;
    return dp[amount];
}
int solveTab(vector<int>&coins,int amount)
{
    vector<int>dp(amount+1,-1);
    dp[0] = 0;
    for(int amt = 1;amt <= amount;amt++)
    {
        int minCoin = INT_MAX;
        for(int i=0;i<coins.size();i++)
        {
            int coin = coins[i];
            if(coin <= amt)
            {
                int recAns = dp[amt-coin];
                if(recAns != INT_MAX)
                {
                    int coinUsed = 1+recAns;
                    minCoin = min(minCoin,coinUsed);
                }
            }
        }  
        dp[amt] = minCoin;
    }
    return dp[amount];
}
int coinChange(vector<int>& coins, int amount) {
    // int ans = solve(coins,amount);
    // if(ans == INT_MAX)
    //   return -1;
    // return ans;  
    
    // vector<int>dp(amount+1,-1);
    // int ans = solveMem(coins,amount,dp);
    // if(ans == INT_MAX)
    //   return -1;
    // return ans;

    int ans = solveTab(coins,amount);
    if(ans == INT_MAX)
      return -1;
    return ans;  
}
int main()
{
    int n;
    cout <<"Enter the value of n : " << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements of coins : " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }
    int amnt;
    cout << "Enter amount : " << endl;
    cin >> amnt;
    cout << "min Coins used is : " << coinChange(nums,amnt) << endl;
    
    return 0;
}