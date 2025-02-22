#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
bool solve(vector<int>& counts, vector<int>& quantity,int ithCust)
{
    if(ithCust == quantity.size())
      return true;
    for(int i=0;i<counts.size();i++)
    {
        if(counts[i] >= quantity[ithCust])
        {
            counts[i] -= quantity[ithCust];
            if(solve(counts,quantity,ithCust+1)){
              return true;
            }
            //backtrack
            counts[i] += quantity[ithCust];
        }
    } 
    return false; 
}
bool canDistribute(vector<int>& nums, vector<int>& quantity) {
    unordered_map<int,int>mp;
    for(auto num:nums)
      mp[num]++;
    vector<int>counts;
    for(auto i:mp)
      counts.push_back(i.second);
    sort(quantity.rbegin(),quantity.rend());  
    return solve(counts,quantity,0);    
}

int main()
{
    int n;
    cout << "Number of elements in nums array : " << endl;
    cin >> n;
    int m;
    cout << "Number of elements in quantity array : " << endl;
    cin >> m;
    vector<int>nums(n);
    vector<int>quantity(m);
    cout << "Elements of num array : " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }
    cout << "Elements of quantity array : " << endl;
    for(int i=0;i<m;i++)
    {
        cin >> quantity[i];
    }
    bool ans = canDistribute(nums,quantity);
    if(ans == true)
      cout << "Can Distribute " << endl;
    else
      cout << "Can't Distribute " << endl;

    return 0;
}