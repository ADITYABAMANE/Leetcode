class Solution {
public:

    int fn(vector<int>& nums,int ind, vector<int>&dp,int start){
        if(ind==start)return nums[ind];
        if(ind<start)return 0;

        if(dp[ind]!=-1)return dp[ind];

        int take=nums[ind]+fn(nums,ind-2,dp,start);
        int notake=0+fn(nums,ind-1,dp,start);

        return dp[ind]=max(take,notake);
         








    }

    int rob(vector<int>& nums) {
         int n=nums.size();
        // vector<int>dp(n,-1);
       
        //return fn(nums,n-1,dp);
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);

        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        int case1=fn(nums,n-2,dp1,0);
        int case2=fn(nums,n-1,dp2,1);

        return max(case1,case2);

        
    }
};