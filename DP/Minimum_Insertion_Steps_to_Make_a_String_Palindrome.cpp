#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solve(string &a,string &b,int i,int j)
{
    if(i == a.size())
        return 0;
    if(j == b.size())
        return 0;
    int ans = 0;
    if(a[i] == b[j])
        ans = 1 + solve(a,b,i+1,j+1);
    else
        ans = max(solve(a,b,i+1,j) , solve(a,b,i,j+1));
    return ans;        
}
int solveMem(string &a,string &b,int i,int j,vector<vector<int>>&dp)
{
    if(i == a.size())
        return 0;
    if(j == b.size())
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];  
    int ans = 0;
    if(a[i] == b[j])
        ans = 1 + solveMem(a,b,i+1,j+1,dp);
    else
        ans = max(solveMem(a,b,i+1,j,dp) , solveMem(a,b,i,j+1,dp));
    return dp[i][j] = ans;        
}
int solveTab(string &a,string &b)
{
    vector<vector<int>>dp(a.size()+1,vector<int>(a.size()+1,0));
    for(int i=a.size()-1;i>=0;i--)
    {
        for(int j=b.size()-1;j>=0;j--)
        {
            int ans = 0;
            if(a[i] == b[j])
                ans = 1 + solveMem(a,b,i+1,j+1,dp);
            else
                ans = max(solveMem(a,b,i+1,j,dp) , solveMem(a,b,i,j+1,dp));
            dp[i][j] = ans; 
        }
    }
    return dp[0][0];
}
int minInsertions(string s) {
    string reverseStr = s;
    reverse(reverseStr.begin(),reverseStr.end());
    //int LPS_Leng = solve(s,reverseStr,0,0);

    // vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
    // int LPS_Leng = solveMem(s,reverseStr,0,0,dp);

    int LPS_Leng = solveTab(s,reverseStr);
    return s.size()-LPS_Leng;
}
int main()
{
    string s ="fomyxevyghcgdouxvio";
    cout << "the minimum number of steps to make s palindrome : " << minInsertions(s) << endl;

    return 0;
}