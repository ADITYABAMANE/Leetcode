
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        std::unordered_map<int, int> boxCount;
        int maxBalls = 0;

        for (int i = lowLimit; i <= highLimit; i++) {
            int sum = 0, num = i;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            maxBalls = std::max(maxBalls, ++boxCount[sum]);
        }

        return maxBalls;
    }
};