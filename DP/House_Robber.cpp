#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int>&nums,int i)
    {
       if(i>=nums.size())
         return 0;
       int incl = nums[i] + solve(nums,i+2);
       int excl = 0+solve(nums,i+1);
       int ans = max(incl,excl);
       return ans;  
    }
    int solveMem(vector<int>&nums,int i,vector<int>&dp)
    {
       if(i>=nums.size())
         return 0;
       if(dp[i] != -1)
         return dp[i];  
       int incl = nums[i] + solveMem(nums,i+2,dp);
       int excl = 0+solveMem(nums,i+1,dp);
       dp[i] = max(incl,excl);
       return dp[i];  
    }int solveTab(vector<int>&nums)
    {
       int n = nums.size();
       vector<int>dp(n+2,0);
       //dp[n] = 0;
       for(int i=n-1;i>=0;i--)
       { 
            int incl = nums[i] + dp[i+2];
            int excl = 0+dp[i+1];
            dp[i] = max(incl,excl);
       }    
       return dp[0];  
    }
    int solveSo(vector<int>&nums)
    {
        int n = nums.size();
        int next1 = 0;
        int next2 = 0;
        for(int i=n-1;i>=0;i--)
        {
            int incl = nums[i] + next2;
            int excl = 0 + next1;
            int curr = max(incl,excl);
            //shifting aye bhul jata hu
            next2 = next1;
            next1 = curr;
        }
        return next1;
    }
    int rob(vector<int>& nums) {
        //return solve(nums,0);

        // vector<int>dp(nums.size()+1,-1);
        // return solveMem(nums,0,dp);
        
        //return solveTab(nums);

        return solveSo(nums);
    }
int main()
{
    int n;
    cout <<"Enter the value of n : " << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements of nums : " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }
    cout << "Max amnt is : " << rob(nums) << endl;

    return 0;
}