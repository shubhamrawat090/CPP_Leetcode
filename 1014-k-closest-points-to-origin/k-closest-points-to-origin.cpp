class Solution {
    typedef pair<int, vector<int>> P;

    struct Compare {
        bool operator()(const auto& a, const auto& b) {
            return a.first < b.first;
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // custom priority queue needed - a maxheap(distance b/w 0,0(origin) and x,y is largest first)
        // in order to remove them fastest
        // maintain heap.size == k
        int n = points.size();
        priority_queue<P, vector<P>, Compare> pq;

        for(int i=0; i<n; i++) {
            int x = points[i][0], y = points[i][1];
            int dist = x*x + y*y;
            pq.push({dist, {x, y}});
            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()) {
            vector<int> pts = pq.top().second;
            pq.pop();
            ans.push_back(pts); 
        }

        return ans;
    }
};