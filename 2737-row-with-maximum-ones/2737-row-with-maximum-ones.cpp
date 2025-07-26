class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        //0 , 1
        //1 , 0

        int n=mat.size();
        int m=mat[0].size();
        int max_ones=0;
        int oc=0;
        int maxr=0;


        for(int i=0;i<n;i++){
            oc=0;

            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    oc++;

                }

            }
            if(oc>max_ones){
                max_ones=oc;
                maxr=i;
            }
        }
        return {maxr,max_ones};
    }
};