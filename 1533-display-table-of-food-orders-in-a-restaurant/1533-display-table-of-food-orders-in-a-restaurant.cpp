class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, unordered_map<string, int>> map;
        set<string> items;

        for (int i = 0, n = orders.size(); i < n; ++i) {
            int table = stoi(orders[i][1]);
            string food = orders[i][2];
            ++map[table][food];
            items.insert(food);
        }

        vector<vector<string>> result;
        vector<string> header{"Table"};
        header.insert(header.end(), items.begin(), items.end());
        result.push_back(header);

        for (const auto& [table, foodCount] : map) {
            vector<string> row{to_string(table)};
            for (const string& food : items) {
                if(foodCount.count(food)) row.push_back(to_string(foodCount.at(food)));
                else row.push_back("0");
            }
            result.push_back(row);
        }
        return result;
    }
};