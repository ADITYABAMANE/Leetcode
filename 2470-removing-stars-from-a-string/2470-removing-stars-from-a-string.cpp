class Solution {
public:
    string removeStars(string s) {
        string newstr="";
        for(int i=0;i<s.length();i++){
            if(s[i]!='*'){
                newstr+=s[i];
            }
            else{
            newstr.pop_back();}

        }
        return newstr;
        
    }
};