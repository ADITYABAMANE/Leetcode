class Solution {
public:

    int solve(string &str,int ind, int &n,vector<int>&dp){
        if(ind==n){
            return 1;

        }
        if(str[ind]=='0'){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int pick_one_digit=solve(str, ind+1,n,dp);
        int pick_two_digit=0;

        if(ind+1<n){

        if(str[ind]=='1' || (str[ind]=='2' && str[ind+1]<='6')){

        pick_two_digit=solve(str, ind+2,n,dp);}}


        return dp[ind]=pick_one_digit + pick_two_digit;


    }

    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n,-1);

        return solve (s, 0, n,dp);
        
    }
};