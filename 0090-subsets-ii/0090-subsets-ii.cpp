class Solution {
public:

vector<vector<int>>res;

void dfs(int ind, vector<int>& nums ,vector<int>&subset){
   

    if(ind>=nums.size()){
        res.push_back(subset);
        return ;
    }

    subset.push_back(nums[ind]);
    dfs(ind+1,nums,subset);
    subset.pop_back();
    dfs(ind+1,nums,subset);




}



    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>subset;
        

        sort(nums.begin(),nums.end());


        dfs(0,nums,subset);
         set<vector<int>>st(res.begin(),res.end());
         vector<vector<int>>finalans(st.begin(),st.end());

         return finalans;

        
        
        
    }
};