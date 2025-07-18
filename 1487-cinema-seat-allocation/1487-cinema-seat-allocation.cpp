class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int , int> aisle;
        for(int i = 0, m = reservedSeats.size(); i < m; ++i){
            int seat = reservedSeats[i][1];
            if(seat > 1 && seat < 10) aisle[reservedSeats[i][0]] |= (1 << (seat - 2));
        }
        int count = 2 * (n - aisle.size());
        for(auto& [_ , mask] : aisle){
            bool left = !(mask & (0b00001111));
            bool mid = !(mask & (0b00111100));
            bool right = !(mask & (0b11110000));
            if(left && right) count += 2;
            else if(left || mid || right) ++count;
        }
        return count;
    }
};