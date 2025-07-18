class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<long long, long long> mp;
        multiset<long long, greater<int>> s;
        
        vector<long long> ans;
        
        int n = nums.size();
        for(int i = 0; i < n; i++){
            auto temp = s.find(mp[nums[i]]);
            if(temp != s.end()) s.erase(temp);
            mp[nums[i]] += freq[i];
            s.insert(mp[nums[i]]);
            
            if(s.empty()){
                ans.push_back(0);
            } else {
                ans.push_back(*(s.begin()));
            }
        }
        
        return ans;
    }
};