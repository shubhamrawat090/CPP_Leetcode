class Solution {
    typedef pair<int, int> P;

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num: nums) { // O(N)
            freq[num]++;
        }

        priority_queue<P, vector<P>, greater<P>> minHeap;
        for(auto& entry: freq) { // O(k)
            minHeap.push({entry.second, entry.first}); // O(log k)
            if(minHeap.size() > k) minHeap.pop();
        }

        vector<int> ans;
        while(!minHeap.empty()) { // O(k)
            int top = minHeap.top().second;
            ans.push_back(top); 
            minHeap.pop(); // O(log k)
        }

        return ans;
    }
};