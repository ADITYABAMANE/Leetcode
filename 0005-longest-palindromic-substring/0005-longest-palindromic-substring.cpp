class Solution {
public:
bool ispalindrome(string &s,int x,int z){
    while(x<z){
        if(s[x]!=s[z]){
            return false;
        }
        x++;
        z--;



    }
    return true;
    





 }  

public:

    string longestPalindrome(string s) {
        int maxlen=0;
        int n=s.length();
        int start=0;
        int end=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispalindrome(s,i,j)){
                    if((j-i+1)>maxlen){
                        maxlen=j-i+1;
                        start=i;
                        

                    }
                   
                    
                    
                }
            }
        }
        return s.substr(start,maxlen);

        



        
    }
};