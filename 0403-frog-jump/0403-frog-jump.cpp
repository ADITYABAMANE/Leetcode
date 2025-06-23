class Solution {
public:



    int n;
    map<int,int>mp;
    bool solve(vector<int>& stones, int  current_stone_index, int prevjump,vector<vector<int>>&dp){
        

        if(current_stone_index==n-1)return true;
        if(dp[current_stone_index][prevjump]!=-1){
            return dp[current_stone_index][prevjump];
        }

        for(int next_jump=prevjump-1;next_jump<=prevjump+1;next_jump++){
            if(next_jump>0){

            int next_stone=stones[current_stone_index]+next_jump;
            if(mp.find(next_stone)!=mp.end()){

                if(solve(stones,mp[next_stone],next_jump,dp))
                return dp[current_stone_index][prevjump]=true;
            }
            }

        }
        return dp[current_stone_index][prevjump] =false;


    }

    bool canCross(vector<int>& stones) {
        n=stones.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        if(stones[1]!=1)return false;
        

        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        return solve(stones,0,0,dp);

        
    }
};