class Solution {
public:
int maxlen=0;

        int currsum=0;
    int findMaxLength(vector<int>& nums) {
        map<int,int>mp;
        mp[0]=-1;
        
        
        for(int i=0;i<nums.size();i++){
           if(nums[i]==0) {
            currsum-=1;
           }
           else{
            currsum+=1;
           }

           if(mp.find(currsum)!=mp.end()){
            maxlen=max(maxlen,i-mp[currsum]);
           }
           else{
            mp[currsum]=i;
           }


            
        }
        return maxlen;
        
    }
};