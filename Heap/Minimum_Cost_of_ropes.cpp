#include <bits/stdc++.h>
using namespace std;
int minCost(vector<int>& arr) {
    // code here
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<arr.size();i++)
       pq.push(arr[i]);
    int ans = 0;
    while(pq.size() != 1)
    {
        int topE1 = pq.top();
        pq.pop();
        int topE2 = pq.top();
        pq.pop();
        int sum = topE1+topE2;
        ans +=sum;
        pq.push(sum);
    }
    return ans;
}