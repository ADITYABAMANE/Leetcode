class Solution {
public:
    int solve(int  i ,int j , vector<int>& arr, vector<vector<int>>& dp){
        if(i>j) return INT_MIN;
        if(dp[i][j]!=-1)  return dp[i][j];
        int sum=0;
        for(int idx =i;idx<=j;idx++){
               sum+=arr[idx];
        }

        int score =0;
        int ans= 0;
        for(int idx=i;idx<=j;idx++){
              score+=arr[idx];
              sum-=arr[idx];
              if(sum>score){
                   ans = max(ans, score + solve(i,idx,arr,dp));
              }
              else if(score>sum) ans = max(ans , sum + solve(idx+1, j,arr,dp));
              else ans  = max({ans , score+solve(i,idx,arr,dp) , sum+solve(idx+1,j,arr,dp)});
        }

        return dp[i][j] = ans; 
    }
    int stoneGameV(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n ,vector<int>(n,-1));
        return solve(0 , n-1 , arr ,dp);
    }
};