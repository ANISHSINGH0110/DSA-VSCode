class Solution {
    public:
        #define ll long long
        long long minimumDifference(vector<int>& nums) {
            int n = nums.size() / 3; // The problem implicitly assumes nums.size() is 3n.
            vector<ll> prefix(nums.size(), -1), suffix(nums.size(), -1);
    
            ll sum = 0; // Minimum `n` element sum for prefix
            priority_queue<ll> pq; // Max-heap for prefix calculation
    
            for (int i = 0; i < nums.size(); ++i) {
                sum += nums[i];
                pq.push(nums[i]);
    
                // Remove largest element if size exceeds `n`
                if (pq.size() > n) {
                    sum -= pq.top();
                    pq.pop();
                }
    
                // Store sum of `n` smallest elements if we have enough elements
                if (pq.size() == n) {
                    prefix[i] = sum;
                }
            }
    
            sum = 0; // Maximum `n` element sum for suffix
            priority_queue<ll, vector<ll>, greater<ll>> pq2; // Min-heap for suffix calculation
    
            for (int i = nums.size() - 1; i >= 0; --i) {
                sum += nums[i];
                pq2.push(nums[i]);
    
                // Remove smallest element if size exceeds `n`
                if (pq2.size() > n) {
                    sum -= pq2.top();
                    pq2.pop();
                }
    
                // Store sum of `n` largest elements if we have enough elements
                if (pq2.size() == n) {
                    suffix[i] = sum;
                }
            }
    
            ll ans = LLONG_MAX;
    
            // Calculate the minimum difference
            for (int i = n - 1; i < 2 * n; ++i) {
                if (prefix[i] != -1 && suffix[i + 1] != -1) {
                    ans = min(ans, prefix[i] - suffix[i + 1]);
                }
            }
    
            return ans;
        }
    };