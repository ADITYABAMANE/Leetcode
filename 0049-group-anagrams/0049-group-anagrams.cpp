class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>a;
        map<string,vector<string>>mp;

        for(auto s:strs){
            string temp=s;
            sort(temp.begin(),temp.end());

            mp[temp].push_back(s);
            




        }
        for(auto it:mp){
            a.push_back(it.second);
        }
        return a;
        
    }
};