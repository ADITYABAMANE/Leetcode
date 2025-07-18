class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int maxX = 0, maxY = 0, n = towers.size();
        for (int i = 0; i < n; ++i) {
            maxX = max(maxX, towers[i][0]);
            maxY = max(maxY, towers[i][1]);
        }
        int bestSignal = -1;
        vector<int> res(2);
        for (int x = 0; x <= maxX + radius; ++x) {
            for (int y = 0; y <= maxY + radius; ++y) {
                int totalSignal = 0;
                for (int i = 0; i < n; ++i) {
                    int dx = x - towers[i][0], dy = y - towers[i][1];
                    int distSq = dx * dx + dy * dy;
                    if (distSq <= radius * radius) totalSignal += towers[i][2] / (1 + sqrt(distSq));
                }
                if (totalSignal > bestSignal) {
                    bestSignal = totalSignal;
                    res = {x, y};
                } 
                else if (totalSignal == bestSignal) {
                    if (x < res[0] || (x == res[0] && y < res[1])) res = {x, y};
                }
            }
        }
        return res;
    }
};