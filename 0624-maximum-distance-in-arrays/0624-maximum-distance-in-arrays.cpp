class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxdistance=0;
        int smallest=arrays[0][0];
        int biggest=arrays[0].back();



        for(int i=1;i<arrays.size();i++){
            maxdistance=max(maxdistance,abs(arrays[i].back()-smallest));
            maxdistance=max(maxdistance,abs(arrays[i][0]-biggest));
            smallest=min(smallest,arrays[i][0]);
            biggest=max(biggest,arrays[i].back());

        }
        return maxdistance;




        
    }
};