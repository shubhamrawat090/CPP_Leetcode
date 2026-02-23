class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j); // mark current island as visited
                    ans++;           // count connected component
                }
            }
        }
        return ans;
    }

private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        // out of bounds or already visited
        if (r < 0 || r >= grid.size() || 
            c < 0 || c >= grid[0].size() || 
            grid[r][c] == '0') {
            return;
        }

        // mark visited
        grid[r][c] = '0';

        // explore 4 directions
        dfs(grid, r + 1, c); // down
        dfs(grid, r - 1, c); // up
        dfs(grid, r, c + 1); // right
        dfs(grid, r, c - 1); // left
    }
};