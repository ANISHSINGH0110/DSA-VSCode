#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int solveOptimal(vector<int>&arr,vector<int>&lis)
{
    if(arr.size() == 0)
        return 0;
    vector<int>ans;
    lis.push_back(1);
    ans.push_back(arr[0]);
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i] > ans.back()){
            ans.push_back(arr[i]);
            lis.push_back(ans.size());
        }
        else{
            int index = lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
            ans[index] = arr[i]; 
            lis.push_back(index+1); 
        }
    }  
    return ans.size();
}
int minimumMountainRemovals(vector<int>& nums) {
    int n = nums.size();
    vector<int> lis, lds(n);  // lds should have a size equal to nums initially
    
    // Calculate LIS from left to right
    solveOptimal(nums, lis);
    
    // Reverse nums to calculate LDS
    reverse(nums.begin(), nums.end());
    
    // Now calculate LDS on the reversed nums
    solveOptimal(nums, lds);
    
    reverse(lds.begin(), lds.end());  // Reverse lds back to match the original nums order
    
    int largestMountain = INT_MIN;
    
    for (int i = 0; i < n; ++i) {
        if (lis[i] == 1 || lds[i] == 1) continue;  // Skip peaks that are not valid
        largestMountain = max(largestMountain, (lis[i] + lds[i] - 1));  // lis[i] + lds[i] - 1 gives mountain size
    }
    
    if (largestMountain == INT_MIN) return 0;
    
    int minRemoval = n - largestMountain;
    return minRemoval;
}
int main()
{
    vector<int>nums = {2,1,1,5,6,2,3,1};
    cout << "the minimum number of elements to remove to make nums a mountain array : " << minimumMountainRemovals(nums) << endl;
}