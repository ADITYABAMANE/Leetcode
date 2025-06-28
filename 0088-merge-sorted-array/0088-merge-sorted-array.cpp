class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>temp;
        for(int i=0;i<m;i++){
            temp.push_back(nums1[i]);
        }
        for(int j=0;j<n;j++){
            temp.push_back(nums2[j]);
        }

        sort(temp.begin(),temp.end());
        // nums1.clear();
        int s=temp.size();
        for(int z=0;z<s;z++){
            nums1[z]=temp[z];

        }
        
    }
};