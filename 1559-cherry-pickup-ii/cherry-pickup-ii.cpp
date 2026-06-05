class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        // return recursive(grid, 0, 0, cols-1);
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        return memoized(grid, 0, 0, cols-1, dp);
    }

    int memoized(vector<vector<int>>& grid, int r, int c1, int c2, vector<vector<vector<int>>>& dp) {
        int rows = grid.size(), cols = grid[0].size();
        if(r < 0 || c1 < 0 || c2 < 0 || r == rows || c1 == cols || c2 == cols) {
            // Out of bounds
            return -1e9; // Some invalid value
        }
        if(r == rows-1) {
            // Last rows
            // Same cell -> count once
            if(c1 == c2) return grid[r][c1];
            // Different cell -> count both
            return grid[r][c1] + grid[r][c2];
        }

        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];

        int nr = r + 1;
        vector<int> dirs = {-1, 0, 1};
        int maxVal = -1e9;
        for(int i=0; i<3; i++) {
            int nc1 = c1 + dirs[i];
            for(int j=0; j<3; j++) {
                int nc2 = c2 + dirs[j];
                maxVal = max(maxVal, memoized(grid, nr, nc1, nc2, dp));
            }
        }

        int currCellVal = (c1 == c2) ? grid[r][c1] : (grid[r][c1] + grid[r][c2]);
        return dp[r][c1][c2] = currCellVal + maxVal; 
    }

    int recursive(vector<vector<int>>& grid, int r, int c1, int c2) {
        int rows = grid.size(), cols = grid[0].size();
        if(r < 0 || c1 < 0 || c2 < 0 || r == rows || c1 == cols || c2 == cols) {
            // Out of bounds
            return -1e9; // Some invalid value
        }
        if(r == rows-1) {
            // Last rows
            // Same cell -> count once
            if(c1 == c2) return grid[r][c1];
            // Different cell -> count both
            return grid[r][c1] + grid[r][c2];
        }

        int nr = r + 1;
        vector<int> dirs = {-1, 0, 1};
        int maxVal = -1e9;
        for(int i=0; i<3; i++) {
            int nc1 = c1 + dirs[i];
            for(int j=0; j<3; j++) {
                int nc2 = c2 + dirs[j];
                maxVal = max(maxVal, recursive(grid, nr, nc1, nc2));
            }
        }

        int currCellVal = (c1 == c2) ? grid[r][c1] : (grid[r][c1] + grid[r][c2]);
        return currCellVal + maxVal; 
    }
};