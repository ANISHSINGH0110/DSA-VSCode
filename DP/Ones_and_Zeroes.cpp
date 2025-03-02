#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
#include <algorithm>
using namespace std;
void convertStringToNumber(vector<string>& strs,vector<pair<int,int>>&numStr)
{
    for(auto str:strs)
    {
        int zeroes=0,ones=0;
        for(auto ch : str)
        {
            if(ch == '0')
                zeroes++;
            else
                ones++;  
        }
        numStr.push_back({zeroes,ones});
    }
}
int solve(vector<pair<int,int>>numStr,int i,int m,int n)
{
    if(i == numStr.size())
        return 0;
    int zeroes = numStr[i].first;
    int ones = numStr[i].second;
    int incl = 0,excl = 0;
    if(m-zeroes >=0 && n-ones >= 0)
        incl = 1+solve(numStr,i+1,m-zeroes,n-ones);
    excl = solve(numStr,i+1,m,n);
    return max(incl,excl);    
}
int solveMem(vector<pair<int,int>>&numStr,int i,int m,int n,vector<vector<vector<int>>>&dp)
{
    if(i == numStr.size())
        return 0;
    if(dp[i][m][n] != -1)
        return dp[i][m][n];  
    int zeroes = numStr[i].first;
    int ones = numStr[i].second;
    int incl = 0,excl = 0;
    if(m-zeroes >=0 && n-ones >= 0)
        incl = 1+solveMem(numStr,i+1,m-zeroes,n-ones,dp);
    excl = solveMem(numStr,i+1,m,n,dp);
    return dp[i][m][n] = max(incl,excl);    
}
int solveTab(vector<pair<int,int>>&numStr,int m,int n)
{
    vector<vector<vector<int>>>dp(numStr.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
    for(int i=numStr.size()-1;i>=0;i--)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=n;k++)
            {
                int zeroes = numStr[i].first;
                int ones = numStr[i].second;
                int incl = 0,excl = 0;
                if(m-zeroes >=0 && n-ones >= 0)
                    incl = 1+ dp[i+1][m-zeroes][n-ones];
                excl = dp[i+1][m][n];
                dp[i][m][n] = max(incl,excl);
            }
        }
    }
    return dp[0][m][n];

}
int findMaxForm(vector<string>& strs, int m, int n) {
    vector<pair<int,int>>numStr;//{0's,1's}
    convertStringToNumber(strs,numStr);
    //return solve(numStr,0,m,n);

    vector<vector<vector<int>>>dp(numStr.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
    return solveMem(numStr,0,m,n,dp);
}
int main()
{
    vector<string>strs = {"10","0001","111001","1","0"};
    int m=5,n=3;
    cout << "the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset : " << findMaxForm(strs,m,n) << endl;
    
    return 0;
}