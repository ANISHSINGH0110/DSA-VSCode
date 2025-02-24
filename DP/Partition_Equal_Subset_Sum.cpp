#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
bool solve(vector<int>&nums,int target,int i)
{
    if(target < 0 || i==nums.size())
      return false;
    if(target == 0)
      return true;
    bool incl = solve(nums,target-nums[i],i+1);
    bool excl = solve(nums,target,i+1);
    return incl || excl;    
}
bool solveMem(vector<int>&nums,int target,int i,vector<vector<int>>&dp)
{
    if(target < 0 || i==nums.size())
      return false;
    if(target == 0)
      return true;
    if(dp[target][i] != -1)
      return dp[target][i];  
    bool incl = solveMem(nums,target-nums[i],i+1,dp);
    bool excl = solveMem(nums,target,i+1,dp);
    dp[target][i] = incl || excl;
    return dp[target][i];    
}
bool solveTab(vector<int>&nums,int target)
{
    int n = nums.size();
    vector<vector<int>>dp(target+1,vector<int>(n+1,0));
    for(int col=0;col<=n;col++)
    {
        dp[0][col] = true;
    }
    for(int t=1;t<=target;t++)
    {
        for(int i=n-1;i>=0;i--)
        {
            bool incl = 0;
            if(t-nums[i] >=0){
              incl = dp[t-nums[i]][i+1];
            }
            bool excl = dp[t][i+1];
            dp[t][i] = incl || excl;
        }
    }
    return dp[target][0];
}
bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(),nums.end(),0);
    if(sum%2 != 0)
      return false;
    int target = sum >> 1;
    //return solve(nums,target,0); 

    // vector<vector<int>>dp(target+1,vector<int>(n+1,-1));
    // return solveMem(nums,target,0,dp); 

    return solveTab(nums,target);
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
    bool ans = canPartition(nums);
    if(ans == true)
      cout << "Possible to partion the array " << endl;
    else
      cout << "Not possible to partion " << endl;  

    return 0;
}