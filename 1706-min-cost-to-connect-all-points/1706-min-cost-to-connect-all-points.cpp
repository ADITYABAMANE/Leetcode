class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 0, connected = 0;
        vector<int> minDist(n, INT_MAX);
        vector<bool> visited(n, false);
        minDist[0] = 0;
        while (connected < n) {
            int u = -1, minCost = INT_MAX;
            for (int i = 0; i < n; ++i) {
                if (!visited[i] && minDist[i] < minCost) {
                    minCost = minDist[i];
                    u = i;
                }
            }
            res += minCost;
            visited[u] = true;
            ++connected;
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int cost = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    minDist[v] = min(minDist[v], cost);
                }
            }
        }
        return res;
    }
};