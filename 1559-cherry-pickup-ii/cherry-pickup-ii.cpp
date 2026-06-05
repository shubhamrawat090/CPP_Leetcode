class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // int rows = grid.size(), cols = grid[0].size();
        // return recursive(grid, 0, 0, cols-1);
        // vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols,
        // vector<int>(cols, -1))); return memoized(grid, 0, 0, cols-1, dp);
        // return tabulate(grid);
        return spaceOptimized(grid);
    }

    int spaceOptimized(vector<vector<int>>& grid) {
        // DEPENDS ON CURR AND NEXT ROW
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> currRow(
            vector<vector<int>>(cols, vector<int>(cols)));
        vector<vector<int>> nextRow(
            vector<vector<int>>(cols, vector<int>(cols)));

        // Base case last row
        for (int c1 = 0; c1 < cols; c1++) {
            for (int c2 = 0; c2 < cols; c2++) {
                if (c1 == c2)
                    nextRow[c1][c2] = grid[rows - 1][c1];
                else
                    nextRow[c1][c2] = grid[rows - 1][c1] + grid[rows - 1][c2];
            }
        }

        for (int r = rows - 2; r >= 0; r--) {
            for (int c1 = cols - 1; c1 >= 0; c1--) {
                for (int c2 = 0; c2 < cols; c2++) {
                    int nr = r + 1;
                    vector<int> dirs = {-1, 0, 1};
                    int maxVal = -1e9;
                    for (int i = 0; i < 3; i++) {
                        int nc1 = c1 + dirs[i];
                        for (int j = 0; j < 3; j++) {
                            int nc2 = c2 + dirs[j];
                            if (nr < 0 || nr == rows || nc1 < 0 ||
                                nc1 == cols || nc2 < 0 || nc2 == cols)
                                continue;
                            maxVal = max(maxVal, nextRow[nc1][nc2]);
                        }
                    }

                    int currCellVal =
                        (c1 == c2) ? grid[r][c1] : (grid[r][c1] + grid[r][c2]);
                    currRow[c1][c2] = currCellVal + maxVal;
                }
            }
            nextRow = currRow;
        }

        return currRow[0][cols - 1];
    }

    int tabulate(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> dp(
            rows, vector<vector<int>>(cols, vector<int>(cols)));

        // Base case last row
        for (int c1 = 0; c1 < cols; c1++) {
            for (int c2 = 0; c2 < cols; c2++) {
                if (c1 == c2)
                    dp[rows - 1][c1][c2] = grid[rows - 1][c1];
                else
                    dp[rows - 1][c1][c2] =
                        grid[rows - 1][c1] + grid[rows - 1][c2];
            }
        }

        for (int r = rows - 2; r >= 0; r--) {
            for (int c1 = cols - 1; c1 >= 0; c1--) {
                for (int c2 = 0; c2 < cols; c2++) {
                    int nr = r + 1;
                    vector<int> dirs = {-1, 0, 1};
                    int maxVal = -1e9;
                    for (int i = 0; i < 3; i++) {
                        int nc1 = c1 + dirs[i];
                        for (int j = 0; j < 3; j++) {
                            int nc2 = c2 + dirs[j];
                            if (nr < 0 || nr == rows || nc1 < 0 ||
                                nc1 == cols || nc2 < 0 || nc2 == cols)
                                continue;
                            maxVal = max(maxVal, dp[nr][nc1][nc2]);
                        }
                    }

                    int currCellVal =
                        (c1 == c2) ? grid[r][c1] : (grid[r][c1] + grid[r][c2]);
                    dp[r][c1][c2] = currCellVal + maxVal;
                }
            }
        }

        return dp[0][0][cols - 1];
    }

    int memoized(vector<vector<int>>& grid, int r, int c1, int c2,
                 vector<vector<vector<int>>>& dp) {
        int rows = grid.size(), cols = grid[0].size();
        if (r < 0 || c1 < 0 || c2 < 0 || r == rows || c1 == cols ||
            c2 == cols) {
            // Out of bounds
            return -1e9; // Some invalid value
        }
        if (r == rows - 1) {
            // Last rows
            // Same cell -> count once
            if (c1 == c2)
                return grid[r][c1];
            // Different cell -> count both
            return grid[r][c1] + grid[r][c2];
        }

        if (dp[r][c1][c2] != -1)
            return dp[r][c1][c2];

        int nr = r + 1;
        vector<int> dirs = {-1, 0, 1};
        int maxVal = -1e9;
        for (int i = 0; i < 3; i++) {
            int nc1 = c1 + dirs[i];
            for (int j = 0; j < 3; j++) {
                int nc2 = c2 + dirs[j];
                maxVal = max(maxVal, memoized(grid, nr, nc1, nc2, dp));
            }
        }

        int currCellVal =
            (c1 == c2) ? grid[r][c1] : (grid[r][c1] + grid[r][c2]);
        return dp[r][c1][c2] = currCellVal + maxVal;
    }

    int recursive(vector<vector<int>>& grid, int r, int c1, int c2) {
        int rows = grid.size(), cols = grid[0].size();
        if (r < 0 || c1 < 0 || c2 < 0 || r == rows || c1 == cols ||
            c2 == cols) {
            // Out of bounds
            return -1e9; // Some invalid value
        }
        if (r == rows - 1) {
            // Last rows
            // Same cell -> count once
            if (c1 == c2)
                return grid[r][c1];
            // Different cell -> count both
            return grid[r][c1] + grid[r][c2];
        }

        int nr = r + 1;
        vector<int> dirs = {-1, 0, 1};
        int maxVal = -1e9;
        for (int i = 0; i < 3; i++) {
            int nc1 = c1 + dirs[i];
            for (int j = 0; j < 3; j++) {
                int nc2 = c2 + dirs[j];
                maxVal = max(maxVal, recursive(grid, nr, nc1, nc2));
            }
        }

        int currCellVal =
            (c1 == c2) ? grid[r][c1] : (grid[r][c1] + grid[r][c2]);
        return currCellVal + maxVal;
    }
};