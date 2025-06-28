class Solution {
    private:
    bool ispalindrome(string &stz,int i,int j){
        int n=stz.length();
        

        // i=0;
        // j=n-1;
        while(i<j){
            if(stz[i]!=stz[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;

    }
public:
int ini=-1;
    string longestPalindrome(string s) {

        int n=s.length();
       
        
        int maxlen=0;
        for(int start=0;start<n;start++){
           
            for(int end=start;end<n;end++){
              
               if(ispalindrome(s,start,end)){
                if(end-start+1>maxlen){
                    maxlen=end-start+1;
                    ini=start;




                }

               } 
            }

        }
        return s.substr(ini,maxlen);
        
    }
};