#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
vector<string>solve(string&s,unordered_map<string,bool>&dict,int i)
{
    vector<string>ans;
    string word;
    if(i == s.size())
        return {""};
    for(int j=i;j<s.size();j++)
    {
        word.push_back(s[j]);
        if(dict.find(word) == dict.end())
            continue;
        auto right = solve(s,dict,j+1);
        for(auto eachRightPart:right)
        {
            string endPart;
            if(eachRightPart.size() > 0)
                endPart = " "+eachRightPart;
            ans.push_back(word+endPart);  
        }  
    }  
    return ans;

}
vector<string>solveMem(string&s,unordered_map<string,bool>&dict,int i,unordered_map<int,vector<string>>&dp)
{
    vector<string>ans;
    string word;
    if(i == s.size())
        return {""};
    if(dp.find(i) != dp.end())
        return dp[i];  
    for(int j=i;j<s.size();j++)
    {
        word.push_back(s[j]);
        if(dict.find(word) == dict.end())
            continue;
        auto right = solveMem(s,dict,j+1,dp);
        for(auto eachRightPart:right)
        {
            string endPart;
            if(eachRightPart.size() > 0)
                endPart = " "+eachRightPart;
            ans.push_back(word+endPart);  
        }  
    }  
    dp[i] = ans;
    return dp[i];

}
vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string,bool>dict;
    for(string s:wordDict)
        dict[s] = 1;
    // return solve(s,dict,0);  
    
    unordered_map<int,vector<string>>dp;
        return solveMem(s,dict,0,dp);
}
int main()
{
    string s = "catsanddog";
    vector<string>wordDict = {"cat","cats","and","sand","dog"};
    vector<string>ans = wordBreak(s,wordDict);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}