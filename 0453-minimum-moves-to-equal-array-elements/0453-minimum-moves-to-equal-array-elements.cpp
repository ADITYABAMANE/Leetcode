class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min=*min_element(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=abs(min-nums[i]);
        }
        return ans;
        
    }
};