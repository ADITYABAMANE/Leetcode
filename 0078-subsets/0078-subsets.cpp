class Solution {
public:
    void solve(vector<int>nums,int ind,int n,vector<int>&temp,vector<vector<int>>&res){
        n=nums.size();
        if(ind>=n){
            res.push_back(temp);
            return ;

        }

        temp.push_back(nums[ind]);
        solve(nums,ind+1,n,temp,res);
        temp.pop_back();
        solve(nums,ind+1,n,temp,res);

    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
            vector<vector<int>>res;
            
        
            solve(nums, 0, n,temp,res);
            set<vector<int>>st(res.begin(),res.end());
            vector<vector<int>>final(st.begin(),st.end());

            return final;





    }
};