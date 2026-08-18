class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                } else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if(fresh == 0) return 0; // All of the oranges are rotten
        if(q.empty()) return -1; // No rotten orange present --> IMPOSSIBLE TO ROT ALL


        int time = 0;

        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto top = q.front();
                q.pop();
                int i = top.first, j = top.second;

                for(auto& dir: dirs) {
                    int x = i + dir[0], y = j + dir[1];

                    if(x < 0 || x >= rows || y < 0 || y >= cols) continue;
                    if(grid[x][y] != 1) continue;

                    grid[x][y] = 2; // mark rotten(visited)
                    q.push({x, y});
                    fresh--;
                }
            }
            time++; // Previous lvl is processed --> move on to next level
        }

        return fresh != 0 ? -1 : time - 1;
    }
};