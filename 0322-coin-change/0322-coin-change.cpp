class Solution {
public:
     long noofcoins(int ind, int target, vector<int>& coins) {
        if (ind < 0) return INT_MAX;
        if (target == 0) return 1;

        long take = 0;
        if (coins[ind] <= target)
            take = 1+ noofcoins(ind, target - coins[ind], coins);  // take same coin again

        long nottake = noofcoins(ind - 1, target, coins);       // skip current coin
        
        return min(take , nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
         int n = coins.size();
        return noofcoins(n - 1, amount, coins);
    }
};