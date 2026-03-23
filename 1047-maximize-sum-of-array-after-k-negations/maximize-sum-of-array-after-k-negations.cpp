class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int num: nums) {
            minHeap.push(num);
        } 

        for(int i=0; i<k; i++) {
            int top = minHeap.top();
            minHeap.pop();
            minHeap.push(-top);
        }

        int sum = 0;
        while(!minHeap.empty()) {
            sum += minHeap.top();
            minHeap.pop();
        }

        return sum;
    }
};