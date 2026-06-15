class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeap;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < k - 1; i++) {
            maxHeap.push({nums[i], i});
        }

        for (int i = k - 1; i < n; i++) {
            maxHeap.push({nums[i], i});
            int delIdx = i - k + 1;
            int topVal = getTopVal(maxHeap, delIdx);
            ans.push_back(topVal);
        }
        return ans;
    }

    int getTopVal(priority_queue<pair<int, int>>& maxHeap, int& delIdx) {
        int size = maxHeap.size();
        int val = maxHeap.top().first;
        for (int i = 0; i < size; i++) {
            auto top = maxHeap.top();
            if (top.second < delIdx) {
                maxHeap.pop();
            } else {
                val = top.first;
                break;
            }
        }
        return val;
    }
};