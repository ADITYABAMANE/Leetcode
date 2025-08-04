class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r = n-1;

        int leftmax=height[0];
        int rightmax=height[n-1];
        int water=0;

        while(l<r){

            if(leftmax<rightmax){
                l++;
                leftmax=max(leftmax, height[l]);
                water+=leftmax-height[l];


            }
            else{
                r--;
                rightmax=max(rightmax, height[r]);
                water+=rightmax-height[r];
            }




        }
        return water;

        
        
    }
};