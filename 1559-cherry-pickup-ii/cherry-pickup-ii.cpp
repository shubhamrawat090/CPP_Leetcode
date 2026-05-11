class Solution {
    int recursive(int i, int j1, int j2, vector<vector<int>>& grid) {
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

        // Allowed directions
        // bottom left(i+1, j-1), bottom(i+1, j), bottom right(i+1, j+1) ==> (3
        // ways) for j1 = bottom left => j2 can be any one of: bottom left,
        // bottom, bottom right Total: 3 * 3 = 9 combinations Note: i ==> i+1,
        // ALWAYS. And j varies from -1, 0, +1
        int ni = i + 1;
        int maxValue = INT_MIN;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            int nj1 = j1 + dj1;
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int nj2 = j2 + dj2;
                int value = 0;
                if (nj1 >= 0 && nj1 < cols && nj2 >= 0 && nj2 < cols) {
                    // Both j's are within columns
                    if (nj1 == nj2) {          // same element
                        value = grid[ni][nj1]; // Take any 1
                    } else {
                        value = grid[ni][nj1] + grid[ni][nj2];
                    }

                    value += recursive(ni, nj1, nj2, grid);
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

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        // return recursive(0, 0, cols - 1, grid);
        vector<vector<vector<int>>> dp(
            rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        return memoized(0, 0, cols - 1, grid, dp);
    }
};