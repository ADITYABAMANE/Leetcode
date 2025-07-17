class Solution {
public:


 void findcombinations(int ind, int target , vector<int>& candidates, vector<int>&v,        vector<vector<int>>&ans){

    if(ind==candidates.size()){
        if(target==0){
            ans.push_back(v);

        }
        return ;
    }

    //pick
    if(candidates[ind]<=target){
        v.push_back(candidates[ind]);
        findcombinations(ind, target-candidates[ind] ,candidates,v,ans);
        v.pop_back();

    }
    //not pick
    findcombinations(ind+1,target,candidates,v,ans);
    

        

        


    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

         vector<vector<int>>ans;
        vector<int>v;

        findcombinations(0,target,candidates,v,ans);

        return ans;
        
    }
};