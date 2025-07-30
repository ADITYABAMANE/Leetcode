class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end()); // Insert all elements into a set for O(1) lookups
        int maxlen = 0;

        // Iterate over each number in the input array
        for (int num : st) {
            // Check if it's the start of a sequence
            if (st.find(num - 1) == st.end()) {
                int currnum = num;
                int len = 1;

                // Count all consecutive numbers
                while (st.find(currnum + 1) != st.end()) {
                    currnum++;
                    len++;
                }

                // Update the max length found so far
                maxlen = max(maxlen, len);
            }
        }

        return maxlen;
    }
};
