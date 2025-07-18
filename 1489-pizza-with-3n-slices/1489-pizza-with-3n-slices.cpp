class Solution {
public:

    int recursion(vector<int>& slices, int i, int last, vector<vector<int>> &dp, int n)
    {
        if(i >= slices.size() or i>last or n == 0) return 0;
        if(dp[i][n] != -1) return dp[i][n];

        int take = slices[i] + recursion(slices, i+2, last, dp, n-1);
        int notake = recursion(slices, i+1, last, dp, n); 

        return dp[i][n] = max(take, notake);
    }

    int maxSizeSlices(vector<int>& slices) 
    {
        int n = slices.size();
        vector<vector<int>> dp1(n+1,vector<int>(n/3+1,-1)), dp2(n+1,vector<int>(n/3+1,-1));

        int ans = max(recursion(slices, 0, n-2, dp1, n/3),
                      recursion(slices, 1, n-1, dp2, n/3));
        return ans;
    }
};