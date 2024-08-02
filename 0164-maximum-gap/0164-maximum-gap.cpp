class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int result=0;
        sort(nums.begin(),nums.end());
        int prev=0;
        int curr=1;
        if(n<2)return 0;
        while(curr<n){
           int difference=(nums[curr]-nums[prev]);
           result=max(result,difference);
           curr++;
           prev++;





        }
        return result;
        

        
    }
};