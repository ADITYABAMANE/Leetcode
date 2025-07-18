class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(), need = 0, curr = 0, res = n;
        for(int i = 0; i < n; ++i) need = (need + nums[i]) % p;
        if(need == 0) return 0;
        unordered_map<int,int> last;
        --last[0];
        for(int i = 0; i < n; ++i){
            curr = (curr + nums[i]) % p;
            int target = (curr - need + p) % p;
            if(last.count(target)) res = min(res , i - last[target]);
            last[curr] = i;
        }
        return res < n ? res : -1;
    }
};