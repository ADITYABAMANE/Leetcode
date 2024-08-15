class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;

        }
        for(auto it:mp){
            if(it.second==edges.size()){
                ans=it.first;
                
            }
        }
        return ans;
        
    }
};