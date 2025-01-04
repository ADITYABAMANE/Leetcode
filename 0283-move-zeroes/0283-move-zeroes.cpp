class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        vector<int>nums1;
        
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cnt++;
            }
            if(nums[i]!=0){
                nums1.push_back(nums[i]);
            }
        }
        while(cnt>0){
            nums1.push_back(0);
            cnt--;
        }
        nums.clear();
        for(int i=0;i<nums1.size();i++){
            nums.push_back(nums1[i]);
        }
       



        
    }
};