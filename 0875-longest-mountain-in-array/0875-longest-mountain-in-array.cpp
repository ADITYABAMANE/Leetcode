class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size(), maxLen = 0, i = 1;
        while (i < n - 1) {
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
                int left = i - 1, right = i + 1;
                while (left && arr[left - 1] < arr[left]) --left;
                while (right < n - 1 && arr[right] > arr[right + 1]) ++right;
                maxLen = max(maxLen, right - left + 1);
                i = right;
            } 
            else ++i;
        }
        return maxLen;
    }
};
