class MedianFinder {
    double median;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {
        this->median = 0.0;
        this->minHeap = {};
        this->maxHeap = {};
    }

    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // Update median
        if (maxHeap.size() > minHeap.size()) {
            median = maxHeap.top();
        } else {
            median = (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }

    double findMedian() { return this->median; }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */