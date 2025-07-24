class Solution {
public:


    void bfs(vector<vector<char>>& grid, vector<vector<int>>&vis,int row,int col){
        queue<pair<int,int>>q;
        vis[row][col]=1;

        int n=grid.size();
        int m=grid[0].size();


        // vis[row][col]=1;
        q.push({row,col});

       int delrow[]={-1,0,1,0};
       int delcol[]={0,-1,0,1};

       while(!q.empty()){
        int trow=q.front().first;
        int tcol=q.front().second;

        q.pop();
        for(int i=0;i<4;i++){
            int nrow=trow+delrow[i];
            int ncol=tcol+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }



       }







    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m= grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(grid,vis,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};