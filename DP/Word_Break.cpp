#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool check(vector<string>&wordDict,string s)
{
    for(auto i:wordDict)
    {
        if(s == i)
          return true;
    }
    return false;
}
bool solve(string &s,vector<string>&wordDict,int start)
{
    if(start == s.size())
      return true;
    string word = "";
    bool flag = false;
    for(int i=start;i<s.size();i++)
    {
        word +=s[i];
        if(check(wordDict,word))
        {
            flag = flag || solve(s,wordDict,i+1);
        }
    }  
    return flag;
}
bool solveMem(string &s,vector<string>&wordDict,int start,vector<int>&dp)
{
    if(start == s.size())
      return true;
    string word = "";
    if(dp[start] != -1)
      return dp[start];
    bool flag = false;
    for(int i=start;i<s.size();i++)
    {
        word +=s[i];
        if(check(wordDict,word))
        {
            flag = flag || solveMem(s,wordDict,i+1,dp);
        }
    }  
    dp[start] = flag;
    return dp[start];
}
bool solveTab(string &s,vector<string>&wordDict)
{
    vector<int>dp(s.size()+1,1);
    for(int start = s.size()-1;start>=0;start--)
    {
        string word = "";
        bool flag = false;
        for(int i=start;i<s.size();i++)
        {
            word +=s[i];
            //cout << word << " ";
            if(check(wordDict,word))
            {
                flag = flag || dp[i+1];
            }
        }  
       // cout << endl;
        dp[start] = flag;
    }
    return dp[0];
    
}
bool wordBreak(string s, vector<string>& wordDict) {
    //return solve(s,wordDict,0);

    // vector<int>dp(s.size()+1,-1);
    // return solveMem(s,wordDict,0,dp);

    return solveTab(s,wordDict);
}
int main()
{
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string>wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    if(wordBreak(s,wordDict) == true)
      cout << "true if s can be segmented into a space-separated sequence of one or more dictionary words " << endl;
    else
      cout << "false if s can't be segmented into a space-separated sequence of one or more dictionary words." << endl;

    return 0;
}