class Solution {
public:
    int dp[1001][1001], n, m;
    int mod = 1e9 + 7;
    int rec(int i, int j) {
        if (i <= 0 || j <= 0)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        ans += rec(i - 1, j);
        ans += rec(i, j - 1);
        ans %= mod;
        dp[i][j] = ans;
        // cout << i<<" "<<j<<" "<<ans << '\n';
        return ans;
    }
    int solve(vector<int>& nums) {
        if (nums.size() <= 1)
            return 1;
        vector<int> less, more;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[0])
                less.push_back(nums[i]);
            else
                more.push_back(nums[i]);
        }
        n = less.size();
        m = more.size();
        long long ans = rec(n,m);
        ans *= solve(less);
        ans %= mod;
        ans *= solve(more);
        ans %= mod;
        return ans;
    }
    int numOfWays(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums)-1;
    }
};