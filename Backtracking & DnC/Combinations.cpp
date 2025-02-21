#include <iostream>
#include <vector>
using namespace std;

void solve(int n,int k,vector<vector<int>>&ans,vector<int>curr,int start)
{
    if(k == 0)
    {
        ans.push_back(curr);
        return;
    }
    for(int i=start;i<=n;i++)
    {
        curr.push_back(i);
        solve(n,k-1,ans,curr,i+1);
        //backtrack
        curr.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>>ans;
    vector<int>curr;
    solve(n,k,ans,curr,1);
    return ans;
}

int main()
{
    int n,k;
    cout << "Enter the value of n : " << endl;
    cin >> n;
    cout << "Enter the value of k : " << endl;
    cin >> k;
    vector<vector<int>>ans = combine(n,k);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}