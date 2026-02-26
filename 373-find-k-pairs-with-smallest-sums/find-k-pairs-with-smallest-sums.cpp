class Solution {
public:
    typedef pair<int, pair<int, int>> P;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        int m = nums1.size();
        int n = nums2.size();

        priority_queue<P, vector<P>, greater<P>> pq;
        set<pair<int, int>> visited;

        pq.push({nums1[0] + nums2[0], {0, 0}});
        visited.insert({0, 0});

        vector<vector<int>> ans;
        while (k-- && pq.size() > 0) {
            auto top = pq.top();
            pq.pop();

            int i = top.second.first; 
            int j = top.second.second;
            ans.push_back({nums1[i], nums2[j]});

            // next possible, (i+1, j), (i, j+1)
            // try i+1, j
            if (i + 1 < m && visited.find({i + 1, j}) == visited.end()) {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                visited.insert({i+1, j});
            }
            // try i, j+1
            if (j + 1 < n && visited.find({i, j + 1}) == visited.end()) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                visited.insert({i, j+1});
            }
        }

        return ans;
    }
};