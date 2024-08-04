class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // int n=nums.size();
        vector<int>sums;
        int sum;

        for(int i=0;i<n;i++){
            sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                sums.push_back(sum);
            }
        }
        sort(sums.begin(),sums.end());
        
       
        long long res=0;
        for(int j=left-1;j<right;j++){
            res+=sums[j];

        }
        return res%1000000007;
        
    }
};