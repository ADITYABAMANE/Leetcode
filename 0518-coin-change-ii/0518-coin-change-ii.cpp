class Solution {
public:

    long noofcoins(int ind, int target,vector<int>& coins, vector<vector<int>>&dp ){

        if(ind<0)return 0;
        if(target==0)return 1;
        long take=0;
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        if(coins[ind]<=target){
            take=noofcoins(ind, target-coins[ind],coins,dp);
        }
        long nottake=noofcoins(ind-1, target,coins,dp);

        return dp[ind][target]=take+nottake;

    }
    int change(int amount,vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
        return noofcoins(n-1,amount, coins,dp);





        
    }
};