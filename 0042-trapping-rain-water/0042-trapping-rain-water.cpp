class Solution {
public:
    int trap(vector<int>& height) {
        ///the formula for getting the amount of water a point is 
        //water+=min(leftmax,rightmax)-height[i];
        //my goal if one pointer at ledt, other at right, shrinking and storing the leftmax and rightmax on the way;

        int n=height.size();
         if(n == 0) return 0;

        int left=0;
        int right=n-1;
        int leftmax=height[0];
        int rightmax= height[n-1];
        int water=0;

        while(left<right){

            if(leftmax<rightmax){
                left++;
                
                leftmax=max(leftmax,height[left]);
                water+=leftmax-height[left];
            }
            else{
                right--;
                
                rightmax=max(rightmax,height[right]);
                water+=rightmax-height[right];
            }

           


        }
        return water;

        
    }
};