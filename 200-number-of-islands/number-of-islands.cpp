class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        int islands = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    dfs(grid, visited, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j) {
        int rows = grid.size(), cols = grid[0].size();

        visited[i][j] = 1;

        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(auto dir: dirs) {
            int x = dir[0] + i;
            int y = dir[1] + j;

            if(x < 0 || y < 0 || x == rows || y == cols || visited[x][y] == 1 || grid[x][y] == '0') continue;

            dfs(grid, visited, x, y);
        }
    }
};