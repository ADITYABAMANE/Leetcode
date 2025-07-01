class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int n=s.length();
        int maxlen=0;
        

        map<char,int>mp;
        int mxfreq=0;

        for(int right=0;right<n;right++){
            mp[s[right]]++;
            mxfreq=max(mxfreq,mp[s[right]]);



            int len=right-left+1;
            int diff=len-mxfreq;

            if(diff>k){
                mp[s[left]]--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);


        }
        return maxlen;
        
    }
};