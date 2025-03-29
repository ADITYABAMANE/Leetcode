class Solution {
public:


int fn(vector<int>& nums,int ind,vector<int>&dp){
    
    if(ind==0)return nums[ind];
    if(ind<0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    



    int take=nums[ind]+fn(nums,ind-2,dp);
    int nottake=0+fn(nums,ind-1,dp);

    return dp[ind]=max(take,nottake);


}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);

        return fn(nums,n-1,dp);

        
    }
};