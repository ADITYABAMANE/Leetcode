class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int min_cost=INT_MAX;
        int profit=0;
        int max_profit=INT_MIN;

        for(int i=0;i<n;i++){

            min_cost=min(min_cost,prices[i]);

            max_profit = max(max_profit, prices[i]-min_cost);











        }

        return max_profit;






        
    }
};