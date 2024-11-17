class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_pro=0;
        int min_pro=INT_MAX;
        int n=prices.size();
        for(int i=0;i<n;i++){
            min_pro=min(min_pro,prices[i]);
            max_pro=max(max_pro,prices[i]-min_pro);
            
        }
        return max_pro;
        
    }
};