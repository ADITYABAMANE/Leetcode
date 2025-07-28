class Solution {
public:

    bool palindrome(int start, int end, string &s){
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
        int n=s.length();
        string res="";
        int res_length=0;

        for(int i=0;i<n;i++){



            for(int j=i;j<n;j++){

                if(palindrome(i,j,s)){
                    if(res_length<j-i+1){
                        res=s.substr(i,j-i+1);
                        res_length=j-i+1;
                    }
                }


            }
        }
        return res;
        
    }
};