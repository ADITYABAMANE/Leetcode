class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int missno=1;
        for(int i=0;i<nums.size();i++){
             if(nums[i]==missno){
                missno++;
             }
             else{
                if(nums[i]>missno){
                    break;
                }
             }
        }
        return missno;

        
    }
};