class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        int land = 0, water = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    land++;
                    q.push({i, j});
                } else {
                    water++;
                }
            }
        }

        if(land == 0 || water == 0) return -1; // No land or water exist

        int distance = 0;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto top = q.front();
                q.pop();
                int i = top.first, j = top.second;
                for(auto dir: dirs) {
                    int x = dir[0] + i, y = dir[1] + j;
                    if(x >=0 && x < n && y >= 0 && y < n) {
                        if(grid[x][y] == 0) {
                            grid[x][y] = -1; // Mark visited
                            q.push({x, y});
                        }
                    }
                }
            }
            distance++;
        }
        
        return distance-1;
    }
};