#include <iostream>
#include <vector>

using namespace std;
void findSubsequences(vector<int>& nums, vector<int>& temp, int index) {
    if (temp.size() > 1) {  // Print only non-empty subsequences of length > 1
        for (int num : temp) cout << num << " ";
        cout << endl;
    }

    for (int i = index; i < nums.size(); i++) {
        if (temp.empty() || nums[i] > temp.back()) {
            temp.push_back(nums[i]);       // Include the current element
            findSubsequences(nums, temp, i + 1); // Recur for the next elements
            temp.pop_back();               // Backtrack to remove the last element
        }
    }
}

void printAllIncreasingSubsequences(vector<int>& nums) {
    vector<int> temp;  // Temporary vector to store subsequence
    findSubsequences(nums, temp, 0);
}
int solve(vector<int>&nums,int last,int i)
{
    if(i>=nums.size())
      return 0;
    int curr = nums[i];
    int incl =0;
    if(curr > last)
      incl = 1+solve(nums,nums[i],i+1);
    int excl = 0+solve(nums,last,i+1);
    return max(incl,excl);    
}
int solveMem(vector<int>&nums,int lastI,int i,vector<vector<int>>&dp)
{
    if(i>=nums.size())
      return 0;
    if(dp[lastI+1][i] != -1)
      return dp[lastI+1][i];  
    int curr = nums[i];
    int incl =0;
    if(lastI == -1 || curr > nums[lastI])
      incl = 1+solveMem(nums,i,i+1,dp);
    int excl = 0+solveMem(nums,lastI,i+1,dp);
    dp[lastI+1][i] = max(incl,excl);
    return dp[lastI+1][i];    
}
int solveTab(vector<int>&nums)
{
    int n = nums.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    for(int curr = n-1;curr>=0;curr--)
    {
        for(int prev = curr-1;prev>= -1;prev--)
        {
            int incl = 0;
            if(prev == -1 || nums[curr] >nums[prev])
            {
                incl = 1+dp[curr+1][curr+1];
            }
            int excl = 0+dp[curr+1][prev+1];
            dp[curr][prev+1] = max(incl,excl);

        }
    }
   return dp[0][0];
}
int lengthOfLIS(vector<int>& nums) {
    //int last = INT_MIN;
//    return solve(nums,last,0); 
    
    //  vector<vector<int>>dp(nums.size()+2,vector<int>(nums.size()+1,-1));
     //return solveMem(nums,-1,0,dp);

    // return solveTab(nums);

       //DP + binarySearch TC = O(nlog(n))
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] > ans.back())
              ans.push_back(nums[i]);
            else{
                //find just bda elemnt index 
                auto it = lower_bound(ans.begin(),ans.end(),nums[i]);
                int index = it-ans.begin();
                ans[index] = nums[i];
            }  
        }
        return ans.size();
}
int main()
{
    // int n;
    // cout <<"Enter the value of n : " << endl;
    // cin >> n;
    // vector<int>nums(n);
    // cout << "Enter the elements of nums : " << endl;
    // for(int i=0;i<n;i++)
    // {
    //     cin >> nums[i];
    // }
    vector<int>nums = {10,9,2,5,3,7,101,18};
    cout << "Ans is " << lengthOfLIS(nums) << endl;
    //printAllIncreasingSubsequences(nums);

    return 0;
}