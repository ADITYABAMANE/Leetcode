class Solution {
public:


    int  bfs(int row, int col,vector<vector<int>>& grid,vector<vector<int>>&vis){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        int Area=1;

        q.push({row,col});
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};

        while(!q.empty()){

            int current_row=q.front().first;
            int current_col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int newrow=current_row+delrow[i];
                int newcol=current_col+delcol[i];

                if(newrow>=0 && newrow<n && newcol>=0 &&  newcol<m && !vis[newrow][newcol] &&  grid[newrow][newcol]){
                    Area++;
                    vis[newrow][newcol]=1;
                    q.push({newrow,newcol});



                }
            }

            






        }
        return Area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // int cnt=0;
        int maxarea=0;
        

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(!vis[i][j] && grid[i][j]==1){
                    int area=bfs(i,j,grid,vis);
                    maxarea=max(maxarea,area);
                    
                }
            }
        }
        return maxarea;

        









        
    }
};