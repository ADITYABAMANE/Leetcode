class Solution {
public:

    void prefixlm(vector<int>& height,vector<int>&leftmax,int n){
        
        

        leftmax[0]=height[0];

        for(int i=1;i<n;i++){
            leftmax[i]=max(leftmax[i-1],height[i]);
        }




    }
    void suffixrm(vector<int>& height,vector<int>&rightmax,int n){
        
         rightmax[n-1]=height[n-1];

        for(int i=n-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],height[i]);
        }

    }
    int trap(vector<int>& height) {
        int n=height.size();

        //if i am at a certain point, to calculate the water stored at that point , i need the leftmax till that point and right max till that point, and then will take the min of them both - height of thr bar

        vector<int>leftmax(n);
        vector<int> rightmax(n);
        prefixlm(height,leftmax,n);
        suffixrm(height, rightmax, n);
        int water=0;

        for(int i=0;i<n;i++){
            water+=min(leftmax[i],rightmax[i] )-height[i];



        }
        return water;


        
    }
};