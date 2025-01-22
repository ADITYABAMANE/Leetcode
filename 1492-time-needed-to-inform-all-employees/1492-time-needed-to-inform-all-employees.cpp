class Solution {

    private:
    int ans=0;
    int mx=0;
    void dfs(int managerx,vector<int>& informTime, unordered_map<int, vector<int>>&mp){
        mx=max(mx,ans);
        for(auto emploee:mp[managerx]){
            ans+=informTime[managerx];
            dfs(emploee,informTime,mp);
            ans-=informTime[managerx];



        }







    }


public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {

        unordered_map<int, vector<int>>mp;
        for(int i=0;i<n;i++){
            int val=manager[i];
            if(val!=-1){
                mp[val].push_back(i);
            }
           
        }
        dfs(headID,informTime,mp);
        return mx;


        
    }
};