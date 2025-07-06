class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int,int>mp;
        for(char c:s){
            mp[c]++;
        }
        for(char x:t){
            mp[x]--;
        }
        for(auto it:mp){
            if(it.second!=0)return false;
        }

        return true;
       
        
    }
};