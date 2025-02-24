#include <iostream>
#include <vector>
using namespace std;
int solve(int n,int k)
    {
        if(n == 1)
          return k;
        if(n == 2)
          return (k+ k*(k-1));
        int ans = (k-1) *(solve(n-1,k) + solve(n-2,k));
        return ans;
    }
    int solveMem(int n,int k,vector<int>&dp)
    {
        if(n == 1)
          return k;
        if(n == 2)
          return (k+ k*(k-1));
        if(dp[n] != -1)
          return dp[n];
        dp[n] = (k-1) *(solveMem(n-1,k,dp) + solveMem(n-2,k,dp));
        return dp[n];
    }
    int solveTab(int n,int k)
    {
        vector<int>dp(n+1,0);
        dp[1] = k;
        dp[2] = k+(k*(k-1));
        for(int i=3;i<=n;i++)
        {
            int ans = (k-1) * (dp[i-1] +dp[i-2]);
            dp[i] = ans;
        }
        return dp[n];
    }
    int countWays(int n, int k) {
        // code here
        //return solve(n,k);
        
        // vector<int>dp(n+1,-1);
        // return solveMem(n,k,dp);
        
        return solveTab(n,k);
    }

int main()
{
    int n,k;
    cout <<"Enter the value of n : " << endl;
    cin >> n;
    cout << "enter the value of k : " << endl;
    cin >> k;
    cout << "Count way is : " << countWays(n,k) << endl;

    return 0;
}