class Solution {
    public:
      vector<int> firstNegInt(vector<int>& arr, int k) {
          // write code here
          vector<int> ans;
          deque<int> dq;
          int i = 0, j = 0;
          int n = arr.size();
          
          while (j < n) {
              // If current element is negative, push its index
              if (arr[j] < 0) {
                  dq.push_back(j);
              }
      
              if (j - i + 1 < k) {
                  j++;
              } else if (j - i + 1 == k) {
                  // Check if there's any negative number in window
                  if (!dq.empty()) {
                      ans.push_back(arr[dq.front()]);
                  } else {
                      ans.push_back(0);
                  }
      
                  // Slide the window
                  if (!dq.empty() && dq.front() == i) {
                      dq.pop_front();  // Remove index that's going out of window
                  }
                  i++;
                  j++;
              }
          }
      
          return ans;
      }
  };