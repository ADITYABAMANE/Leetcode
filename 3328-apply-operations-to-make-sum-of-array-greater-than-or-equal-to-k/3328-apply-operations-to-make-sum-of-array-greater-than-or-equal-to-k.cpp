class Solution {
public:
    int minOperations(int k) {
        return floor(sqrt(k)) - 1 + (k - 1) / floor(sqrt(k));
    }
};