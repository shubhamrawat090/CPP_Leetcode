class MedianFinder {
    // Maintain lower half                              Maintain upper half
    // --------- highest val(use maxHeap)         lowest val(use minHeap) -------------
    // Median is somewhere in between

    // 1 THING TO MAKE SURE: lowerHalf.size() SHOULDN'T EXCEED upperHalf.size() + 1

    // DIFFERENCE OF 1 ELEMENT SHOULD BE MAINTAINED between both halves

    priority_queue<int> lowerHalf;
    priority_queue<int, vector<int>, greater<int>> upperHalf;

public:
    MedianFinder() {
        lowerHalf = {};    
        upperHalf = {};    
    }
    
    void addNum(int num) {
        if(lowerHalf.empty() || num <= lowerHalf.top()) {
            lowerHalf.push(num);
        } else {
            upperHalf.push(num);
        }

        // Rebalance
        if(lowerHalf.size() > upperHalf.size() + 1) {
            // Remove 1 element from lowerHalf and push it to upperHalf
            upperHalf.push(lowerHalf.top());
            lowerHalf.pop();
        } else if(upperHalf.size() > lowerHalf.size()) {
            // Remove 1 element from upperHalf and push it to lowerHalf
            lowerHalf.push(upperHalf.top());
            upperHalf.pop();
        }
    }
    
    double findMedian() {
        if(lowerHalf.size() > upperHalf.size()) {
            return lowerHalf.top();
        } else {
            return (lowerHalf.top() + upperHalf.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */