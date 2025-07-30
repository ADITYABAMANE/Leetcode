class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxlen=1;
        if(n==0)return 0;

        int i=1;
        int cnt=1;
        while(i<n){
            //1,2,3,4,100,200
            //   i

            // cnt=1;
            if(nums[i]-nums[i-1]==1){
                cnt++;
                

            }
            else if(nums[i]==nums[i-1]){
                i++;
                continue;
            }
            else{
                cnt=1;

            }
            maxlen=max(maxlen, cnt);
            i++;
        }
        return maxlen;
        
    }
};