class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int count = 0;
        int n = arr.size();

        for(int i=0;i<arr.size();i++){
            int left = i+1;
            int right = n-i;

            int totalSum = left * right;
            int SubArraySum = (totalSum + 1) / 2;

            count += arr[i] * SubArraySum;
        }
        return count;
    }
};