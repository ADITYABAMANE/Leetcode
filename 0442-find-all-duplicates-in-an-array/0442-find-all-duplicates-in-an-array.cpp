class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>duplicates;
        unordered_map<int,int>mp;
        for(auto num :nums){
            mp[num]++;
        }
        for(auto it:mp){
            if(it.second>1)duplicates.push_back(it.first);
        }
        return duplicates;
        
    }
};