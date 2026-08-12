class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        int islands = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        int rows = grid.size(), cols = grid[0].size();

        grid[i][j] = '2';

        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(auto dir: dirs) {
            int x = dir[0] + i;
            int y = dir[1] + j;

            if(x < 0 || y < 0 || x == rows || y == cols || grid[x][y] != '1') continue;

            dfs(grid, x, y);
        }
    }
};