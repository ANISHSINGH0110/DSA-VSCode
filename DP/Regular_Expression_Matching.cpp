#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool solve(string &s,string &p,int i,int j)
{
    if(i>=s.length() && j>=p.length())
        return true;
    if(j >= p.length())
        return false;
    bool currMatch = (i<s.length()) && (p[j] == '.' || s[i] == s[j]);
    if(j+1 < p.length() && p[j+1] == '*')
    {
        bool emptyWala = solve(s,p,i,j+2);
        bool precElemWala = currMatch && solve(s,p,i+1,j);
        return emptyWala || precElemWala;
    }
    else if(currMatch)
        return solve(s,p,i+1,j+1);
    else
        return false;  
}
bool solveMem(string &s,string &p,int i,int j,vector<vector<int>>&dp)
{
    if(i>=s.length() && j>=p.length())
        return true;
    if(j >= p.length())
        return false;
    if(dp[i][j] != -1)
        return dp[i][j];  
    bool currMatch = (i<s.length()) && (p[j] == '.' || s[i] == p[j]);
    bool ans;
    if(j+1 < p.length() && p[j+1] == '*')
    {
        bool emptyWala = solveMem(s,p,i,j+2,dp);
        bool precElemWala = currMatch && solveMem(s,p,i+1,j,dp);
        ans = emptyWala || precElemWala;
    }
    else if(currMatch)
        ans = solveMem(s,p,i+1,j+1,dp);
    else
        ans = false;  
    dp[i][j] = ans;
    return dp[i][j];  
}
bool solveTab(string &s,string &p)
{
    int m = s.length();
    int n = p.length();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    dp[m][n] = true;
    for(int i=m;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
        bool currMatch = (i<s.length()) && (p[j] == '.' || s[i] == p[j]);
        bool ans;
        if(j+1 < p.length() && p[j+1] == '*')
        {
            bool emptyWala = dp[i][j+2];
            bool precElemWala = currMatch && dp[i+1][j];
            ans = emptyWala || precElemWala;
        }
        else if(currMatch)
            ans = dp[i+1][j+1];
        else
            ans = false;  
        dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
bool isMatch(string s, string p) {
    // return solve(s,p,0,0);

//    int m = s.length();
//    int n = p.length();
//    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    //  return solveMem(s,p,0,0,dp);

    return solveTab(s,p);
}
int main()
{
    string s,p;
    cout << "Enter s : " << endl;
    cin >> s;
    cout << "Enter p : " << endl;
    cin >> p;
    bool  ans = isMatch(s,p);
    if(ans == true)
      cout << "Match Found  "<< endl;
    else
      cout << "Match Not Found "  << endl; 

    return 0;
}