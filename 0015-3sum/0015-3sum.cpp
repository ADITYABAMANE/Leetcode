class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n=nums.size();

        if(n<3)return {};

        sort(nums.begin(),nums.end());
        set<vector<int>>st;

        for(int i=0;i<n-2;i++){

            int left=i+1;
            int right=n-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];

                if(sum==0){
                st.insert({nums[i], nums[left], nums[right]});
                
                left++;
                right--;
                }
                else if(sum<0){
                    left++;
                }
                else{
                    right--;

                }




            }




        }
        return vector<vector<int>>(st.begin(),st.end());
        
        



        
    }
};