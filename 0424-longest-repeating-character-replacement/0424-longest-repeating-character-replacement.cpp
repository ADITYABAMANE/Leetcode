class Solution {
public:
 int maxlen=0;
    int characterReplacement(string s, int k) {
        int n=s.length();

        int i=0;
        int j=i;
        map<int,int>mp;
        int maxfreq=0;
        int maxlen=0;
        while(j<n){
            mp[s[j]]++;

            maxfreq=max(maxfreq,mp[s[j]]);
            int chardiff=(j-i+1)-maxfreq;

            if(chardiff>k){
                mp[s[i]]--;
                i++;
            }
            maxlen=max(maxlen,j-i+1);
            j++;

        }
        return maxlen;
       
        
        
    }
};