#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solve(string& s,int &n,int i)
    {
        if(i == n)
          return 1;//one valid split done
        if(s[i] == '0')
          return 0; //not possible;
        //incl ith char
        int result = solve(s,n,i+1);
        if(i+1 < n)
        {
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
              result += solve(s,n,i+2);
        }    
        return result;
    }
    int solveMemo(string& s,int &n,int i,vector<int>&dp)
    {
        if(i == n)
          return dp[i] =1;//one valid split done
        if(s[i] == '0')
          return dp[i] = 0; //not possible;
        if(dp[i] != -1)
          return dp[i];   
        //incl ith char
        int result = solveMemo(s,n,i+1,dp);
        if(i+1 < n)
        {
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
              result += solveMemo(s,n,i+2,dp);
        }    
        dp[i] = result;
        return dp[i];
    }
     int solveTab(string& s,int &n,vector<int>&dp)
    {
        dp[n] = 1; //one valid split done
        for(int i=n-1;i>=0;i--){
            if(s[i] == '0')
              dp[i] = 0;
            else{  
                dp[i] = dp[i+1];   
                if(i+1 < n)
                {
                    if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
                    dp[i] += dp[i+2];
                }
            }
        }   
        return dp[0];
    }
    int numDecodings(string s) {
       int n = s.length();
       //return solve(s,n,0);  

    //    vector<int>dp(101,-1);
    //    return solveMemo(s,n,0,dp);

       vector<int>dp(101,0);
       return solveTab(s,n,dp);
   }

int main()
{
    string s;
    cout <<"Enter the string : " << endl;
    cin >> s;
    cout << "Number Decoded is : " << numDecodings(s) << endl;
    
    return 0;
}