class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int>row_cnt(n,0);
        vector<int>col_cnt(m,0);
        

        int total_servers=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    row_cnt[i]++;
                    col_cnt[j]++;
                    total_servers++;


                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && (row_cnt[i]==1 && col_cnt[j]==1)){
                    total_servers--;
                }

            }
        }
        return total_servers;




        
    }
};