#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isSafeToPlace(vector<int>&e1,vector<int>&e2)
    {
        if(e1[0] < e2[0] && e1[1] < e2[1])
          return true;
        else
          return false;  
    }
    int solve(vector<vector<int>>&envelopes,int curr,int prev)
    {
       if(curr >= envelopes.size())
         return 0;
       int incl =0;
       if(prev == -1 || isSafeToPlace(envelopes[prev],envelopes[curr]))
         incl = 1 + solve(envelopes,curr+1,curr);
       int excl = 0 + solve(envelopes,curr+1,prev);
       int finalAns = max(incl,excl);
       return finalAns;    
    }
    int solveMem(vector<vector<int>>&envelopes,int curr,int prev,vector<vector<int>>&dp)
    {
       if(curr >= envelopes.size())
         return 0;
       if(dp[curr][prev+1] != -1)
         return dp[curr][prev+1];  
       int incl =0;
       if(prev == -1 || isSafeToPlace(envelopes[prev],envelopes[curr]))
         incl = 1 + solveMem(envelopes,curr+1,curr,dp);
       int excl = 0 + solveMem(envelopes,curr+1,prev,dp);
       dp[curr][prev+1] = max(incl,excl);
       return dp[curr][prev+1];    
    }
    int solveTab(vector<vector<int>>&envelopes)
    {
        vector<vector<int>>dp(envelopes.size()+1,vector<int>(envelopes.size()+1,0));
        int n = envelopes.size();
        for(int curr=n-1;curr>=0;curr--)
        {
            for(int prev = curr-1;prev>=-1;prev--)
            {
                int incl =0;
                if(prev == -1 || isSafeToPlace(envelopes[prev],envelopes[curr]))
                    incl = 1 + dp[curr+1][curr+1];
                int excl = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(incl,excl);
            }
        }
       return dp[0][0];

    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        int curr =0;
        int prev = -1;
        //return solve(envelopes,curr,prev);

        // vector<vector<int>>dp(envelopes.size()+1,vector<int>(envelopes.size()+1,-1));
        // return solveMem(envelopes,curr,prev,dp);

        return solveTab(envelopes);
    }
int main()
{
    int n;
    cout << "Enter number of envelop : " << endl;
    cin >> n;
    vector<vector<int>>arr(n,vector<int>(2,0));
    cout << "Enter elements of envelopes : " << endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "Maxmimum Envelopes is : " << maxEnvelopes(arr) << endl;
    return 0;
}