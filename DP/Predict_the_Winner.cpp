#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
#include <algorithm>
using namespace std;

int solve(vector<int>&nums,int start,int end)
{
    if(start == end)
        return nums[start];
    int diffBySt = nums[start] - solve(nums,start+1,end);
    int diffByEnd = nums[end] - solve(nums,start,end-1);
    return max(diffBySt,diffByEnd);  
}
int solveMem(vector<int>&nums,int start,int end,vector<vector<int>>&dp)
{
    if(start == end)
        return nums[start];
    if(dp[start][end] != -1)
        return dp[start][end];  
    int diffBySt = nums[start] - solveMem(nums,start+1,end,dp);
    int diffByEnd = nums[end] - solveMem(nums,start,end-1,dp);
    return dp[start][end] = max(diffBySt,diffByEnd);  
}
int solveTab(vector<int>&nums)
{    int n = nums.size();
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));
    // Initialize the dp array for single elements
    for (int i = 0; i < n; ++i) {
        dp[i][i] = nums[i];
    }

    // Fill dp for subarrays of increasing lengths
    for (int length = 2; length <= n; ++length) {
        for (int start = 0; start <= n - length; ++start) {
            int end = start + length - 1;
            int diffByStart = nums[start] - dp[start + 1][end];
            int diffByEnd = nums[end] - dp[start][end - 1];
            dp[start][end] = max(diffByStart, diffByEnd);
        }
    }

    return dp[0][n - 1];
}
bool predictTheWinner(vector<int>& nums) {
    //return solve(nums,0,nums.size()-1) >=0; 

//   vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
//   return solveMem(nums,0,nums.size()-1,dp) >=0; 

    return solveTab(nums) >=0;
}
int main()
{

    vector<int>nums = {1,5,233,7};
    cout << "true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true : " << predictTheWinner(nums) << endl;

    return 0;
}