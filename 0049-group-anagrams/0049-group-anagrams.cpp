class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(string s:strs){
            string t=s;
            sort(t.begin(),t.end());
            mp[t].push_back(s);

        }
        vector<vector<string>>anagrams;
        for(auto it:mp){
            anagrams.push_back(it.second);
        }
        return anagrams;
        
    }
};