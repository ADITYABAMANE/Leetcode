class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int count = 1;

        for (int j = 1; j <= chars.size(); j++) {
            if (j < chars.size() && chars[j] == chars[j - 1]) {
                count++;
            } else {
                chars[i] = chars[j - 1];
                i++;

                if (count > 1) {
                    for (char digit : to_string(count)) {
                        chars[i] = digit;
                        i++;
                    }
                }

                count = 1;
            }
        }

        return i;
    }
};
