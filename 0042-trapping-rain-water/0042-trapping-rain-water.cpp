class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        

        vector<int>leftmaxes(n);
        leftmaxes[0]=height[0];
        for(int i=1;i<n;i++){
            leftmaxes[i]= max(leftmaxes[i-1],height[i]);

        }
        




        vector<int>rightmaxes(n);
        rightmaxes[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightmaxes[i]= max(rightmaxes[i+1],height[i]);
            
        }

        int water=0;
        for(int i=0;i<n;i++){
            water+=abs(min(leftmaxes[i],rightmaxes[i])- height[i]);
        }


        return water;

        


        
    }
};