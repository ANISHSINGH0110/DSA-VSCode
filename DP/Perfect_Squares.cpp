#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;
int solve(int n)
{
    if(n <= 0)
      return 0;
    
    int ans = INT_MAX;
    int end = sqrt(n);
    int i=1;
    while(i<=end)
    {
        int perfectSquare = i*i;
        int noOfPerfectSquare = 1 + solve(n-perfectSquare);
        if(noOfPerfectSquare < ans)
           ans = noOfPerfectSquare;
        i++;   
    }
   
   return ans;
}
int solveMemo(int n,vector<int>&dp)
{
    if(n <= 0)
      return 0;
    if(dp[n] != -1)
      return dp[n];
    int ans = INT_MAX;
    int end = sqrt(n);
    int i=1;
    while(i<=end)
    {
        int perfectSquare = i*i;
        int noOfPerfectSquare = 1 + solveMemo(n-perfectSquare,dp);
        if(noOfPerfectSquare < ans)
           ans = noOfPerfectSquare;
        i++;   
    }
    dp[n] = ans;
    return dp[n];
}
int solveTab(int n)
{
    vector<int>dp(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int ans = INT_MAX;
        int end = sqrt(i);
        int start=1;
        while(start<=end)
        {
            int perfectSquare = start*start;
            int noOfPerfectSquare = 1 + dp[i-perfectSquare];
            if(noOfPerfectSquare < ans)
             ans = noOfPerfectSquare;
            start++;   
        }
        dp[i] = ans;
    }
    return dp[n];
}
int numSquares(int n) {
   // return solve(n);

//    vector<int>dp(n+1,-1);
//    return solveMemo(n,dp);

   return solveTab(n);
}
int main()
{
    int n;
    cout << "Enter the value of n : " <<endl;
    cin >> n;
    cout << "least number of perfect square numbers that sum to n : " << numSquares(n) << endl;

    return 0;
}