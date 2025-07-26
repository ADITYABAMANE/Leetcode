class Solution {
public:

    int solve(vector<int>& nums,int ind, int n,vector<int>&dp){

        if(ind>n)return 0;
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int pick=nums[ind]+ solve(nums,ind+2,n,dp);
        int np=0+solve(nums,ind+1,n,dp);

        return dp[ind] = max(pick,np);

    }
    int rob(vector<int>& nums) {

        int n=nums.size();

        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
       

        int ans1=solve(nums,0,n-2,dp1);
        int ans2=solve(nums, 1,n-1,dp2);

        return max(ans1,ans2);
        
    }
};