class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int>tot(26, 0);
        for(char c : s){
            if(c!='?')
                tot[c-'a']++;
        }
        vector<char>added;
        for(int i = 0;i<s.length();i++){
            if(s[i]=='?'){
                int maxfre = INT_MAX;
                char ch = '-1';
                for(int j = 0;j<26;j++){
                    if(maxfre>tot[j]){
                        maxfre = tot[j];
                        ch = j+'a';
                    }
                }
                tot[ch-'a']++;
                added.push_back(ch);
            }
        }
        int j = 0;
        sort(added.begin(), added.end());
        for(int i = 0;i<s.length();i++){
            if(s[i]=='?'){
                s[i]  = added[j];
                j++;
            }
        }
        return s;
    }
};