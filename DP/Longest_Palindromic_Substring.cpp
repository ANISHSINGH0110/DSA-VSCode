#include <iostream>
#include <vector>
#include <string>
using namespace std;
int start = 0;
int maxLen = 1;
bool solve(string &s,int i,int j)
{
    if(i>=j)
        return true;
    bool flag = false;
    if(s[i] == s[j])
        flag = solve(s,i+1,j-1);
    if(flag)
    {
        int currLen = j-i+1;
        if(currLen > maxLen)
        {
            maxLen = currLen;
            start = i;
        }
    }   
    return flag;
}
bool solveMem(string &s,int i,int j,vector<vector<int>>&dp)
{
    if(i>=j)
        return true;
    if(dp[i][j] != -1)
        return dp[i][j];  
    bool flag = false;
    if(s[i] == s[j])
        flag = solveMem(s,i+1,j-1,dp);
    if(flag)
    {
        int currLen = j-i+1;
        if(currLen > maxLen)
        {
            maxLen = currLen;
            start = i;
        }
    }   
    dp[i][j] = flag;
    return dp[i][j];
}
string longestPalindrome(string s) {
    // int n = s.size();
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=i;j<n;j++)
    //     {
    //         bool t = solve(s,i,j);
    //     }
    // }
    // return s.substr(start,maxLen);

    int n = s.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            bool t = solveMem(s,i,j,dp);
        }
    }
    return s.substr(start,maxLen);
}
int main()
{
    string s = "babad";
    cout << "the longest palindromic substring in s : " << longestPalindrome(s) << endl;
    return 0;
}