#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
#include <algorithm>
using namespace std;
int solve(vector<int>&sat,int i,int time)
{
    if(i == sat.size())
        return 0;
    int includeLikeTimeCoefficient = time*sat[i] + solve(sat,i+1,time+1);
    int excl = solve(sat,i+1,time);
    return max(includeLikeTimeCoefficient,excl);  
}
int solveMem(vector<int>&sat,int i,int time,vector<vector<int>>&dp)
{
    if(i == sat.size())
        return 0;
    if(dp[i][time] != -1)
        return dp[i][time];  
    int includeLikeTimeCoefficient = time*sat[i] + solveMem(sat,i+1,time+1,dp);
    int excl = solveMem(sat,i+1,time,dp);
    return dp[i][time] = max(includeLikeTimeCoefficient,excl);  
}
int solveTab(vector<int>&sat)
{
    vector<vector<int>>dp(sat.size()+1,vector<int>(sat.size()+2,0));

    for(int i=sat.size()-1;i>=0;i--)
    {
        for(int j=sat.size();j>=0;j--)
        {
            int includeLikeTimeCoefficient = j*sat[i] + dp[i+1][j+1];
            int excl = dp[i+1][j];
            dp[i][j] = max(includeLikeTimeCoefficient,excl);  
        }
    }
    return dp[0][1];
}
int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(),satisfaction.end());
    //return solve(satisfaction,0,1); 

//    vector<vector<int>>dp(satisfaction.size()+1,vector<int>(satisfaction.size()+1,-1));
//    return solveMem(satisfaction,0,1,dp);
    
    return solveTab(satisfaction);
}
int main()
{

    vector<int>sat = {-1,-8,0,5,-7};
    cout << "the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes : " << maxSatisfaction(sat) << endl;
    
    return 0;
}