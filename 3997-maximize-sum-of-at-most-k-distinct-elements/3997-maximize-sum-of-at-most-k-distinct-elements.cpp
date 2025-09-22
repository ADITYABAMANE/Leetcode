class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
       
        unordered_set<int> st(nums.begin(), nums.end());

       
        vector<int> uq(st.begin(), st.end());

        
        sort(uq.rbegin(), uq.rend());

       
        vector<int> res;
        for (int i = 0; i < min(k, (int)uq.size()); i++) {
            res.push_back(uq[i]);
        }

        return res;
    }
};
