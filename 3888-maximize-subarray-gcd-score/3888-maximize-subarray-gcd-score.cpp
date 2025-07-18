class Solution {
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        int n = nums.size();
        long long max_val = 0;
        for(int i = 0; i < n; i++) {
            int gcd = nums[i];
            unordered_map<int, int> mp;
            int lowest = INT_MAX;
            for(int j = i; j < n; j++) {
                //subarray i..j
                int kk = nums[j];
                int count = 0;
                while(kk%2  == 0) {
                    kk /= 2;
                    count++;
                }
                mp[count]++;
                lowest = min(lowest, count);
                
                gcd = __gcd(gcd, nums[j]);
                
                long long val = (long long)gcd*(j-i+1);
                count = mp[lowest];
                if(count <= k) {
                    val = val * 2;
                }
                
                max_val = max(max_val, val);
            }
        }
        
        return max_val;
    }
};