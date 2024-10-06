class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        for (const string& word : words) {
            mp[word]++;
        }

        vector<pair<string, int>> freqVec(mp.begin(), mp.end());

        sort(freqVec.begin(), freqVec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });

        vector<string> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(freqVec[i].first);
        }

        return result;
    }
};
