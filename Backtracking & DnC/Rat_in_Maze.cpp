#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isSafe(int newx,int newy,vector<vector<bool>>&vis,vector<vector<int>>&m,int n)
{
    if(newx < 0 || newy < 0 || newx >=n || newy >= n)
      return false; //out of bound 
    if(vis[newx][newy] == true) 
      return false; //already visited
    if(m[newx][newy] == 0)
      return false; //blocked   
    return true;  
}

void solve(vector<vector<int>>&m,int n,vector<vector<bool>>&vis,int srcx,int srcy,int destx,int desty,vector<string>&ans,string output)
{
    if(srcx == destx && srcy == desty)
    {
        ans.push_back(output);
        return;
    }
    //Up i,j->i-1,j
    int newx = srcx-1;
    int newy = srcy;
    if(isSafe(newx,newy,vis,m,n))
    {
        vis[newx][newy] = true;
        solve(m,n,vis,newx,newy,destx,desty,ans,output+"U");
        //backtrack
        vis[newx][newy] = false;
    }
     //Down i,j->i+1,j
    newx = srcx+1;
     newy = srcy;
     if(isSafe(newx,newy,vis,m,n))
     {
         vis[newx][newy] = true;
         solve(m,n,vis,newx,newy,destx,desty,ans,output+"D");
         //backtrack
         vis[newx][newy] = false;
     }
      //Left i,j->i,j-1
    newx = srcx;
    newy = srcy-1;
    if(isSafe(newx,newy,vis,m,n))
    {
        vis[newx][newy] = true;
        solve(m,n,vis,newx,newy,destx,desty,ans,output+"L");
        //backtrack
        vis[newx][newy] = false;
    }
     //Right i,j->i,j+1
     newx = srcx;
     newy = srcy+1;
     if(isSafe(newx,newy,vis,m,n))
     {
         vis[newx][newy] = true;
         solve(m,n,vis,newx,newy,destx,desty,ans,output+"R");
         //backtrack
         vis[newx][newy] = false;
     }
}
vector<string>findPath(vector<vector<int>>&m,int n)
{
    vector<string>ans;
    int srcx = 0;
    int srcy = 0;
    int destx = n-1;
    int desty = n-1;
    string output = "";
    vector<vector<bool>>vis(n,vector<bool>(n,0));
    vis[0][0] = true;

    if(m[0][0] == 0)
      return ans;

    solve(m,n,vis,srcx,srcy,destx,desty,ans,output); 
    return ans;

}
int main()
{
    int n;
    cout << "Enter the value of n :" << endl;
    cin >> n;
    vector<vector<int>>m(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> m[i][j];
        }
    }
    vector<string>ans = findPath(m,n);
    for(auto i: ans)
    {
        cout << i << " ";
    }

    return 0;
}