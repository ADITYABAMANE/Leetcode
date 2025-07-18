class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), q = l.size();
        vector<bool> res(q , false);
        for(int j = 0; j < q; ++j){
            int start = l[j], end = r[j];
            int maxi = *max_element(nums.begin() + start, nums.begin() + end + 1);
            int mini = *min_element(nums.begin() + start, nums.begin() + end + 1);
            int len = end - start + 1, diff = (maxi - mini) / (len - 1);
            if(maxi == mini) res[j] = true;
            else if((maxi - mini) % (len - 1)) continue;
            else{
                vector<bool> seen(len , false);
                int i;
                for(i = start; i <= end; ++i){
                    int currdiff = nums[i] - mini;
                    if(currdiff % diff || seen[currdiff / diff]) break;
                    seen[currdiff / diff] = true;
                }
                if(i > end) res[j] = true;
            }
        }
        return res;
    }
};