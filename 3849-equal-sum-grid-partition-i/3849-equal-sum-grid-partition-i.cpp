class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();        // number of rows
        int n = grid[0].size();     // number of columns

        long long total = 0;

        // Step 1: Calculate total sum
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                total += grid[i][j];
            }
        }

        // Can't split if total is odd
        if (total % 2 != 0) return false;

        // Step 2: Check horizontal split
        long long rowSum = 0;
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                rowSum += grid[i][j];
            }

            if (rowSum * 2 == total)
                return true;
        }

        // Step 3: Compute column sums
        vector<long long> colSums(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                colSums[j] += grid[i][j];
            }
        }

        // Step 4: Check vertical split
        long long colSum = 0;
        for (int j = 0; j < n - 1; ++j) {
            colSum += colSums[j];
            if (colSum * 2 == total)
                return true;
        }

        // No valid cut found
        return false;
    }
};