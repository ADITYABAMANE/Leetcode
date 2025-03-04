class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int max_water=0;
        int area=0;
        while(left<right ){
            area=min(height[left],height[right])*(right-left);
             max_water=max(max_water,area);
            if(height[left]>height[right]){
                right--;
            }
            else {
                left++;
            }
           

        }
        return max_water;
    }
};