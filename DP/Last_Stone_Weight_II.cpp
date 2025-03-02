#include <iostream>
#include <vector>
#include<numeric>
#include<limits.h>
using namespace std;
int totalSum = 0;
int solve(vector<int>&stone,int i,int sum)
{
    if(i == stone.size())
    {
        if(sum < 0)
            return INT_MAX;
        return sum;  
    }
    int pos = solve(stone,i+1,sum+stone[i]);
    int neg = solve(stone,i+1,sum-stone[i]);
    return min(pos,neg);
}
int solveMem(vector<int>&stone,int i,int sum,vector<vector<int>>&dp)
{
    if(i == stone.size())
    {
        if(sum < 0)
            return INT_MAX;
        return sum;  
    }
    if(dp[i][sum+totalSum] != -1)
        return dp[i][sum+totalSum];
    int pos = solveMem(stone,i+1,sum+stone[i],dp);
    int neg = solveMem(stone,i+1,sum-stone[i],dp);
    return dp[i][sum+totalSum] =  min(pos,neg);
}
int lastStoneWeightII(vector<int>& stones) {
    // return solve(stones,0,0);

    totalSum = accumulate(stones.begin(),stones.end(),0);
    vector<vector<int>>dp(stones.size()+1,vector<int>(2*totalSum+1,-1));
    return solveMem(stones,0,0,dp);
}
int main()
{
    vector<int>stones = {31,26,33,21,40};
    cout << "the smallest possible weight of the left stone. If there are no stones left, return 0 : " << lastStoneWeightII(stones) << endl;

    return 0;
}