class Solution {
public:
    bool isAnagram(string s, string t) {

        map<char, int>m1;
        
        for(char ch:s){
            m1[ch]++;

        }
        for(char ch1:t){
            m1[ch1]--;

        }
        for(auto d:m1){
            if(d.second!=0){
                return false;
            }
           

        }
        return true;


        
    }
};