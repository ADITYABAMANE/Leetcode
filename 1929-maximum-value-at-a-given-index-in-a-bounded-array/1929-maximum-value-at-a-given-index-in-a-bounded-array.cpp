class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        auto isValid = [&](int mid) -> bool {
            long long left = 0;
            if (mid > index) {
                long long first = mid - index;
                long long last = mid - 1;
                left = (first + last) * index / 2;
            } else {
                long long ones = index - (mid - 1);
                left = (long long)mid * (mid - 1) / 2 + ones;
            }

            int rightCount = n - index - 1;
            long long right = 0;
            if (mid > rightCount) {
                long long first = mid - 1;
                long long last = mid - rightCount;
                right = (first + last) * rightCount / 2;
            } else {
                long long ones = rightCount - (mid - 1);
                right = (long long)mid * (mid - 1) / 2 + ones;
            }

            return left + mid + right <= maxSum;
        };

        int l = 0, r = maxSum, result = 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isValid(mid)) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result;
    }
};