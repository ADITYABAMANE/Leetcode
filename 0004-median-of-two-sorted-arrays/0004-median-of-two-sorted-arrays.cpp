class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merged_array;
       double ans;
        for(int i=0;i<nums1.size();i++){
            merged_array.push_back(nums1[i]);
        }
        for(int j=0;j<nums2.size();j++){
            merged_array.push_back(nums2[j]);
        }
        int n=merged_array.size();
        sort(merged_array.begin(),merged_array.end());
        if(n%2!=0){
        ans=merged_array[n/2];}
        else{
            ans=(merged_array[n/2] + merged_array[(n/2)-1] )/2.0;
            
        }

        return ans;
        
        
    }
};