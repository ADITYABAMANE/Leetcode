class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();

        vector<int> nms;
        for (int i = 0; i < nums.size(); i++) {
            nms = nums[i];
            sort(nms.begin(), nms.end());

            nums[i] = nms;
        }

        // Traverse Column Wise
        int sum = 0;
        for (int j = 0; j < n; j++) {
            int maxi = -1;
            for (int i = 0; i < m; i++) {
                if (maxi < nums[i][j]) {
                    maxi = nums[i][j];
                }
            }

            sum += maxi;
        }

        return sum;
    }
};