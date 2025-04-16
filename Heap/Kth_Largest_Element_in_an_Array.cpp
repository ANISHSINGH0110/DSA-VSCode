#include <bits/stdc++.h>
using namespace std;
//using max Heap
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int>pq;
    for(int i=0;i<nums.size();i++)
    {
        pq.push(nums[i]);
    }
    int ans = -1;
    while(k != 0)
    {
        ans = pq.top();
        pq.pop();
        k--;
    }
    return ans;
}
//using min heap
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<nums.size();i++)
    {
        pq.push(nums[i]);
        if(pq.size() > k)
          pq.pop();
    }
    return pq.top();
}

