class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int,int>freqMap;//key:element,value:freq
            for(auto num:nums)
              freqMap[num]++;
            //pair<int,int>->shows {freq,num}
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
            //iterate over the freqMap & maintain heap of k size
            for(auto entry:freqMap)
            {
                minHeap.push({entry.second,entry.first});//heap has pair
                if(minHeap.size() > k)
                  minHeap.pop();//removing the least frq element
            }  
            //at this point my minHeap has top k freq element
            vector<int>ans;
            while(!minHeap.empty())
            {
                pair<int,int>top = minHeap.top();
                //auto top = minHeap.top();
                // auto [freq,num] = minHeap.top();
                minHeap.pop();
                ans.push_back(top.second);
            }
            return ans;
        }
    };