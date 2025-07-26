class Solution {
public:

    int solve(vector<int>&nums, int ind,vector<int>&dp){
        int n=nums.size();

        

        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1)return dp[ind];
        int pick=nums[ind]+solve(nums,ind+2,dp);
         int notpick=0+solve(nums,ind+1,dp);


         return dp[ind]=max(pick,notpick);


    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);

        return solve(nums,0,dp);
        
    }
};