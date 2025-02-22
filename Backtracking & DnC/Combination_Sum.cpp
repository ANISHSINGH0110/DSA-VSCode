#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& candidates,int target,vector<int>&v,vector<vector<int>>&ans,int index)
{
    if(target == 0)
    {
        ans.push_back(v);
        return;
    }
    if(target < 0)
        return;
    for(int i=index;i<candidates.size();i++)
    {
        v.push_back(candidates[i]);
        solve(candidates,target-candidates[i],v,ans,i);
        //backtrack
        v.pop_back();
    }  
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>v;
    solve(candidates,target,v,ans,0);
    return ans;
}
int main()
{
    int n;
    cout << "Enter the number of element in array : " << endl;
    cin >> n;
    vector<int>arr(n);
    cout << "Enter elements of array " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int target;
    cout << "Enter target " << endl;
    cin >> target;
    vector<vector<int>>ans = combinationSum(arr,target);
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