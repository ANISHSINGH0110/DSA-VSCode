#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int solve(vector<int>&piles,int i,int M,bool alice)
{
    if(i>=piles.size())
        return 0;
    int ans = alice ? INT_MIN:INT_MAX;
    int total = 0;
    for(int x=1;x<=2*M;x++)
    {
        if(i+x-1 >= piles.size())
            break;
        total += piles[i+x-1];
        if(alice)
            ans = max(ans,total+solve(piles,i+x,max(x,M),!alice));
        else
            ans = min(ans,solve(piles,i+x,max(x,M),!alice));    
    }   
    return ans;
}
int solveMem(vector<int>&piles,int i,int M,bool alice,vector<vector<vector<int>>>&dp)
{
    if(i>=piles.size())
        return 0;
    if(dp[i][M][alice] != -1)
        return dp[i][M][alice];  
    int ans = alice ? INT_MIN:INT_MAX;
    int total = 0;
    for(int x=1;x<=2*M;x++)
    {
        if(i+x-1 >= piles.size())
            break;
        total += piles[i+x-1];
        if(alice)
            ans = max(ans,total+solveMem(piles,i+x,max(x,M),!alice,dp));
        else
            ans = min(ans,solveMem(piles,i+x,max(x,M),!alice,dp));    
    }   
    dp[i][M][alice] = ans;
    return dp[i][M][alice];
}
int solveTab(vector<int>&piles)
{
    vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,0)));
    for(int i=piles.size()-1;i>=0;i--)
    {
        for(int M=piles.size();M>=1;M--)
        {
            for(int alice = 0;alice <=1;alice++)
            {
                int ans = alice ? INT_MIN:INT_MAX;
                int total = 0;
                for(int x=1;x<=2*M;x++)
                {
                    if(i+x-1 >= piles.size())
                        break;
                    total += piles[i+x-1];
                    if(alice)
                    ans = max(ans,total+ dp[i+x][max(x,M)][!alice]);
                    else
                    ans = min(ans,dp[i+x][max(x,M)][!alice]);    
                }   
                dp[i][M][alice] = ans;
            }
        }
    }
    return dp[0][1][1];
}
int stoneGameII(vector<int>& piles) {
    //return solve(piles,0,1,true);

    // vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,-1)));
    // return solveMem(piles,0,1,true,dp);

    return solveTab(piles);
}
int main()
{
    vector<int>piles = {3111,4303,2722,2183,6351,5227,8964,7167,9286,6626,2347,1465,5201,7240,5463,8523,8163,9391,8616,5063,7837,7050,1246,9579,7744,6932,7704,9841,6163,4829,7324,6006,4689,8781,621};
    cout << "the maximum number of stones Alice can get : " << stoneGameII(piles) << endl;

    return 0;
}