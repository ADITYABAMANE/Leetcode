class Solution {
public:


    int solve(string &s, int ind, int n,vector<int>&dp){
        if(ind==n){
            return 1;
        }
        if(s[ind]=='0'){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }

        int pick_ith_index=solve(s,ind+1,n,dp);
        int pick_ith_and_iplusoneth_index=0;

        if(ind+1<n){

        if(s[ind]== '1' || ( s[ind] == '2' && s[ind+1]<= '6' )){

        pick_ith_and_iplusoneth_index=solve(s,ind+2,n,dp);}}


        return dp[ind]= pick_ith_index+ pick_ith_and_iplusoneth_index;






    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n,-1);

        return solve(s, 0,n,dp);

        
    }
};