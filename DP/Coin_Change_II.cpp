#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int solve(int amount, std::vector<int>& coins, int index) {
    if (amount == 0) 
      return 1;
    if (index >= coins.size() || amount < 0) 
      return 0;
    int include = solve(amount - coins[index], coins, index);
    int exclude = solve(amount, coins, index + 1);

    return include + exclude;
}
int solveMem(int amount,vector<int>&coins,int i,vector<vector<int>>&dp)
{
   if (amount == 0) 
      return 1;
    if (i >= coins.size() || amount < 0) 
      return 0;
    if(dp[i][amount] != -1)
      return dp[i][amount];  
    int include = solveMem(amount - coins[i], coins, i,dp);
    int exclude = solveMem(amount, coins, i + 1,dp);

    return dp[i][amount] = include + exclude;
}
unsigned long long solveTab(vector<int>&coins,int amount)
{
    int n = coins.size();
    vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount + 1, 0));
    for (int amt = 0; amt <= amount; amt++) {
        dp[0][amt] = (amt % coins[0] == 0) ? 1 : 0;
    }
    for (int i = 1; i < n; i++) {  
        for (int amt = 0; amt <= amount; amt++) {
            unsigned long long include = (amt >= coins[i]) ? dp[i][amt - coins[i]] : 0;
            unsigned long long exclude = dp[i - 1][amt];  
            dp[i][amt] = include + exclude;
        }
    }

    return dp[n - 1][amount]; 
}
int change(int amount, vector<int>& coins) {
    // int ans = solve(amount,coins,0);
    // if(ans == INT_MAX)
    //   return 0;
    // return ans;  
    
    // vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
    // int ans = solveMem(amount,coins,0,dp);
    // if(ans == INT_MAX)
    //   return 0;
    // return ans;

    

    return solveTab(coins,amount);
}
int main()
{
    vector<int>nums = {3,5,7,8,9,10,11};
    int amt = 500;
    cout << "the number of combinations that make up that amount : " << change(amt,nums) << endl;

    return 0;
}