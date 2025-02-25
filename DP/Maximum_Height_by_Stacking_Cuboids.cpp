#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSafeToPlace(vector<int>&c1,vector<int>&c2)
{
    if(c1[0] <= c2[0] && c1[1] <= c2[1] && c1[2] <= c2[2])
      return true;
    else
      return false;  
}
int solve(vector<vector<int>>&cuboids,int curr,int prev)
{
    if(curr >= cuboids.size())
      return 0;
    int incl = 0;
    if(prev == -1 || isSafeToPlace(cuboids[prev],cuboids[curr]))
      incl = cuboids[curr][2] + solve(cuboids,curr+1,curr);
    int excl = 0 + solve(cuboids,curr+1,prev);
    int finalAns = max(incl,excl);
    return finalAns;    
}
int solveMem(vector<vector<int>>&cuboids,int curr,int prev,vector<vector<int>>&dp)
{
    if(curr >= cuboids.size())
      return 0;
    if(dp[curr][prev+1] != -1)
      return dp[curr][prev+1];  
    int incl = 0;
    if(prev == -1 || isSafeToPlace(cuboids[prev],cuboids[curr]))
      incl = cuboids[curr][2] + solveMem(cuboids,curr+1,curr,dp);
    int excl = 0 + solveMem(cuboids,curr+1,prev,dp);
    dp[curr][prev+1] = max(incl,excl);
    return dp[curr][prev+1];    
}
int solveTab(vector<vector<int>>&cuboids)
{
    int n = cuboids.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int curr=n-1;curr>=0;curr--)
    {
        for(int prev=curr-1;prev >=-1;prev--)
        {
            int incl = 0;
            if(prev == -1 || isSafeToPlace(cuboids[prev],cuboids[curr]))
              incl = cuboids[curr][2] + dp[curr+1][curr+1];
            int excl = 0 + dp[curr+1][prev+1];
            dp[curr][prev+1] = max(incl,excl);
        }
    }
    return dp[0][0];

}
int maxHeight(vector<vector<int>>& cuboids) {
   for(auto &cuboid:cuboids)
      sort(cuboid.begin(),cuboid.end());//to get max height at index 2
   sort(cuboids.begin(),cuboids.end());
   int curr = 0;
   int prev = -1;
//    int ans = solve(cuboids,curr,prev) ;
//    return ans;   
//    vector<vector<int>>dp(cuboids.size()+1,vector<int>(cuboids.size(),-1));
//    int ans = solveMem(cuboids,curr,prev,dp);
//    return ans;

   return solveTab(cuboids);
}
int main()
{
    int n;
    cout << "Enter the number of cuboids : " << endl;
    cin >> n;
    vector<vector<int>>arr(n,vector<int>(3));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >>arr[i][j];
        }
    }
    cout << "Maximum height of cuboid is : " << maxHeight(arr) << endl;

    return 0;
}