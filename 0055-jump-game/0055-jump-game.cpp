class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();

        int minjmp=0;

        for(int i=n-2;i>=0;i--){
            minjmp++;

            if(nums[i]>=minjmp){
                minjmp=0;
            }
        }
        return minjmp==0?true:false;

        
    }
};