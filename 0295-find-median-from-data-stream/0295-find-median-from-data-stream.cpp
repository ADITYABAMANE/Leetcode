class MedianFinder {
public:
multiset<int>m;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        m.insert(num);
        
    }
    
    double findMedian() {
        int n=m.size();

        auto it=m.begin();
        advance(it,n/2);

        auto it2=it;
        it2--;
        if(n%2==0){
            double median=(*it + *it2)/2.0;
            return median;
        }

        return *it;

        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */