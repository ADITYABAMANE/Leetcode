class Solution {
    int mini=0;
    int mx=0;
    public:

    void dfs(int mmanager, vector<int>& informTime, unordered_map<int,vector<int>>&mp ){
        mx=max(mx,mini);
        for(auto submanager:mp[mmanager]){
            mini+=informTime[mmanager];
            dfs(submanager,informTime,mp);
            mini-=informTime[mmanager];
        }

    }



public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {

     unordered_map<int,vector<int>>mp;   

     //to make a adjacency list
     for(int i=0;i<n;i++){
        if(manager[i]!=-1){
            mp[manager[i]].push_back(i);

        }
     }
     dfs(headID,informTime,mp);
     return mx;
    }

};