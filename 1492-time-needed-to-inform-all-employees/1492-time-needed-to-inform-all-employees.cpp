class Solution {
    
public:
int ans=0;
int mx=0;
    void dfs(int mainman,vector<int>& informTime, unordered_map<int,vector<int>>&mp){
        mx=max(mx,ans);

        for(auto  emploee:mp[mainman]){
            ans+=informTime[mainman];
            dfs(emploee,informTime,mp);
            ans-=informTime[mainman];
        }

    }


    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                mp[manager[i]].push_back(i);
            }
        }
        dfs(headID,informTime,mp);
        return mx;

        
    }
};