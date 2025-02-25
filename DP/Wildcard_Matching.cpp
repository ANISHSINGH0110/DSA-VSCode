#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool solve(string &s,string &p,int i,int j)
    {
        if(i ==s.length() && j == p.length())
        {
            return true;
        }
        if(j == p.length())
          return false;
        if(i == s.length())
        {
            for(int k=j;k<p.length();k++)
            {
                if(p[k] != '*')
                  return false;
            }
            return true;
        }  
        if(p[j] == '?' || s[i] == p[j])
           return solve(s,p,i+1,j+1);
        else if(p[j] == '*')
           return solve(s,p,i+1,j) + solve(s,p,i,j+1);
        else
          return false;      
    }
    bool solveMem(string &s,string &p,int i,int j,vector<vector<int>>&dp)
    {
        if(i ==s.length() && j == p.length())
        {
            return true;
        }
        if(j == p.length())
          return false;
        if(i == s.length())
        {
            for(int k=j;k<p.length();k++)
            {
                if(p[k] != '*')
                  return false;
            }
            return true;
        }  
        if(dp[i][j] != -1)
          return dp[i][j];
        bool ans;  
        if(p[j] == '?' || s[i] == p[j])
           ans = solveMem(s,p,i+1,j+1,dp);
        else if(p[j] == '*')
           ans = solveMem(s,p,i+1,j,dp) + solveMem(s,p,i,j+1,dp);
        else
          return false; 
        dp[i][j] = ans; 
        return dp[i][j];       
    }
    bool solveTab(string &s,string &p)
    {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,0));
        dp[m][n] = true;
        for(int col=0;col<n;col++)
        {
            bool flag = true;
            for(int k=col;k<p.length();k++)
            {
                if(p[k] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[m][col] = flag;
        }
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n;j>=0;j--)
            {
                bool ans;  
                if(p[j] == '?' || s[i] == p[j])
                  ans = dp[i+1][j+1];
                else if(p[j] == '*')
                  ans = dp[i+1][j] || dp[i][j+1];
                else
                 ans = false; 
                dp[i][j] = ans; 
            }
        }
        return dp[0][0];

    }
    bool isMatch(string s, string p) {
        //return solve(s,p,0,0);


        // int m = s.length();
        // int n = p.length();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return solveMem(s,p,0,0,dp);

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