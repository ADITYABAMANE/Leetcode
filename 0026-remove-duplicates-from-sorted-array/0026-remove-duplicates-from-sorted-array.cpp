class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s;
        for(auto it:nums){
            s.insert(it);
        }
        
        nums.clear();
        for(auto it=s.begin();it!=s.end();it++){
            nums.push_back(*it);
        }
        return nums.size();
    }
};