class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int n=nums.size();
        int maxlen=0;

        map<int,int>mp;
        int currsum=0;
        mp[0]=-1;

        for(int i=0;i<n;i++){
            currsum+=nums[i]==0 ?-1:1;

            if(mp.find(currsum)!=mp.end()){
                maxlen=max(maxlen,i-mp[currsum]);
            }
            else{
            mp[currsum]=i;}
        }
        return maxlen;
        
        
    }
};