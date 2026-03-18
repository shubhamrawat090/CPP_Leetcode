class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeap;
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<k-1; i++) {
            maxHeap.push({nums[i], i});
        }

        for(int i=k-1; i<n; i++) {
            maxHeap.push({nums[i], i});
            while(!maxHeap.empty() && maxHeap.top().second < i - k + 1) {
                maxHeap.pop();
            }
            ans.push_back({maxHeap.top().first});
        }

        return ans;
    }
};