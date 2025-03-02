#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
#include <algorithm>
using namespace std;
int solve(vector<int>&nums,int target,int i)
{
    if(i==nums.size())
        return target == 0?1:0;
    int plus = solve(nums,target-nums[i],i+1);
    int minus = solve(nums,target+nums[i],i+1);
    return plus+minus;
}
int solveMem(vector<int>&nums,int target,int i,map<pair<int,int>,int>&dp)
{
    if(i==nums.size())
        return target == 0?1:0;
    if(dp.find({i,target}) != dp.end())
        return dp[{i,target}];  
    int plus = solveMem(nums,target-nums[i],i+1,dp);
    int minus = solveMem(nums,target+nums[i],i+1,dp);
    return dp[{i,target}] = plus+minus;
}
int solveTab(vector<int>&nums,int target)
{
    map<pair<int,int>,int>dp;
    dp[{nums.size(),0}] = 1;
    int total = 0;
    for(auto num:nums)
        total +=num;
    for(int i=nums.size()-1;i>=0;--i)
    {
        for(int sum=-total;sum <= total;++sum)
        {
            int plus = dp.find({i+1,sum-nums[i]}) != dp.end() ? dp[{i+1,sum-nums[i]}]:0;
            int minus = dp.find({i+1,sum+nums[i]}) != dp.end() ? dp[{i+1,sum+nums[i]}] : 0;
            dp[{i,sum}] = plus+minus;
        }
    }   
    return dp[{0,target}];

}
int findTargetSumWays(vector<int>& nums, int target) {
    // return solve(nums,target,0);

//    map<pair<int,int>,int>dp;
//    return solveMem(nums,target,0,dp);

    return solveTab(nums,target);
}
int main()
{
    vector<int>nums = {1,1,1,1,1};
    int  target = 3;
    cout <<"the number of different expressions that you can build, which evaluates to target :" << findTargetSumWays(nums,target) << endl;

}