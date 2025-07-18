class Solution {
public:
    bool dfs(int i , int j , int n , int m, vector<vector<bool>>& vis , vector<vector<int>>& mat){
        if(i < 0 || j < 0 || i >= n || j >= m || mat[i][j] == 0 || vis[i][j])
            return false;

        vis[i][j] = true;

        dfs(i + 1 , j , n , m , vis , mat);
        dfs(i - 1 , j , n , m , vis , mat);
        dfs(i  , j + 1, n , m , vis , mat);
        dfs(i  , j - 1 , n , m , vis , mat);

        return true;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> mat(3 * n, vector<int>(3 * m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int r = 3 * i, c = 3 * j;
                int val = grid[i][j];

                // mark connectivity based on street type
                if(val == 1){ // horizontal
                    mat[r + 1][c] = mat[r + 1][c + 1] = mat[r + 1][c + 2] = 1;
                } else if(val == 2){ // vertical
                    mat[r][c + 1] = mat[r + 1][c + 1] = mat[r + 2][c + 1] = 1;
                } else if(val == 3){ // top-left corner
                    mat[r + 1][c + 1] = mat[r + 2][c + 1] = mat[r + 1][c] = 1;
                } else if(val == 4){ // top-right corner
                    mat[r + 1][c + 1] = mat[r + 2][c + 1] = mat[r + 1][c + 2] = 1;
                } else if(val == 5){ // bottom-left corner
                    mat[r + 1][c + 1] = mat[r][c + 1] = mat[r + 1][c] = 1;
                } else if(val == 6){ // bottom-right corner
                    mat[r + 1][c + 1] = mat[r][c + 1] = mat[r + 1][c + 2] = 1;
                }
            }
        }

        vector<vector<bool>> vis(3 * n, vector<bool>(3 * m, false));

        // start DFS from top-left cell center
        dfs(1, 1, 3 * n, 3 * m, vis, mat);

        // check if bottom-right cell center is visited
        return vis[3 * n - 2][3 * m - 2];
    }
};