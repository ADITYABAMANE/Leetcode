class Solution {
public:
    int maxArea(vector<int>& height) {
       //using the sliding window problem
        int n=height.size();
        int left=0;
        int right=n-1;
        int max_area=0;
        int area=0;
        while(left<right){

            
            //area=l*b


            area=(right-left) * min(height[left],height[right]);
            max_area=max(max_area,area);

            if(height[left]>height[right]){
                right--;

            }
            else{left++;
            }
        }

        return max_area;

        

        
    }
};