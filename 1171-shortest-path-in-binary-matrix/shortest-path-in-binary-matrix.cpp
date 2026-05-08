class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return -1; // No way to start
        int n = grid.size();
        queue<pair<int, int>> q;
        int dist = 1;
        q.push({0, 0}); 
        grid[0][0] = -1; // Mark visited
        vector<vector<int>> dirs = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},
            {-1, 1}, {1, 1}, {1, -1}, {-1, -1}
        };
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto top = q.front();
                q.pop();
                int i = top.first, j = top.second;
                if(i == n-1 && j == n-1) {
                    return dist; // Reached last block
                }

                for(auto& dir: dirs) {
                    int x = i + dir[0], y = j + dir[1];
                    if(x >= 0 && x < n && y >= 0 && y < n) {
                        if(grid[x][y] == 0) {
                            grid[x][y] = -1; // Mark visited
                            q.push({x, y});
                        }
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};