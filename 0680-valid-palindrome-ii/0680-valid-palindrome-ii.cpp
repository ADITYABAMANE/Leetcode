class Solution {
public:

    bool checkpal(string s, int left,int right){
        while(left<=right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;

        }
        return true;

    }

    bool validPalindrome(string s) {

        int l=0;
        int r=s.length()-1;
        while(l<=r){

            if(s[l]!=s[r]){
               
                    return checkpal(s,l+1,r) || checkpal(s,l,r-1);
                
            }
            l++;
            r--;



        }
        return true;
        
    }
};