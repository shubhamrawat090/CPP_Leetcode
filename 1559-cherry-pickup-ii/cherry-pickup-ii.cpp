class Solution {
    int recursive(int i, int j1, int j2, vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        // Out of bounds
        if (j1 < 0 || j2 < 0 || j1 >= cols || j2 >= cols)
            return -1e9;

        // Last row
        if (i == rows - 1) {
            if (j1 == j2) {
                return grid[i][j1];
            } else {
                return grid[i][j1] + grid[i][j2];
            }
        }

        // Cherries from current row
        int cherries = 0;
        if (j1 == j2) {
            cherries = grid[i][j1];
        } else {
            cherries = grid[i][j1] + grid[i][j2];
        }

        int ni = i + 1;
        int maxValue = INT_MIN;

        for (int dj1 = -1; dj1 <= 1; dj1++) {
            int nj1 = j1 + dj1;

            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int nj2 = j2 + dj2;

                int value = -1e9;

                if (nj1 >= 0 && nj1 < cols && nj2 >= 0 && nj2 < cols) {
                    value = cherries + recursive(ni, nj1, nj2, grid);
                }

                maxValue = max(maxValue, value);
            }
        }

        return maxValue;
    }

    int memoized(int i, int j1, int j2, vector<vector<int>>& grid,
                 vector<vector<vector<int>>>& dp) {
        int rows = grid.size(), cols = grid[0].size();
        // Very small number so that when I add it up I get even smaller sum.
        // ANSWER REQUIRED MAX VALUE
        if (j1 < 0 || j2 < 0 || j1 >= cols || j2 >= cols)
            return -1e9;
        if (i == rows - 1) { // last row
            if (j1 == j2) {
                // Same cell
                return grid[i][j1]; // count ones
            } else {
                // different cell
                return grid[i][j1] + grid[i][j2];
            }
        }

        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        // Allowed directions
        // bottom left(i+1, j-1), bottom(i+1, j), bottom right(i+1, j+1) ==> (3
        // ways) for j1 = bottom left => j2 can be any one of: bottom left,
        // bottom, bottom right Total: 3 * 3 = 9 combinations Note: i ==> i+1,
        // ALWAYS. And j varies from -1, 0, +1

        // Calculate cherries to take from current for the next one
        // Both j's are within columns
        int cherries = 0;
        if (j1 == j2) {             // same element
            cherries = grid[i][j1]; // Take any 1
        } else {
            cherries = grid[i][j1] + grid[i][j2];
        }

        int ni = i + 1;
        int maxValue = INT_MIN;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            int nj1 = j1 + dj1;
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int nj2 = j2 + dj2;
                int value = -1e9;
                if (nj1 >= 0 && nj1 < cols && nj2 >= 0 && nj2 < cols) {
                    value = cherries + memoized(ni, nj1, nj2, grid, dp);
                }
                maxValue = max(maxValue, value);
            }
        }
        return dp[i][j1][j2] = maxValue;
    }

    int tabulate(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> dp(
            rows, vector<vector<int>>(cols, vector<int>(cols, 0)));

        for (int j1 = 0; j1 < cols; j1++) {
            for (int j2 = 0; j2 < cols; j2++) {
                if (j1 == j2) {
                    // Same cell
                    dp[rows-1][j1][j2] = grid[rows - 1][j1]; // count ones
                } else {
                    // different cell
                    dp[rows-1][j1][j2] = grid[rows - 1][j1] + grid[rows - 1][j2];
                }
            }
        }

        for (int i = rows - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < cols; j1++) {
                for (int j2 = 0; j2 < cols; j2++) {
                    int cherries = 0;
                    if (j1 == j2) {             // same element
                        cherries = grid[i][j1]; // Take any 1
                    } else {
                        cherries = grid[i][j1] + grid[i][j2];
                    }

                    int ni = i + 1;
                    int maxValue = INT_MIN;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        int nj1 = j1 + dj1;
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int nj2 = j2 + dj2;
                            int value = -1e9;
                            if (nj1 >= 0 && nj1 < cols && nj2 >= 0 &&
                                nj2 < cols) {
                                value = cherries + dp[ni][nj1][nj2];
                            }
                            maxValue = max(maxValue, value);
                        }
                    }
                    dp[i][j1][j2] = maxValue;
                }
            }
        }

        // Because:
        // Robot1 starts at (0, 0)
        // Robot2 starts at (0, cols-1)
        return dp[0][0][cols-1];
    }

    int spaceOptmized(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        vector<vector<int>> bottom(cols, vector<int>(cols, 0));

        for (int j1 = 0; j1 < cols; j1++) {
            for (int j2 = 0; j2 < cols; j2++) {
                if (j1 == j2) {
                    // Same cell
                    bottom[j1][j2] = grid[rows - 1][j1]; // count ones
                } else {
                    // different cell
                    bottom[j1][j2] = grid[rows - 1][j1] + grid[rows - 1][j2];
                }
            }
        }

        for (int i = rows - 2; i >= 0; i--) {
            vector<vector<int>> curr(cols, vector<int>(cols, 0));
            
            for (int j1 = 0; j1 < cols; j1++) {
                for (int j2 = 0; j2 < cols; j2++) {
                    int cherries = 0;
                    if (j1 == j2) {             // same element
                        cherries = grid[i][j1]; // Take any 1
                    } else {
                        cherries = grid[i][j1] + grid[i][j2];
                    }

                    int maxValue = INT_MIN;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        int nj1 = j1 + dj1;
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int nj2 = j2 + dj2;
                            int value = -1e9;
                            if (nj1 >= 0 && nj1 < cols && nj2 >= 0 &&
                                nj2 < cols) {
                                value = cherries + bottom[nj1][nj2];
                            }
                            maxValue = max(maxValue, value);
                        }
                    }
                    curr[j1][j2] = maxValue;
                }
            }

            bottom = curr;
        }

        // Because:
        // Robot1 starts at (0, 0)
        // Robot2 starts at (0, cols-1)
        return bottom[0][cols-1];
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        // int rows = grid.size(), cols = grid[0].size();
        // return recursive(0, 0, cols - 1, grid);
        // vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols,
        // vector<int>(cols, -1))); return memoized(0, 0, cols - 1, grid, dp);
        // return tabulate(grid);
        return spaceOptmized(grid);
    }
};