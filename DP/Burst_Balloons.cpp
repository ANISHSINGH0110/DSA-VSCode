#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solve(vector<int>&nums,int start,int end)
{
    if(start > end)
      return 0;
    int coins = INT_MIN;
    for(int i=start;i<=end;i++)
    {
        coins = max(coins,nums[start-1]*nums[i]*nums[end+1] 
                  + solve(nums,start,i-1)//left subarray of ith index
                  + solve(nums,i+1,end));//right subarray of ith index
    }  
    return coins;
}
int solveMem(vector<int>&nums,int start,int end,vector<vector<int>>&dp)
{
    if(start > end)
      return 0;
    if(dp[start][end] != -1)
      return dp[start][end];  
    int coins = INT_MIN;
    for(int i=start;i<=end;i++)
    {
        coins = max(coins,nums[start-1]*nums[i]*nums[end+1] 
                  + solveMem(nums,start,i-1,dp)//left subarray of ith index
                  + solveMem(nums,i+1,end,dp));//right subarray of ith index
    }  
    dp[start][end] = coins;
    return dp[start][end];
}
int solveTab(vector<int>&nums)
{
    vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));
    int n = nums.size()-2;
    for(int start=n;start>=1;start--)
    {
        for(int end=start;end<=n;end++)
        {
             int coins = INT_MIN;
            for(int i=start;i<=end;i++)
            {
                coins = max(coins,nums[start-1]*nums[i]*nums[end+1] 
                        + dp[start][i-1]//left subarray of ith index
                        + dp[i+1][end]);//right subarray of ith index
            }  
            dp[start][end] = coins;
        }
    }
    return dp[1][n];
}
int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(),1);
    nums.insert(nums.end(),1);
    //return solve(nums,1,nums.size()-2);

    // vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
    // return solveMem(nums,1,nums.size()-2,dp);
    
    return solveTab(nums);
}
int main()
{

    vector<int>nums = {8,2,6,8,9,8,1,4,1,5,3,0,7,7,0,4,2,2,5};
    cout << "the maximum coins you can collect by bursting the balloons wisely : " << maxCoins(nums) << endl;
    
    return 0;
}