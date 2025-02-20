class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int roww=matrix.size();
        int coll=matrix[0].size();
        vector<int>row(roww,1);
        vector<int>col(coll,1);

        for(int i=0;i<roww;i++){
            for(int j=0;j<coll;j++){
                if(matrix[i][j]==0){
                    row[i]=0;
                    col[j]=0;
                }
            }
        }

        for(int i=0;i<roww;i++){
            for(int j=0;j<coll;j++){
                if(row[i]==0 || col[j]==0){
                    matrix[i][j]=0;


                }
            }
        }
    }
};