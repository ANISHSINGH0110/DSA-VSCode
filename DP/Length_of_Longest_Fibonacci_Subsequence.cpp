#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int solve(int j,int k,vector<int>&arr,unordered_map<int,int>&mp)
{
    int target = arr[k]-arr[j];
    if(mp.count(target) && mp[target] < j) //i<j<k
    {
        int i= mp[target];
        return solve(i,j,arr,mp)+1;
    }
    return 2;
}
int solveMem(int j,int k,vector<int>&arr,unordered_map<int,int>&mp,vector<vector<int>>&dp)
{
    int target = arr[k]-arr[j];
    if(dp[j][k] != -1)
        return dp[j][k];
    if(mp.count(target) && mp[target] < j) //i<j<k
    {
        int i= mp[target];
        return dp[j][k] = solveMem(i,j,arr,mp,dp)+1;
    }
    return dp[j][k] =2;
}
int lenLongestFibSubseq(vector<int>& arr) {
    // int n = arr.size();
    // unordered_map<int,int>mp;
    // for(int i=0;i<n;i++)
    // {
    //     mp[arr[i]] = i;
    // }
    // int maxLength = 0;
    // for(int j=1;j<n;j++)
    // {
    //     for(int k=j+1;k<n;k++)
    //     {
    //         int length = solve(j,k,arr,mp);
    //         if(length >= 3)
    //         {
    //             maxLength = max(maxLength,length);
    //         }
    //     }
    // }
    // return maxLength;

    int n = arr.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]] = i;
    }
    int maxLength = 0;
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    for(int j=1;j<n;j++)
    {
        for(int k=j+1;k<n;k++)
        {
            int length = solveMem(j,k,arr,mp,dp);
            if(length >= 3)
            {
                maxLength = max(maxLength,length);
            }
        }
    }
    return maxLength;
}
int main()
{
    int n;
    cout << "Number of element in array : " << endl;
    cin >> n;
    vector<int>arr(n);
    cout << "Enter elements of array : " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    cout << "the length of the longest Fibonacci-like subsequence of arr : " << lenLongestFibSubseq(arr) << endl;
    return 0;
}