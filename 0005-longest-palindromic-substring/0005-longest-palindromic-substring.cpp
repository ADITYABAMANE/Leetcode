class Solution {
public:
    string longestPalindrome(string s) {

        int n=s.length();
        string res="";
        int result_length=0;

        for(int i=0;i<n;i++){

       //odd length string

        int l=i,r=i;

        while(l>=0 && r<n && s[l]==s[r]){
            if(r-l+1>result_length){
                res=s.substr(l,r-l+1);
                result_length=r-l+1;
            }
            l--;
            r++;
        }


        //even length string

        l=i;
        r=i+1;
         while(l>=0 && r<n && s[l]==s[r]){
            if(r-l+1>result_length){
                res=s.substr(l,r-l+1);
                result_length=r-l+1;
            }
            l--;
            r++;
        }



        }
        return res;
        
    }
};