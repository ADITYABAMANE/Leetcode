class Solution {
public:
    int minDeletions(string s) {
        map<char,int>mp;
        set<int>st;

        int n=s.length();

        for(int i=0;i<n;i++){
            mp[s[i]]++;

        }
        int ans=0;

        for(auto it:mp){

            int freq=it.second;


            while(freq>0 && st.count(freq)){
                freq--;
                ans++;


            }

            if(freq>0){
                st.insert(freq);

            }

        }

        return ans;



        
    }
};