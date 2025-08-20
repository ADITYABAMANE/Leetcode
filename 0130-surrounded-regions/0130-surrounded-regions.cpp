class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& board){
        int a=board.size();
        int b=board[0].size();
        vis[row][col]=1;

        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && nrow<a && ncol>=0 && ncol<b && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,board);
            }
        }




    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        //first row and last row;
        for(int j=0;j<m;j++){

            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,vis,board);
            }
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,vis,board);
            }

            
        }

        //first and last column
        for(int i=0;i<n;i++){

            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,vis,board);
            }

            
        }
        for(int k=0;k<n;k++){
            for(int z=0;z<m;z++){
                if(!vis[k][z] && board[k][z]=='O'){
                    board[k][z]='X';

                }
            }
        }
        
    }
};