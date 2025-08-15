class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int>inc;
        deque<int>dec;
        int maxlen=0;
        int left=0;


        for(int i=0;i<nums.size();i++){
            int ce=nums[i];

            while(!inc.empty() && ce< inc.back() ){
                inc.pop_back();
            }
            inc.push_back(ce);

            while(!dec.empty() && ce>dec.back()){
                dec.pop_back();
            }
            dec.push_back(ce);

            while(dec.front()-inc.front()>limit){

                if(nums[left]==inc.front()){
                    inc.pop_front();
                }
                if(nums[left]==dec.front()){
                    dec.pop_front();
                }

                left++;

            }
            maxlen=max(maxlen,i-left+1);




        }
        return maxlen;
        
    }
};