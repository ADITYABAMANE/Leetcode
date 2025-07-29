class Solution {
public:


    int check_paths(vector<vector<int>>& obstacleGrid, int i,int j,vector<vector<int>>&dp){
         int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();

       

        if(obstacleGrid[n-1][m-1]==1){
            return 0;
        }
        if(i>=n || j>=m){
            return 0;
        }
        if(i==n-1 && j==m-1){
            return 1;
        }
        int down=0;
        int right=0;
         if(dp[i][j]!=-1){
            return dp[i][j];
        }
          


          
        if(obstacleGrid[i][j]!=1){
          down=check_paths(obstacleGrid,i+1,j,dp);}
          if(obstacleGrid[i][j]!=1){
          
           right=check_paths(obstacleGrid,i,j+1,dp);
          }
          return dp[i][j]=down+right;
        


    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();


        vector<vector<int>>dp(n,vector<int>(m,-1));
       return  check_paths(obstacleGrid, 0,0,dp);
       
    }
};