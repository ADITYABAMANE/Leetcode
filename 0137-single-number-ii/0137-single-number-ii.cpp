class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>mp;
        int final_ans=-1;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;

        }
        
        for(auto it: mp){
            if(it.second==1){
                final_ans=it.first;
                break;
            }
        }
        return final_ans;


    }
};