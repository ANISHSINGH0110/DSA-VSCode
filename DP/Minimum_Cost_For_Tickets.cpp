#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int>& days, vector<int>& costs,int i)
    {
        if(i >= days.size())
          return 0;
        //1day pass  
        int cost1 = costs[0] + solve(days,costs,i+1);
        //7 day pass
        int endDayPass = days[i]+7-1;
        int j=1;
        while(j < days.size() && days[j] <=endDayPass)
        {
            j++;
        }
        int cost7 = costs[1]+solve(days,costs,j);
        //30 days pass
        endDayPass = days[i] +30-1;
        j=1;
        while(j<days.size() && days[j] <=endDayPass)
           j++;
        int cost30 = costs[2] + solve(days,costs,j);
        int ans = min(cost1,min(cost7,cost30));
        return ans;   

    }
    int solveMem(vector<int>& days, vector<int>& costs,int i,vector<int>&dp)
    {
        if(i >= days.size())
          return 0;
        if(dp[i] != -1)
          return dp[i];  
        //1day pass  
        int cost1 = costs[0] + solveMem(days,costs,i+1,dp);
        //7 day pass
        int endDayPass = days[i]+7-1;
        int j=1;
        while(j < days.size() && days[j] <=endDayPass)
        {
            j++;
        }
        int cost7 = costs[1]+solveMem(days,costs,j,dp);
        //30 days pass
        endDayPass = days[i] +30-1;
        j=1;
        while(j<days.size() && days[j] <=endDayPass)
           j++;
        int cost30 = costs[2] + solveMem(days,costs,j,dp);
        int ans = min(cost1,min(cost7,cost30));
        dp[i] = ans;
        return dp[i];   

    }
    int solveTab(vector<int>& days, vector<int>& costs)
    {
        vector<int>dp(days.size()+1,0);
        for(int i=days.size()-1;i>=0;i--)
        {
            //1day pass  
            int cost1 = costs[0] + dp[i+1];
            //7 day pass
            int endDayPass = days[i]+7-1;
            int j=1;
            while(j < days.size() && days[j] <=endDayPass)
            {
                j++;
            }
            int cost7 = costs[1]+ dp[j];
            //30 days pass
            endDayPass = days[i] +30-1;
            j=1;
            while(j<days.size() && days[j] <=endDayPass)
            j++;
            int cost30 = costs[2] + dp[j];
            dp[i] = min(cost1,min(cost7,cost30));
        }
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        //return solve(days,costs,0);

        // vector<int>dp(days.size()+1,-1);
        // return solveMem(days,costs,0,dp);
        
        return solveTab(days,costs);
    }
int main()
{
    int n;
    cout <<"number of days array " << endl;
    cin >> n;
    vector<int>days(n);
    cout << "Enter elements of days array " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> days[i];
    }
    cout << "Enter the costs of passes 1,7,30 " << endl;
    vector<int>costs(3);
    for(int i=0;i<3;i++)
    {
        cin >> costs[i];
    }
    cout << "the minimum number of dollars you need to travel every day in the given list of days : " << mincostTickets(days,costs) << endl;

    return 0;
}