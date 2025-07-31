class Solution {
public:
    bool solve(int ind,vector<int>&nums , int target,vector<vector<int>>&dp){
        int n=nums.size();

        
        if(target==0)return true;
        if(ind>=n && target!=0){
            return false;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        bool take=false;
        if(nums[ind]<=target){
        take=solve(ind+1,nums,  target-nums[ind],dp);
        }
        bool notake=solve(ind+1,nums,  target,dp);

        return dp[ind][target]= take || notake ;



    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        
        int target=sum/2;
        vector<vector<int>>dp(nums.size(),vector<int>(target+1, -1));

        return solve(0,nums,target,dp);        
    }
};