class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;

        for(int i=0;i<nums.size();i++){

            int remaining_amount=target-nums[i];

            if(mp.find(remaining_amount)!=mp.end()){
                return {mp[remaining_amount],i};
            }
            mp[nums[i]]=i;




        }
        return {};
        
    }
};