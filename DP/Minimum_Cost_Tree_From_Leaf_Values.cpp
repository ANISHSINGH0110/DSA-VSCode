#include <iostream>
#include <vector>
#include <limits.h>
#include <map>
using namespace std;
int solve(vector<int>&arr,map<pair<int,int>,int>&maxi,int s,int e)
    {
        if(s >= e)
          return 0;
        int ans = INT_MAX;
        for(int i=s;i<e;i++)
        {
            int leftSubTreeMax = maxi[{s,i}];
            int rightSubTreeMax = maxi[{i+1,e}];
            int currRoot = leftSubTreeMax * rightSubTreeMax;
            ans = min(ans,currRoot+solve(arr,maxi,s,i) + solve(arr,maxi,i+1,e));
        }  
        return ans;

    }
    int solveMem(vector<int>&arr,map<pair<int,int>,int>&maxi,int s,int e,vector<vector<int>>&dp)
    {
        if(s >= e)
          return 0;
        if(dp[s][e] != -1)
          return dp[s][e];  
        int ans = INT_MAX;
        for(int i=s;i<e;i++)
        {
            int leftSubTreeMax = maxi[{s,i}];
            int rightSubTreeMax = maxi[{i+1,e}];
            int currRoot = leftSubTreeMax * rightSubTreeMax;
            ans = min(ans,currRoot+solveMem(arr,maxi,s,i,dp) + solveMem(arr,maxi,i+1,e,dp));
        }  
        dp[s][e] = ans;
        return dp[s][e];
    }
    int solveTab(vector<int>&arr,map<pair<int,int>,int>&maxi)
    {
        vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+1,0));
        for(int s=arr.size()-1;s>=0;s--)
        {
            for(int e = 0;e<arr.size();e++)
            {
                if(s>=e)
                  continue;
                else
                {  
                    int ans = INT_MAX;
                    for(int i=s;i<e;i++)
                    {
                        int leftSubTreeMax = maxi[{s,i}];
                        int rightSubTreeMax = maxi[{i+1,e}];
                        int currRoot = leftSubTreeMax * rightSubTreeMax;
                        ans = min(ans,currRoot+ dp[s][i] + dp[i+1][e]);
                    }  
                    dp[s][e] = ans;
                }   
            }
        }
        return dp[0][arr.size()-1];
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int>maxi;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(i == j)
                  maxi[{i,j}] = arr[j];//single element
                else
                {
                    maxi[{i,j}] = max(maxi[{i,j-1}],arr[j]);
                }
                    
            }
        }
        int s=0;
        int e = n-1;
       // return solve(arr,maxi,s,e);

    //    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //    return solveMem(arr,maxi,s,e,dp);

        return solveTab(arr,maxi);
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
    cout << "Minimum Cost tree from leaf values is : " << mctFromLeafValues(nums) << endl;

    return 0;
}