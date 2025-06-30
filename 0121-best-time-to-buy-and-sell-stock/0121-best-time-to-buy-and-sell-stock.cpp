class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum_cost_price=INT_MAX;
        int maximum_profit=INT_MIN;
        int n=prices.size();
        for(int i=0;i<n;i++){
            minimum_cost_price=min(minimum_cost_price, prices[i]);
            maximum_profit=max(maximum_profit, prices[i]-minimum_cost_price);
            



            
        }
        return maximum_profit;
        
    }
};