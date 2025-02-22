#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int kadaneAlgo(vector<int>&nums)
{
    int ans = INT_MIN,sum = 0;
    for(int i=0;i<nums.size();i++)
    {
    int num = nums[i];
    sum += num;
    ans = max(ans,sum);
    if(sum < 0) sum = 0;
    }
    return ans;
}
int maxSubArray(vector<int>& nums) {
    // int maxSum = INT_MIN;
    // int n = nums.size();
    // for (int i = 0; i < n; i++) {
    //     int sum = 0;  
    //     for (int j = i; j < n; j++) {
    //         sum += nums[j];  
    //         maxSum = max(maxSum, sum);  
    //     }
    // }
    // return maxSum;

    return kadaneAlgo(nums);
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
    cout << "Maximum subarray sum is : " << maxSubArray(arr) << endl;

    return 0;
}