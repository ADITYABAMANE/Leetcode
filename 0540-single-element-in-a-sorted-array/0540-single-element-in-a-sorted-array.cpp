class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int,int>mp;
        int a;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;




      }
      for(auto it : mp){
        if(it.second==1){
             a=it.first;
            break;
            
        }
      }
      return a;
        
    }
};