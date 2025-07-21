class Solution {
public:
    void solve(int ind,vector<int>& nums, vector<int>&temp,vector<vector<int>>& res){
        int n=nums.size();

        if(ind>=n){
            res.push_back(temp);
            return ;

        }

        temp.push_back(nums[ind]);
        solve(ind+1,nums,temp,res);
        temp.pop_back();
        solve(ind+1,nums,temp,res);






    }




    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>res;
        vector<int>temp;
        sort(nums.begin(), nums.end());

         solve(0,nums,temp,res);

         set<vector<int>>st(res.begin(),res.end());

         vector<vector<int>>ans(st.begin(),st.end());

         return ans;
    }
};