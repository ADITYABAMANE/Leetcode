class Solution {
public:
  long f(int ind, int target,vector<int>& coins, vector<vector<int>>&dp){

    //base cases
    if(target==0)return 1;
    if(ind<0)return 0;

    if(dp[ind][target]!=-1){
        return dp[ind][target];
    }

    long take=0;
    if(coins[ind]<=target){
        take=f(ind,target-coins[ind],coins,dp);

    }
    long nottake=f(ind-1,target,coins,dp);

    return dp[ind][target]=take+nottake;

  }
    int change(int amount, vector<int>& coins) {

        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);

        
    }
};