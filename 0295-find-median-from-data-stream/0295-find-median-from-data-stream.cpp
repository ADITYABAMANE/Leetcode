class MedianFinder {
public:
    multiset<int> arr; // Use multiset in case duplicates are allowed

    MedianFinder() {
    }

    void addNum(int num) {
        arr.insert(num);
    }

    double findMedian() {
        int n = arr.size();
        auto it = arr.begin();

        advance(it, n / 2);

        if (n % 2 == 0) {
            auto it2 = it;
            --it2; // points to (n/2 - 1)th element
            return (*it + *it2) / 2.0;
        } else {
            return *it;
        }
    }
};
