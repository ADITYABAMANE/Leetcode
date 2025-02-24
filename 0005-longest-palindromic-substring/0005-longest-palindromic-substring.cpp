class Solution {
public:

    

    bool ispalindrome(string &s,int start,int end){
       while(start<end){
        if(s[start]!=s[end]){
            return false;

        }
        start++;
        end--;
       }
       return true;

    }









    string longestPalindrome(string s) {
        int maxlen=0;
       int begin=0;
       
        for(int i=0;i<s.length();i++){
           
            for(int j=i;j<s.length();j++){
                
                if(ispalindrome(s,i,j)){
                  if(j-i+1>maxlen){
                    maxlen=j-i+1;
                    begin=i;
                  }

                }



            }

        }
        return  s.substr(begin,maxlen);
        
    }
};