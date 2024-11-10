class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int longl=0;
        int currl=1;
        sort(nums.begin(),nums.end());
        if(nums.size()==1)return 1;
        if(nums.size()==0)return 0;

        for(int j=1;j<n;j++){
            if(nums[j]==nums[j-1]){
                
                continue;
            }
            if(nums[j]-nums[j-1]==1){
                currl++;
               
            }
            if(nums[j]-nums[j-1]>=2){
                currl=1;
            }
            longl=max(longl,currl);





        }
        return max(longl,currl);
        
    }
};