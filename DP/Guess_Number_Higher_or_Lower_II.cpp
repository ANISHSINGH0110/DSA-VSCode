#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int solve(int s,int e)
{
    if(s>=e)
        return 0;
    int ans = INT_MAX;
    for(int i=s;i<e;i++)
    {
        ans = min(ans,i+max(solve(i+1,e),solve(s,i-1)));
    }  
    return ans;
}
int solveMem(int s,int e,vector<vector<int>>&dp)
{
    if(s>=e)
        return 0;
    if(dp[s][e] != -1)
        return dp[s][e];  
    int ans = INT_MAX;
    for(int i=s;i<e;i++)
    {
        ans = min(ans,i+max(solveMem(i+1,e,dp),solveMem(s,i-1,dp)));
    }  
    dp[s][e] = ans;
    return dp[s][e];
}
int solveTab(int n)
{
    vector<vector<int>>dp(n+2,vector<int>(n+2,0));
    for(int s=n;s>=0;s--)
    {
        for(int e=1;e<=n;e++)
        {
            if(s>=e)
                continue;
            else
            {
                int ans = INT_MAX;
                for(int i=s;i<e;i++)
                {
                    ans = min(ans,i+max(dp[i+1][e],dp[s][i-1]));
                }  
                dp[s][e] = ans;
            }  
        }
    }
    return dp[1][n];
}
int getMoneyAmount(int n) {
    //return solve(1,n);

    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return solveMem(1,n,dp);
}
int main()
{
    int n;
    cout << "Enter the value of n : " << endl;
    cin >> n;
    cout << "Minimum money needed to win game is : " << getMoneyAmount(n) << endl;


    return 0;
}