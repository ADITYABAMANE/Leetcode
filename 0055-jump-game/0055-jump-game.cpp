class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int minjump=0;
        for(int i=n-2;i>=0;i--){

            minjump++;
            if(nums[i]>=minjump){
                minjump=0;
            }
        }
        if(minjump==0)return true;
        return false;
        
    }
};