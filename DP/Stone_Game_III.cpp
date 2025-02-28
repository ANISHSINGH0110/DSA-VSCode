#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int solve(vector<int>&sv,int i)
    {
        if(i == sv.size())
          return 0;
        int ans = INT_MIN;
        int total = 0;
        for(int x=1;x<=3;x++)
        {
            if(i+x-1 >= sv.size())
              break;
            total += sv[i+x-1];
            ans = max(ans,total-solve(sv,i+x));
        }  
        return ans;
    }
    int solveMem(vector<int>&sv,int i,vector<int>&dp)
    {
        if(i == sv.size())
          return 0;
        if(dp[i] != -1)
          return dp[i];  
        int ans = INT_MIN;
        int total = 0;
        for(int x=1;x<=3;x++)
        {
            if(i+x-1 >= sv.size())
              break;
            total += sv[i+x-1];
            ans = max(ans,total-solveMem(sv,i+x,dp));
        }  
        dp[i] = ans;
        return dp[i];
    }
    int solveTab(vector<int>&sv)
    {
        vector<int>dp(sv.size()+1,0);
        for(int i=sv.size()-1;i>=0;i--)
        {
            int ans = INT_MIN;
            int total = 0;
            for(int x=1;x<=3;x++)
            {
                if(i+x-1 >= sv.size())
                 break;
                total += sv[i+x-1];
                ans = max(ans,total- dp[i+x]);
            }  
            dp[i] = ans;
        }
        return dp[0];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        //int ans = solve(stoneValue,0);
        
        // vector<int>dp(stoneValue.size(),-1);
        // int ans = solveMem(stoneValue,0,dp);

        int ans = solveTab(stoneValue);
        if(ans > 0)
         return "Alice";
        else if(ans < 0)
          return "Bob";
        return "Tie";   
    }
int main()
{
    //vector<int>sv = {1,2,3,7};
    //vector<int>sv = {1,2,3,-9};
    vector<int>sv = {1,2,3,6};

    cout << "the winner is : " << stoneGameIII(sv) << endl;
    return 0;
}