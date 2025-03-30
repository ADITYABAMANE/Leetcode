class Solution {
public:
    // Helper function to calculate max profit with memoization
    int fn(vector<int>& nums, int ind, vector<int>& dp, int start) {
        if (ind < start) return 0; // If index goes below start, return 0
        if (ind == start) return nums[start]; // Base case: rob the first house
        
        if (dp[ind] != -1) return dp[ind]; // If value is already calculated, return it
        
        // Two choices:
        int take = nums[ind] + fn(nums, ind - 2, dp, start); // Rob current and skip previous
        int nottake = fn(nums, ind - 1, dp, start); // Skip current and move to previous
        
        return dp[ind] = max(take, nottake); // Store and return the maximum profit
    }

    // Main function
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Edge cases
        if (n == 1) return nums[0]; // If only one house
        if (n == 2) return max(nums[0], nums[1]); // If two houses, take max

        // Create dp arrays initialized to -1 for both cases
        vector<int> dp1(n, -1); // Case 1: Exclude last house
        vector<int> dp2(n, -1); // Case 2: Exclude first house

        // Rob from 0 to n-2 (excluding last house)
        int case1 = fn(nums, n - 2, dp1, 0);
        
        // Rob from 1 to n-1 (excluding first house)
        int case2 = fn(nums, n - 1, dp2, 1);

        // Return the maximum of both cases
        return max(case1, case2);
    }
};
