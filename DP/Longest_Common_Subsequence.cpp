#include <iostream>
#include <string>
#include<vector>
using namespace std;
int solve(string text1, string text2,int i,int j)
{
    if(i >= text1.size())
        return 0;
    if(j >= text2.size())
        return 0;
    int ans = 0;
    if(text1[i] == text2[j])
        ans = 1+solve(text1,text2,i+1,j+1);
    else
        ans = 0+max(solve(text1,text2,i+1,j),solve(text1,text2,i,j+1));
    return ans;         
}
int solveMem(string &text1, string &text2,int i,int j,vector<vector<int>>&dp)
{
    if(i >= text1.size())
        return 0;
    if(j >= text2.size())
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];  
    int ans = 0;
    if(text1[i] == text2[j])
        ans = 1+solveMem(text1,text2,i+1,j+1,dp);
    else
        ans = 0+max(solveMem(text1,text2,i+1,j,dp),solveMem(text1,text2,i,j+1,dp));
    dp[i][j] = ans; 
    return dp[i][j];        
}
int solveTab(string &text1, string &text2)
{
    vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
    for(int i=text1.size()-1;i>=0;i--)
    {
        for(int j=text2.size()-1;j>=0;j--)
        {
            int ans = 0;
            if(text1[i] == text2[j])
            ans = 1+ dp[i+1][j+1];
            else
            ans = 0+max(dp[i+1][j],dp[i][j+1]);
            dp[i][j] = ans; 
        }
    }
    return dp[0][0];
}
int longestCommonSubsequence(string text1, string text2) {
    //return solve(text1,text2,0,0);

    // vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
    // return solveMem(text1,text2,0,0,dp);

    return solveTab(text1,text2);
}
int main()
{
    string st1 = "abcde";
    string st2 = "ace";

    cout <<"Longest Common Subsequence is : " << longestCommonSubsequence(st1,st2) << endl;
 
    return 0;
}