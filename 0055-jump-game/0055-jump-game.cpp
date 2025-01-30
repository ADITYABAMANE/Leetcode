class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        int minj=0;
        for(int i=n-2;i>=0;i--){
            minj++;
            if(nums[i]>=minj){
                minj=0;
            }
        }
        if(minj==0)return true;
        return false;
    }
};