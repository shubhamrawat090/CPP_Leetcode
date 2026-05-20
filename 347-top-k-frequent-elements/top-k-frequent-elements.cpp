class Solution {
    typedef pair<int, int> P;
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int, int> freqMap;
        for(int val: arr) {
            freqMap[val]++;
        }
        priority_queue<P, vector<P>, greater<P>> minQ;
        for(auto& entry: freqMap) {
            int val = entry.first, freq = entry.second;
            minQ.push({freq, val});
            if(minQ.size() > k) minQ.pop();
        }
        vector<int> ans;
        while(!minQ.empty()) {
            int val = minQ.top().second;
            minQ.pop();
            ans.push_back(val);
        }
        return ans;
    }
};