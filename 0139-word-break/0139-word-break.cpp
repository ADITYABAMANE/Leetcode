class Solution {
public:

    bool solve(int idx,string &s,  unordered_set<string>&st
         , vector<int>&dp){
        int n=s.length();
        

        if(idx>=n)return true;
        // if(st.find(s)!=st.end()){
        //     return true;
        // }
        if(dp[idx]!=-1)return dp[idx];
        for(int l=1;idx+l<=n;l++){
            string temp=s.substr(idx,l);

            if(st.find(temp)!=st.end() && solve(idx+l,s,st,dp)  ){
                return dp[idx]=true;
            }

        }
        return dp[idx]=false;



    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_set<string>st;
        vector<int>dp(n,-1);
        

        //storing every word from dict in the set so its easy to acess
        for(auto it:wordDict){
            st.insert(it);

        }
        return solve(0,s,st,dp);
        
    }
};