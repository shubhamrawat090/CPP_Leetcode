class Solution {
private:
    bool bfs(vector<vector<char>>& grid, queue<vector<int>>& q, vector<vector<int>>& visited) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto top = q.front();
                q.pop();
                int x = top[0], y = top[1];
                int parentX = top[2], parentY = top[3];

                for (auto dir : dirs) {
                    int nx = x + dir[0], ny = y + dir[1];
                    if (nx >= 0 && nx < rows && ny >= 0 &&
                        ny < cols) { // within range
                        if (grid[x][y] != grid[nx][ny])
                            continue; // Continue for same value only

                        if (visited[nx][ny] &&
                            (nx != parentX || ny != parentY)) {
                            return true;
                        } else if (!visited[nx][ny]) {
                            visited[nx][ny] = 1;
                            q.push({nx, ny, x, y});
                        }
                    }
                }
            }
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        // Node, parent track
        // If nbr already visited && nbr is NOT parent --> cycle
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        queue<vector<int>> q;

        // Do BFS for all connected components - connected components have the
        // same value
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j]) {
                    q.push({i, j, -1, -1});
                    visited[i][j] = 1;

                    if (bfs(grid, q, visited))
                        return true;
                }
            }
        }

        return false;

        // [
        //     ["a","b","b"],
        //     ["b","z","b"],
        //     ["b","b","a"]
        // ]
    }
};