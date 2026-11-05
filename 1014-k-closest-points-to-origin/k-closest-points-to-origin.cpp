struct Coords {
    int x;
    int y;
    int dist;
};

struct cmp {
    bool operator()(const Coords& a, const Coords& b) {
        return a.dist < b.dist;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();

        priority_queue<Coords, vector<Coords>, cmp> maxHeap;

        for (int i = 0; i < n; i++) {
            Coords c;
            c.x = points[i][0];
            c.y = points[i][1];
            c.dist = (c.x * c.x) + (c.y * c.y);

            maxHeap.push(c);

            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        vector<vector<int>> ans(k);
        int i = 0;
        while (!maxHeap.empty()) {
            Coords c = maxHeap.top();
            maxHeap.pop();

            ans[i] = {c.x, c.y};
            i++;
        }

        return ans;
    }
};