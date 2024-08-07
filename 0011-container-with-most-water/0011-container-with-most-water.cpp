class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int max_water=0;

        int max_area=0;
        while(left<right){
            int max_area=(right-left)*min(height[left],height[right]);
            max_water=max(max_water,max_area);

            if(height[left]<height[right]){
                left++;

            }
            else{
                right--;
            }
            
        }
        return  max_water;
        
    }
};