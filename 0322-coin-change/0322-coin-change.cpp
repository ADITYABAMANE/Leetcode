class Solution {
public:
     long noofcoins(int ind, int target, vector<int>& coins,vector<vector<long>>&dp) {
        if (ind ==0) {
        if( target%coins[0]==0){
            return target/coins[0];
        }
        return INT_MAX;}

        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }

        
        long nottake=0+ noofcoins(ind-1,target,coins,dp);
        long take=INT_MAX;
        if (coins[ind] <= target)
            take = 1+ noofcoins(ind, target - coins[ind], coins,dp);  // take same coin again

       

        return dp[ind][target]= min(take , nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
         int n = coins.size();
        vector<vector<long>> dp(n, vector<long>(amount + 1, -1));
        long ans= noofcoins(n - 1, amount, coins,dp);
        if(ans>=INT_MAX)return -1;
        return ans;
    }
};