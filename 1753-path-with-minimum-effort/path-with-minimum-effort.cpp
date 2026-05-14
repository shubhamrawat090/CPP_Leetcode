class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, 1e6));
        dist[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            q;
        q.push({0, 0, 0});
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto top = q.top();
            q.pop();
            int i = top[1], j = top[2], w = top[0];
            for (auto& dir : dirs) {
                int x = i + dir[0], y = j + dir[1];
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    int effort = abs(heights[x][y] - heights[i][j]);
                    if (max(w, effort) < dist[x][y]) {
                        dist[x][y] = max(w, effort);
                        q.push({dist[x][y], x, y});
                    }
                }
            }
        }

        return dist[rows - 1][cols - 1];
    }
};