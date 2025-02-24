#include <iostream>
#include<vector>
using namespace std;
int solve(vector<int>&val,vector<int>&wt,int capacity,int index)
{
    if(index == 0)
    {
        if(wt[0] <= capacity)
            return val[0];
        else
            return 0;
    }
    int incl = 0;
    if(wt[index] <= capacity)
    {
        incl = val[index] + solve(val,wt,capacity-wt[index],index-1);
    }
    int excl = 0 + solve(val,wt,capacity,index-1);
    int finalAns = max(incl,excl);
    return finalAns;
}
int solveMem(vector<int>&val,vector<int>&wt,int capacity,int index,vector<vector<int>>&dp)
{
    if(index == 0)
    {
        if(wt[0] <= capacity)
            return val[0];
        else
            return 0;
    }
    if(dp[capacity][index] != -1)
        return dp[capacity][index];
    int incl = 0;
    if(wt[index] <= capacity)
    {
        incl = val[index] + solveMem(val,wt,capacity-wt[index],index-1,dp);
    }
    int excl = 0 + solveMem(val,wt,capacity,index-1,dp);
    int finalAns = max(incl,excl);
    dp[capacity][index] = finalAns;
    return dp[capacity][index];
}
int solveTab(int capacity, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    vector<vector<int>>dp(capacity+1,vector<int>(n+1,0));
    for(int weight=0;weight<=capacity;weight++)
    {
        for(int index=1;index<=n-1;index++)
        {
            int incl = 0;
            if(wt[index] <= capacity)
            {
                incl = val[index] + dp[weight-wt[index]][index-1];
            }
            int excl = 0 + dp[weight][index-1];
            dp[weight][index] = max(incl,excl);
            
        }
    }
}
int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
    // code here
    // int n = val.size();
    // return solve(val,wt,capacity,n-1);
    
    int n = val.size();
    vector<vector<int>>dp(capacity+1,vector<int>(n+1,-1));
    return solveMem(val,wt,capacity,n-1,dp);
}

int main()
{
    int n;
    cout <<"Enter the value of n : " << endl;
    cin >> n;
    vector<int>val(n);
    cout << "Enter the elements of value : " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> val[i];
    }
    vector<int>wt(n);
    cout << "Enter the elements of weight : " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> wt[i];
    }
    int cap;
    cout << "Enter capacity : " << endl;
    cin >> cap;
    cout << "max Capacity is : " << knapSack(cap,val,wt) << endl;

    return 0;
}