class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int i=0;
        int j=0;
        int maxlen=0;
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;


             if(mp.size()<j-i+1){
                mp[s[i]]--;

                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }

                i++;
               
               


            }

            
                
                maxlen=max(maxlen,j-i+1);
                j++;



            

           
        }
        return maxlen;
        
    }
};