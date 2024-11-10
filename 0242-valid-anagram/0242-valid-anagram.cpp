class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mp1;
        map<char,int>mp2;
        for(char c1:s){
            mp1[c1]++;
        }
        for(char c2:t){
            mp1[c2]--;
        }
        for(auto it:mp1){
            if(it.second!=0){
                return false;

            }
        }
        return true;

        
    }
};