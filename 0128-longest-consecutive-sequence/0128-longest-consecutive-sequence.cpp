class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        
            
        int currlen=1;
        int maxlen=1;
        int n=nums.size();
        int curr=1;

        while(curr<n){
            if(nums[curr]-nums[curr-1]==1){
                currlen++;
            }
            else if(nums[curr]==nums[curr-1]){
                curr++;
                continue;
                
            }
            else{
                currlen=1;
            }

            maxlen=max(maxlen,currlen);
            curr++;
        }
        return maxlen;

        
        
    }
};