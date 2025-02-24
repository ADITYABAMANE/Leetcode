class Solution {
public:
string st="";

    bool ispalindrome(string s1){
        string s2=s1;
        reverse(s2.begin(),s2.end());

        if(s1==s2){
            return true;
        }
        return false;

    }



    int countSubstrings(string s) {
        int cnt=0;
        for(int i=0;i<s.length();i++){
            st="";
            for(int j=i;j<s.length();j++){
                st+=s[j];
                if(ispalindrome(st)){
                    cnt++;
                }



            }
        }
        return cnt;
        
    }
};