class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
         long long ans=0;
         int minkpos=-1;
         int maxkpos=-1;
         int culpritindex=-1;

         for(int i=0;i<nums.size();i++){

            if(nums[i]<minK || nums[i]>maxK){
                culpritindex=i;
            }
            if(nums[i]==minK){
                minkpos=i;

            }
            if(nums[i]==maxK){
                maxkpos=i; 

            }
            long long  smaller=min(minkpos,maxkpos);
            long long temp=smaller-culpritindex; 
            ans+=(temp<=0) ?0:temp;

         }
         return ans;
        
    }
};