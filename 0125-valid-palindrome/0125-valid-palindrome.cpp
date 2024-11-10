class Solution {
public:
    bool isPalindrome(string s) {
        string cleanedstring="";
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i])){
                cleanedstring+=tolower(s[i]);

            }
        }
        string sample=cleanedstring;
        reverse(sample.begin(),sample.end());
        if(cleanedstring==sample){
            return true;
        }
        return false;
    }
};