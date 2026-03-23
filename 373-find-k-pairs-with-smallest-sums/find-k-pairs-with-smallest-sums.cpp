class Solution {
    typedef pair<int, pair<int, int>> P;

public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // add first full row(nums1[i: 0 -> min(k, nums1.size())], nums2[0])
        int m = nums1.size(), n = nums2.size();
        priority_queue<P, vector<P>, greater<P>> pq;

        for(int i=0; i<min(k, m); i++) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        vector<vector<int>> ans;
        while(k > 0 && !pq.empty()) {
            P top = pq.top(); pq.pop();
            int i = top.second.first;
            int j = top.second.second;

            ans.push_back({nums1[i], nums2[j]});

            if(j + 1 < n) {
                pq.push({nums1[i] + nums2[j+1], {i, j+1}});
            }

            k--;
        }

        return ans;
    }
};