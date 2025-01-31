class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int lastJumpIdx = 0; 
        int totaljumps = 0;

        if (n == 1) return 0;

        int coverage = 0;
        for (int i = 0; i < n - 1; i++) {  
            coverage = max(coverage, i + nums[i]);

            if (i == lastJumpIdx) {  
                lastJumpIdx = coverage;
                totaljumps++;

                if (coverage >= n - 1) { 
                    return totaljumps;
                }
            }
        }
        return totaljumps;
    }
};
