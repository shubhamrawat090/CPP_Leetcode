class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshOranges = 0;
        int rows = grid.size(), cols = grid[0].size();
        queue<vector<int>> q;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                } else if(grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        if(freshOranges == 0) return 0; // No fresh oranges present to rot
        if(q.empty()) return -1; // No rotten oranges present

        int time = 1;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto top = q.front();
                q.pop();
                int i = top[0], j = top[1];

                for(auto& dir: dirs) {
                    int x = i + dir[0], y = j + dir[1];
                    if(x >= 0 && x < rows && y >= 0 && y < cols) { // Within bounds
                        if(grid[x][y] == 1) {
                            grid[x][y] = 2; // Rot the fresh orange
                            freshOranges--;

                            if(freshOranges == 0) return time;

                            q.push({x, y});
                        }
                    }
                }
            }
            time++;
        }

        return -1;
    }
};