class Solution {
    public:
        int solve(const vector<int>& nums, int index, int prev_index, int prev_diff) {
            if (index == nums.size()) 
              return 0;
    
            // Option 1: skip current element
            int skip = solve(nums, index + 1, prev_index, prev_diff);
    
            int take = 0;
            if (prev_index == -1) {
                // First element, can always take
                take = 1 + solve(nums, index + 1, index, -1);
            } else {
                int curr_diff = abs(nums[index] - nums[prev_index]);
                if (prev_diff == -1 || curr_diff <= prev_diff) {
                    take = 1 + solve(nums, index + 1, index, curr_diff);
                }
            }
    
            return max(skip, take);
        }
        unordered_map<string, int> memo;
    
        int dfs(const vector<int>& nums, int index, int prev_index, int prev_diff) {
            if (index == nums.size())
                return 0;
    
            // Memo key encoding
            string key = to_string(index) + "|" + to_string(prev_index) + "|" + to_string(prev_diff);
            if (memo.find(key) != memo.end())
                return memo[key];
    
            // Option 1: skip current element
            int skip = dfs(nums, index + 1, prev_index, prev_diff);
    
            // Option 2: take current element if valid
            int take = 0;
            if (prev_index == -1) {
                // First element, can always take
                take = 1 + dfs(nums, index + 1, index, 301);  // set initial diff very high
            } else {
                int curr_diff = abs(nums[index] - nums[prev_index]);
                if (curr_diff <= prev_diff) {
                    take = 1 + dfs(nums, index + 1, index, curr_diff);
                }
            }
    
            return memo[key] = max(skip, take);
        }
        int solveMem(const vector<int>& nums, int index, int prev_index, int prev_diff,
                     vector<vector<vector<int>>>& dp) {
            if (index == nums.size())
                return 0;
    
            if (dp[index][prev_index + 1][prev_diff + 1] != -1)
                return dp[index][prev_index + 1][prev_diff + 1];
    
            // Option 1: skip current element
            int skip = solveMem(nums, index + 1, prev_index, prev_diff, dp);
    
            int take = 0;
            if (prev_index == -1) {
                // First element, always take
                take = 1 + solveMem(nums, index + 1, index, -1, dp);
            } else {
                int curr_diff = abs(nums[index] - nums[prev_index]);
                if (prev_diff == -1 || curr_diff <= prev_diff) {
                    take = 1 + solveMem(nums, index + 1, index, curr_diff, dp);
                }
            }
    
            return dp[index][prev_index + 1][prev_diff + 1] = max(skip, take);
        }
        int longestSubsequence(vector<int>& nums) {
            //return solve(nums,0,-1,-1);
    
            // int n = nums.size();
            // // Dimensions: index, prev_index+1, prev_diff+1
            // vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(302, -1)));
            // return solveMem(nums, 0, -1, -1, dp);
    
           // return dfs(nums, 0, -1, 301);
    
           int n = nums.size();
            vector<unordered_map<int, int>> dp(n);
            int maxLen = 1;
    
            for (int i = 0; i < n; ++i) {
                dp[i][300] = 1; // Initialize with max possible diff
    
                for (int j = 0; j < i; ++j) {
                    int diff = abs(nums[i] - nums[j]);
    
                    // Try extending all valid sequences ending at j
                    for (auto& [prev_diff, length] : dp[j]) {
                        if (diff <= prev_diff) {
                            dp[i][diff] = max(dp[i][diff], length + 1);
                            maxLen = max(maxLen, dp[i][diff]);
                        }
                    }
                }
            }
    
            return maxLen;
    
           
        }
    };