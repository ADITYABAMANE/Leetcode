class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int missingnumber=1;
        for(int num:nums){
            if(num>0){
                if(missingnumber==num){
                    missingnumber++;
                }
                else if(num>missingnumber){
                    break;

                }

            }

        }
        return missingnumber;
        
    }
};