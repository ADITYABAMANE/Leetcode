class Solution {
private:
    int triplet(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int> map;
        for(int j = 0, m = nums2.size(); j < m; ++j) ++map[nums2[j]];
        int n = nums1.size(), res = 0;
        for(int i = 0; i < n; ++i){
            long target = 1L * nums1[i] * nums1[i];
            for(auto& [b , cnt] : map){
                if(target % b || !map.count(target / b)) continue;
                if(target / b == b) res += cnt * (cnt - 1);
                else res += cnt * map[target / b];
            }
        }
        return res / 2;
    }
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return triplet(nums1 , nums2) + triplet(nums2 , nums1);
    }
};