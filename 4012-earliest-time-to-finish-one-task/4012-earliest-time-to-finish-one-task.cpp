class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int mint=INT_MAX;

        for(int i=0;i<tasks.size();i++){

            int ct=tasks[i][0]+tasks[i][1];

            mint=min(mint,ct);
        }
        return mint;
        
    }
};