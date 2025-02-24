#include <iostream>
#include <vector>
using namespace std;

long long int MOD = 1000000007;
int solve(int n,int k, int target)
{
    if(n < 0 || target < 0)
        return 0;
    if(n == 0 && target == 0)
        return 1;
    if(n == 0 && target != 0)
        return 0;
    if(n != 0 && target == 0)
        return 0;
    int ans = 0;
    for(int i=1;i<=k;i++)
    {
        ans += solve(n-1,k,target-i);
    }        
    return ans;
}
int solveMemo(int n,int k, int target,vector<vector<long long int>>&dp)
{
    if(n < 0 || target < 0)
        return 0;
    if(n == 0 && target == 0)
        return 1;
    if(n == 0 && target != 0)
        return 0;
    if(n != 0 && target == 0)
        return 0;
    if(dp[n][target] != -1)
        return dp[n][target];
    long long int ans =0;  
    for(int i=1;i<=k;i++)
    {
        ans += solveMemo(n-1,k,target-i,dp);
    }        
    dp[n][target] = ans % MOD;
    return dp[n][target];
}
int solveTab(int n,int k ,int target)
{
    vector<vector<long long int>>dp(n+1,vector<long long int>(target+1,0));
    dp[0][0] = 1;
    for(int N=1;N<=n;N++)
    {
        for(int t=1;t<=target;t++)
        {
            long long int ans =0;  
            for(int i=1;i<=k;i++)
            {
                long long int tempAns = 0;
                if(t-i >=0)
                    tempAns += dp[N-1][t-i];
                ans = (ans%MOD) + (tempAns%MOD);  
            }        
            dp[N][t] = ans % MOD;
        }
    }
    return dp[n][target];

}
int numRollsToTarget(int n, int k, int target) {
    //return solve(n,k,target);

    // vector<vector<long long int>>dp(n+1,vector<long long int>(target+1,-1));
    // return solveMemo(n,k,target,dp);

    return solveTab(n,k,target);

}
int main()
{
    int n,k,target;
    cout << "Enter the value of n : " << endl;
    cin >> n;
    cout << "Enter the value of k : " << endl;
    cin >> k;
    cout << "Enter the value of target :" << endl;
    cin >> target;
    cout << "Number of possible ways : " << numRollsToTarget(n,k,target);

    return 0;
}