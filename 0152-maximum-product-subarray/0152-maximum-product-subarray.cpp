class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int mul;
        int max_p=0;
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n;i++){

            mul=1;
            
            for(int j=i;j<n;j++){

                mul*=nums[j];
                max_p=max(max_p,mul);
            }

        }
        return max_p;
        
    }
};