class Solution {
private:
    void bfs(vector<vector<char>>& grid, int row, int col, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};

        while (!q.empty()) {
            int crow = q.front().first;
            int ccol = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = crow + delrow[i];
                int ncol = ccol + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++;
                    bfs(grid, row, col, vis);
                }
            }
        }
        return cnt;
    }
};
