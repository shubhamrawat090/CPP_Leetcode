class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j] == 1) {
                    fresh++;
                } else if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        if(fresh == 0) return 0;

        int time = 0;
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(q.size() > 0) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                auto temp = q.front();
                q.pop();
                for(auto dir: dirs) {
                    int x = temp.first + dir[0];
                    int y = temp.second + dir[1];
                    if(x >= 0 && y >= 0 && x < r && y < c && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        fresh--;
                        q.push({x, y});
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time - 1 : -1;
    }
};