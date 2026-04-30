class Solution {
public:
    int characterReplacement(string s, int k) {

        int n=s.length();

        int maxlen=0;
        int chardiff=0;
        int maxfreq=0;

        unordered_map<char,int >mp;

        int i=0;int j=0;

        while(j<n){
            mp[s[j]]++;
            maxfreq=max(maxfreq,mp[s[j]]);
            chardiff=(j-i+1)-maxfreq;

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