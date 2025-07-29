class Solution {
public:

    int solve(string &s,int ind, vector<int>&dp){
        int n=s.length();
        if(s[ind]=='0'){
            return 0;
        }
        if(ind==n){
            return 1;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }

        int take_one_digit=solve(s,ind+1,dp);
        int take_two_digit=0;

        if(ind+1<n){

        if(s[ind]=='1' || s[ind]=='2' && s[ind+1]<='6'){
         take_two_digit=solve(s,ind+2,dp);}}

        return  dp[ind]=take_one_digit + take_two_digit;

    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        return solve(s,0,dp);


        
        
    }
};