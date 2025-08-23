class Solution {
public:
    long long  solve(int row,int col,vector<vector<int>>& grid,vector<vector<long long>>&dp){
        int n=grid.size();
        int m=grid[0].size();
        // int sum=0;
         if(row<0 || row>=n || col<0 || col>=m){
            return INT_MAX;
        }

        if(row==n-1 && col==m-1){
            return grid[row][col];
        }
        if(dp[row][col]!=-1)return dp[row][col];
       
       long long right=grid[row][col]+solve(row,col+1,grid,dp);

        long long down=grid[row][col]+solve(row+1,col,grid,dp);

        return dp[row][col]= min(right,down);






    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       vector<vector<long long>> dp(n, vector<long long>(m, -1));

        return solve(0,0,grid,dp);
        
    }
};