class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n = nums.size(), sum = 0, total = accumulate(nums.begin() , nums.end() , 0);
        sort(nums.begin() , nums.end() , greater<int>());
        vector<int> res;
        for(int i = 0; i < n; ++i){
            res.push_back(nums[i]);
            sum += nums[i];
            if(2 * sum > total) break;
        }
        return res;
    }
};