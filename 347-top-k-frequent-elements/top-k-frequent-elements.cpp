class Solution {
    typedef pair<int, int> P;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num: nums) freq[num]++;
        priority_queue<P, vector<P>, greater<P>> minHeap;
        for(auto entry: freq) {
            int num = entry.first;
            minHeap.push({freq[num], num});
            if(minHeap.size() > k) minHeap.pop();
        }
        vector<int> ans;
        while(!minHeap.empty()) {
            auto entry = minHeap.top();
            minHeap.pop();
            ans.push_back({entry.second});
        }
        return ans;
    }
};