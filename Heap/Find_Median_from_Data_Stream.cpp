class MedianFinder {
    public:
        priority_queue<int>maxHeap;
        priority_queue<int,vector<int>,greater<int>>minHeap;
        double median;
        MedianFinder() {
            median = 0;
        }
        
        void addNum(int num) {
            if(maxHeap.size() == minHeap.size())
            {
                if(num > median) //insert in right
                {
                    minHeap.push(num);
                    median = minHeap.top();
                }
                else //insert in left
                {
                   maxHeap.push(num);
                   median = maxHeap.top();
                }
            }
            else if(maxHeap.size() == minHeap.size()+1)//maxHeap size > minHeap size
            {
                if(num > median)
                {
                    minHeap.push(num);
                    median = (minHeap.top()+maxHeap.top())/2.0;
                }
                else //max already bada h seedha insert nahi kr skte toh 1 element off load karo
                {
                    int element = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(element);
                    maxHeap.push(num);//now insert num in left
                    median = (minHeap.top() + maxHeap.top())/2.0;
    
                }
    
            }
            else if(maxHeap.size()+1 == minHeap.size())
            {
                if(num > median) //min already bada hai seedha insert nhi kr skte hai ,toh element offload krna hai
                {
                    int element = minHeap.top();
                    minHeap.pop();
                    maxHeap.push(element);
                    minHeap.push(num);
                    median = (minHeap.top()+maxHeap.top())/2.0;
                }
                else
                {
                    //insert in left
                    maxHeap.push(num);
                    median = (minHeap.top()+maxHeap.top())/2.0;
                }
            }
        }
        
        double findMedian() {
            return median;
        }
    };
    
    /**
     * Your MedianFinder object will be instantiated and called as such:
     * MedianFinder* obj = new MedianFinder();
     * obj->addNum(num);
     * double param_2 = obj->findMedian();
     */