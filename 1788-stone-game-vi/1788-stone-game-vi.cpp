class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({aliceValues[i] + bobValues[i], i});
        }

        int alicesum = 0, bobsum = 0;

        for (int i = 0; i < n; i++) {
            pair<int, int> top = pq.top();
            pq.pop();
            int index = top.second;

            if (i % 2 == 0) {
                alicesum += aliceValues[index];
            } else {
                bobsum += bobValues[index];
            }
        }

        if (alicesum > bobsum) return 1;
        if (alicesum < bobsum) return -1;
        return 0;
    }
};