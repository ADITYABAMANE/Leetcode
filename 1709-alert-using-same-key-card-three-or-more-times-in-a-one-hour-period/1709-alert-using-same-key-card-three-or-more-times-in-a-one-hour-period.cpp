class Solution {
private:
    int calcTime(string& Time){
        return ((Time[0] - '0') * 10 + Time[1] - '0') * 60 + (Time[3] - '0') * 10 + Time[4] - '0';
    }
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> logs;
        for (int i = 0, n = keyName.size(); i < n; ++i) logs[keyName[i]].push_back(calcTime(keyTime[i]));
        vector<string> alert;
        for (auto& [name, times] : logs) {
            sort(times.begin(), times.end());
            for (int i = 2, m = times.size(); i < m; ++i) {
                if (times[i] - times[i - 2] <= 60) {
                    alert.push_back(name);
                    break;
                }
            }
        }
        sort(alert.begin(), alert.end());
        return alert;
    }
};