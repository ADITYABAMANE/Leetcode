class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int missno=1;

        for(int num:nums){
            if(num>0){
                if(missno==num){
                    missno++;
                }
                else if(num>missno){
                    break;
                }
            }

        }
        return missno;
        
    }
};