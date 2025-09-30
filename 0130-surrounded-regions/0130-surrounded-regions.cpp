class Solution {
public:

    void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>& board){

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

         //first row and last row

         for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(0,i,vis,board);
            }
            if(!vis[n-1][i] && board[n-1][i]=='O'){
                dfs(n-1,i,vis,board);
            }
         }
         



         //first col and last col

         for(int j=0;j<n;j++){
            if(!vis[j][0] && board[j][0]=='O'){
                dfs(j,0,vis,board);
            }
            if(!vis[j][m-1] && board[j][m-1]=='O'){
                dfs(j,m-1,vis,board);

            }

         }
         for(int k=0;k<n;k++){
            for(int l=0;l<m;l++){
                if(!vis[k][l] && board[k][l]=='O'){
                    board[k][l]='X';
                }
            }
         }

        
    }
};