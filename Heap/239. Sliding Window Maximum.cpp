class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            priority_queue<pair<int,int>>pq; //pair<val,index>
            vector<int>ans;
            for(int i=0;i<k;i++) //consider first window
              pq.push({nums[i],i});
            //store max of first window  
            ans.push_back(pq.top().first); 
            //consider rest of window
            for(int i = k; i<nums.size();i++)
            {
                pq.push({nums[i],i});
                //remove if maxs are from previous window
                while(pq.top().second <= i-k)
                   pq.pop();
                ans.push_back(pq.top().first);   
            } 
            return ans;
    
        }
    };